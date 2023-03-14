%skeleton "lalr1.cc" // -*- C++ -*-
%require "3.8.1"
%header

%define api.token.raw

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
  # include <string>
  #include <variant>
  class driver;
  class Node;
  class AST;
}

// The parsing context.
%param { driver& drv }

%locations

%define parse.trace
%define parse.error detailed
%define parse.lac full

%code {
  #include "driver.hh"
  #include "memory"
  #include "ast.hh"
  #include "node.hh"
  std::unique_ptr<AST> ast;
}

%define api.token.prefix {TOK_}


%token <int> INT "int"
%token <float> FLOAT "float"
%token <std::string> ID TYPE RELOP
%token SEMI COMMA ASSIGNOP PLUS MINUS STAR DIV AND OR DOT NOT LP RP LB RB LC RC
%token STRUCT RETURN IF ELSE WHILE

%printer { yyo << $$; } <*>;


%type <Node*> Program ExtDefList ExtDef ExtDecList Specifier StructSpecifier
%type <Node*> OptTag Tag VarDec FunDec VarList ParamDec CompSt
%type <Node*> StmtList Stmt DefList Def DecList Dec Exp Args

%nonassoc error
%right ASSIGNOP
%left OR
%left AND
%left RELOP
%left PLUS MINUS
%left STAR DIV
%right NOT
%left LP RP LB RB DOT
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%%



%start Program;
Program : ExtDefList{
    Node* new_node = new Node(@1.begin.line,"Program",Node::non_end,1);
    ast = std::make_unique<AST>(new_node);
    $$ = new_node;
    add_child($$,$1,1);
};
ExtDefList : ExtDef ExtDefList{
    struct Node* new_node = new Node(@1.begin.line,"ExtDefList",Node::non_end,1);
    $$ = new_node;
    add_child($$,$1,1);
    add_child($$,$2,2);
}
    | /*empty*/{
        $$ = NULL;
    }
    ;
ExtDef : Specifier ExtDecList SEMI{
    struct Node* new_node = new Node(@1.begin.line,"ExtDef",Node::non_end,1);
    struct Node* SEMI_node = new Node(@3.begin.line,"SEMI",Node::end);
    $$ = new_node;
    add_child($$,$1,1);
    add_child($$,$2,2);
    add_child($$,SEMI_node,3);
}
    | Specifier SEMI {
        struct Node* new_node = new Node(@1.begin.line,"ExtDef",Node::non_end,2);
        struct Node* SEMI_node = new Node(@2.begin.line,"SEMI",Node::end);
        $$ = new_node;
        add_child($$,$1,1);
        add_child($$,SEMI_node,2);
    }
    | Specifier FunDec CompSt {
        struct Node* new_node = new Node(@1.begin.line,"ExtDef",Node::non_end,3);
        $$ = new_node;
        add_child($$,$1,1);
        add_child($$,$2,2);
        add_child($$,$3,3);
    }
    | Specifier error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "delcaration error");}
    ;
ExtDecList : VarDec {
    struct Node* new_node = new Node(@1.begin.line,"ExtDecList",Node::non_end,1);
    $$ = new_node;
    add_child($$,$1,1);
}
    | VarDec COMMA ExtDecList {
        struct Node* new_node = new Node(@1.begin.line,"ExtDecList",Node::non_end,2);
        struct Node* COMMA_node = new Node(@2.begin.line,"COMMA",Node::end);
        $$ = new_node;
        add_child($$,$1,1);
        add_child($$,COMMA_node,2);
        add_child($$,$3,3);
    }
    | VarDec COMMA error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "delcaration error");}
    ;
Specifier : TYPE {
    struct Node* new_node = new Node(@1.begin.line,"Specifier",Node::non_end,1);
    struct Node* TYPE_node = new Node(@1.begin.line,"TYPE",Node::string_node);
    TYPE_node->m_value = $1;
    $$ = new_node;
    add_child($$,TYPE_node,1);
}
    | StructSpecifier {
        struct Node* new_node = new Node(@1.begin.line,"Specifier",Node::non_end,2);
        $$ = new_node;
        add_child($$,$1,1);
    }
    ;
StructSpecifier : STRUCT OptTag LC DefList RC {
    struct Node* new_node = new Node(@1.begin.line,"StructSpecifier",Node::non_end,1);
    $$ = new_node;
    struct Node* STRUCT_node = new Node(@1.begin.line,"STRUCT",Node::end);
    struct Node* LC_node = new Node(@3.begin.line,"LC",Node::end);
    struct Node* RC_node = new Node(@5.begin.line,"RC",Node::end);
    add_child($$,STRUCT_node,1);
    add_child($$,$2,2);
    add_child($$,LC_node,3);
    add_child($$,$4,4);
    add_child($$,RC_node,5);
}
    | STRUCT Tag {
        struct Node* new_node = new Node(@1.begin.line,"StructSpecifier",Node::non_end,2);
        $$ = new_node;
        struct Node* STRUCT_node = new Node(@1.begin.line,"STRUCT",Node::end);
        add_child($$,STRUCT_node,1);
        add_child($$,$2,2);
    }
    | STRUCT OptTag LC error RC{fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "struct error");}
    ;
OptTag : ID{
    struct Node* new_node = new Node(@1.begin.line,"OptTag",Node::non_end,1);
    $$ = new_node;
    struct Node* ID_node = new Node(@1.begin.line,"ID",Node::string_node);
    ID_node->m_value = $1;
    add_child($$,ID_node,1);
}
    | /*empty*/{
        $$ = NULL;
    }
    ;
Tag : ID{
    struct Node* new_node = new Node(@1.begin.line,"Tag",Node::non_end,1);
    $$ = new_node;
    struct Node* ID_node = new Node(@1.begin.line,"ID",Node::string_node);
    ID_node->m_value = $1;
    add_child($$,ID_node,1);
}
    ;
/*declaraitons*/
VarDec : ID {
    struct Node* new_node = new Node(@1.begin.line,"VarDec",Node::non_end,1);
    $$ = new_node;
    struct Node* ID_node = new Node(@1.begin.line,"ID",Node::string_node);
    ID_node->m_value = $1;
    add_child($$,ID_node,1);
}
    | VarDec LB INT RB {
        struct Node* new_node = new Node(@1.begin.line,"VarDec",Node::non_end,2);
        $$ = new_node;
        struct Node* LB_node = new Node(@2.begin.line,"LB",Node::end);
        struct Node* int_node = new Node(@3.begin.line,"INT",Node::int_node);
        int_node->m_value = $3;
        struct Node* RB_node = new Node(@4.begin.line,"RB",Node::end);
        add_child($$,$1,1);
        add_child($$, LB_node,2);
        add_child($$,int_node,3);
        add_child($$,RB_node,4);
    }
    | VarDec LB error RB {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "wrong variable declaration");}
    ;
FunDec : ID LP VarList RP {
    struct Node* new_node = new Node(@1.begin.line,"FunDec",Node::non_end,1);
    $$ = new_node;
    struct Node* ID_node = new Node(@1.begin.line,"ID",Node::string_node);
    ID_node->m_value = $1;
    struct Node* LP_node = new Node(@2.begin.line,"LP",Node::end);
    struct Node* RP_node = new Node(@4.begin.line,"RP",Node::end);
    add_child($$,ID_node,1);
    add_child($$, LP_node,2);
    add_child($$,$3,3);
    add_child($$,RP_node,4);
}
    | ID LP RP {
        struct Node* new_node = new Node(@1.begin.line,"FunDec",Node::non_end,2);
        $$ = new_node;
        struct Node* ID_node = new Node(@1.begin.line,"ID",Node::string_node);
        ID_node->m_value = $1;
        struct Node* LP_node = new Node(@2.begin.line,"LP",Node::end);
        struct Node* RP_node = new Node(@3.begin.line,"RP",Node::end);
        add_child($$,ID_node,1);
        add_child($$, LP_node,2);
        add_child($$,RP_node,3);
    }
    ;
VarList : ParamDec COMMA VarList {
    struct Node* new_node = new Node(@1.begin.line,"VarList",Node::non_end,1);
    $$ = new_node;
    struct Node* COMMA_node = new Node(@2.begin.line,"COMMA",Node::end);
    add_child($$,$1,1);
    add_child($$, COMMA_node,2);
    add_child($$,$3,3);
}
    | ParamDec {
        struct Node* new_node = new Node(@1.begin.line,"VarList",Node::non_end,2);
        $$ = new_node;
        add_child($$,$1,1);
    }
    ;
ParamDec : Specifier VarDec {
    struct Node* new_node = new Node(@1.begin.line,"ParamDec",Node::non_end,1);
    $$ = new_node;
    add_child($$,$1,1);
    add_child($$,$2,2);
}
    ;
/*statements*/
CompSt : LC DefList StmtList RC {
    struct Node* new_node = new Node(@1.begin.line,"CompSt",Node::non_end,1);
    $$ = new_node;
    struct Node* LC_node = new Node(@1.begin.line,"LC",Node::end);
    struct Node* RC_node = new Node(@4.begin.line,"RC",Node::end);
    add_child($$,LC_node,1);
    add_child($$, $2,2);
    add_child($$,$3,3);
    add_child($$,RC_node,4);
}
    | error DefList StmtList RC {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Missing {");}
    ;
StmtList : Stmt StmtList {
    struct Node* new_node = new Node(@1.begin.line,"StmtList",Node::non_end,1);
    $$ = new_node;
    add_child($$, $1,1);
    add_child($$,$2,2);
}
    | /*empty*/ {
        $$ = NULL;
    }
    ;
Stmt : Exp SEMI{
    struct Node* new_node = new Node(@1.begin.line,"Stmt",Node::non_end,1);
    struct Node* SEMI_node = new Node(@2.begin.line,"SEMI",Node::end);
    $$ = new_node;
    add_child($$, $1,1);
    add_child($$,SEMI_node,2);
}
    | error SEMI {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "wrong expression");}
    | Exp error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Missing ;");}
    | CompSt{
        struct Node* new_node = new Node(@1.begin.line,"Stmt",Node::non_end,2);
        $$ = new_node;
        add_child($$, $1,1);
    }
    | RETURN Exp SEMI {
        struct Node* new_node = new Node(@1.begin.line,"Stmt",Node::non_end,3);
        struct Node* RETURN_node = new Node(@1.begin.line,"RETURN",Node::end);
        struct Node* SEMI_node = new Node(@3.begin.line,"SEMI",Node::end);
        $$ = new_node;
        
        add_child($$,RETURN_node,1);
        add_child($$, $2,2);
        add_child($$,SEMI_node,3);
    }
    | RETURN Exp error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Missing ;");}
    | RETURN error SEMI {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Wrong return expression");}
    | IF LP Exp RP Stmt {
        struct Node* new_node = new Node(@1.begin.line,"Stmt",Node::non_end,4);
        struct Node* IF_node = new Node(@1.begin.line,"IF",Node::end);
        struct Node* LP_node = new Node(@2.begin.line,"LP",Node::end);
        struct Node* RP_node = new Node(@4.begin.line,"RP",Node::end);
        $$ = new_node;
        
        add_child($$,IF_node,1);
        add_child($$, LP_node,2);
        add_child($$,$3,3);
        add_child($$,RP_node,4);
        add_child($$,$5,5);
    }
    | IF LP Exp RP Stmt ELSE Stmt {
        struct Node* new_node = new Node(@1.begin.line,"Stmt",Node::non_end,5);
        struct Node* IF_node = new Node(@1.begin.line,"IF",Node::end);
        struct Node* LP_node = new Node(@2.begin.line,"LP",Node::end);
        struct Node* RP_node = new Node(@4.begin.line,"RP",Node::end);
        struct Node* ELSE_node = new Node(@6.begin.line,"ELSE",Node::end);
        $$ = new_node;
        
        add_child($$,IF_node,1);
        add_child($$, LP_node,2);
        add_child($$,$3,3);
        add_child($$,RP_node,4);
        add_child($$,$5,5);
        add_child($$,ELSE_node,6);
        add_child($$,$7,7);
    }
    | WHILE LP Exp RP Stmt {
        struct Node* new_node = new Node(@1.begin.line,"Stmt",Node::non_end,6);
        struct Node* WHILE_node = new Node(@1.begin.line,"WHILE",Node::end);
        struct Node* LP_node = new Node(@2.begin.line,"LP",Node::end);
        struct Node* RP_node = new Node(@4.begin.line,"RP",Node::end);
        $$ = new_node;
        
        add_child($$,WHILE_node,1);
        add_child($$, LP_node,2);
        add_child($$,$3,3);
        add_child($$,RP_node,4);
        add_child($$,$5,5);
    }
    
    ;
DefList : Def DefList {
    struct Node* new_node = new Node(@1.begin.line,"DefList",Node::non_end,1);
    $$ = new_node;
    
    add_child($$,$1,1);
    add_child($$, $2,2);
}
    | /*empty*/{
        $$ = NULL;
    }
    ;
Def : Specifier DecList SEMI {
    struct Node* new_node = new Node(@1.begin.line,"Def",Node::non_end,1);
    struct Node* SEMI_node = new Node(@3.begin.line,"SEMI",Node::end);
    $$ = new_node;
    
    add_child($$,$1,1);
    add_child($$, $2,2);
    add_child($$, SEMI_node,2);
}
    | error DecList SEMI {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Wrong declaration");}
    | Specifier error SEMI {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Wrong declaration");}
    ;
DecList : Dec {
    struct Node* new_node = new Node(@1.begin.line,"DecList",Node::non_end,1);
    $$ = new_node;
    
    add_child($$,$1,1);
}
    | Dec COMMA DecList {
        struct Node* new_node = new Node(@1.begin.line,"DecList",Node::non_end);
        struct Node* COMMA_node = new Node(@2.begin.line,"COMMA",Node::end);
        $$ = new_node;
        
        add_child($$,$1,1);
        add_child($$, COMMA_node,2);
        add_child($$, $3,3);
    }
    ;
Dec : VarDec {
    struct Node* new_node = new Node(@1.begin.line,"Dec",Node::non_end,1);
    $$ = new_node;
    
    add_child($$,$1,1);
}
    | VarDec ASSIGNOP Exp {
        struct Node* new_node = new Node(@1.begin.line,"Dec",Node::non_end,2);
        struct Node* ASSIGNOP_node = new Node(@2.begin.line,"ASSIGNOP",Node::end);
        $$ = new_node;
        
        add_child($$,$1,1);
        add_child($$, ASSIGNOP_node,2);
        add_child($$, $3,3);
    }
    | VarDec ASSIGNOP error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Wrong expression");}
    ;

Exp : Exp ASSIGNOP Exp{
    struct Node* new_node = new Node(@1.begin.line,"Exp",Node::non_end,1);
    struct Node* ASSIGNOP_node = new Node(@2.begin.line,"ASSIGNOP",Node::end);
    $$ = new_node;
    
    add_child($$,$1,1);
    add_child($$, ASSIGNOP_node,2);
    add_child($$, $3,3);
}
    | Exp ASSIGNOP error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Wrong expression");}
    | Exp AND Exp {
        struct Node* new_node = new Node(@1.begin.line,"Exp",Node::non_end,2);
        struct Node* AND_node = new Node(@2.begin.line,"AND",Node::end);
        $$ = new_node;
        
        add_child($$,$1,1);
        add_child($$, AND_node,2);
        add_child($$, $3,3);
    }
    | Exp AND error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Wrong expression");}
    | Exp OR Exp {
        struct Node* new_node = new Node(@1.begin.line,"Exp",Node::non_end,3);
        struct Node* OR_node = new Node(@2.begin.line,"OR",Node::end);
        $$ = new_node;
        
        add_child($$,$1,1);
        add_child($$, OR_node,2);
        add_child($$, $3,3);
    }
    | Exp OR error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Wrong expression");}
    | Exp RELOP Exp {
        struct Node* new_node = new Node(@1.begin.line,"Exp",Node::non_end,4);
        struct Node* RELOP_node = new Node(@2.begin.line,"RELOP",Node::end);
        RELOP_node->m_value = $2;
        $$ = new_node;
        
        add_child($$,$1,1);
        add_child($$, RELOP_node,2);
        add_child($$, $3,3);
    }
    | Exp RELOP error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Wrong expression");}
    | Exp PLUS Exp {
        struct Node* new_node = new Node(@1.begin.line,"Exp",Node::non_end,5);
        struct Node* PLUS_node = new Node(@2.begin.line,"PLUS",Node::end);
        $$ = new_node;
        
        add_child($$,$1,1);
        add_child($$, PLUS_node,2);
        add_child($$, $3,3);
    }
    | Exp PLUS error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Wrong expression");}
    | Exp MINUS Exp {
        struct Node* new_node = new Node(@1.begin.line,"Exp",Node::non_end,6);
        struct Node* MINUS_node = new Node(@2.begin.line,"MINUS",Node::end);
        $$ = new_node;
        
        add_child($$,$1,1);
        add_child($$, MINUS_node,2);
        add_child($$, $3,3);
    }
    | Exp MINUS error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Wrong expression");}
    | Exp STAR Exp {
        struct Node* new_node = new Node(@1.begin.line,"Exp",Node::non_end,7);
        struct Node* STAR_node = new Node(@2.begin.line,"STAR",Node::end);
        $$ = new_node;
        
        add_child($$,$1,1);
        add_child($$, STAR_node,2);
        add_child($$, $3,3);
    }
    | Exp STAR error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Wrong expression");}
    | Exp DIV Exp {
        struct Node* new_node = new Node(@1.begin.line,"Exp",Node::non_end,8);
        struct Node* DIV_node = new Node(@2.begin.line,"DIV",Node::end);
        $$ = new_node;
        
        add_child($$,$1,1);
        add_child($$, DIV_node,2);
        add_child($$, $3,3);
    }
    | Exp DIV error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Wrong expression");}
    | LP Exp RP {
        struct Node* new_node = new Node(@1.begin.line,"Exp",Node::non_end,9);
        struct Node* LP_node = new Node(@1.begin.line,"LP",Node::end);
        struct Node* RP_node = new Node(@3.begin.line,"RP",Node::end);
        $$ = new_node;
        
        add_child($$,LP_node,1);
        add_child($$, $2,2);
        add_child($$, RP_node,3);
    }
    | LP error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Missing )");}
    | MINUS Exp {
        struct Node* new_node = new Node(@1.begin.line,"Exp",Node::non_end,10);
        struct Node* MINUS_node = new Node(@1.begin.line,"MINUS",Node::end);
        $$ = new_node;
        
        add_child($$,MINUS_node,1);
        add_child($$, $2,2);
    }
    | MINUS error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Wrong expression");}
    | NOT Exp {
        struct Node* new_node = new Node(@1.begin.line,"Exp",Node::non_end,11);
        struct Node* NOT_node = new Node(@1.begin.line,"NOT",Node::end);
        $$ = new_node;
        
        add_child($$,NOT_node,1);
        add_child($$, $2,2);
    }
    | NOT error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Wrong expression");}
    | ID LP Args RP {
        struct Node* new_node = new Node(@1.begin.line,"Exp",Node::non_end,12);
        struct Node* ID_node = new Node(@1.begin.line,"ID",Node::string_node);
        ID_node->m_value = $1;
        struct Node* LP_node = new Node(@2.begin.line,"LP",Node::end);
        struct Node* RP_node = new Node(@4.begin.line,"RP",Node::end);
        $$ = new_node;
        
        add_child($$,ID_node,1);
        add_child($$,LP_node,2);
        add_child($$, $3,3);
        add_child($$,RP_node,4);
    }
    | ID LP Args error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Missing )");}
    | ID LP RP {
        struct Node* new_node = new Node(@1.begin.line,"Exp",Node::non_end,13);
        struct Node* ID_node = new Node(@1.begin.line,"ID",Node::string_node);
        ID_node->m_value = $1;
        struct Node* LP_node = new Node(@2.begin.line,"LP",Node::end);
        struct Node* RP_node = new Node(@3.begin.line,"RP",Node::end);
        $$ = new_node;
        
        add_child($$,ID_node,1);
        add_child($$,LP_node,2);
        add_child($$,RP_node,3);
    }
    | ID LP error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Missing )");}
    | Exp LB Exp RB {
        struct Node* new_node = new Node(@1.begin.line,"Exp",Node::non_end,14);
        struct Node* LB_node = new Node(@2.begin.line,"LB",Node::end);
        struct Node* RB_node = new Node(@4.begin.line,"RB",Node::end);
        $$ = new_node;
        
        add_child($$,$1,1);
        add_child($$,LB_node,2);
        add_child($$,$3,3);
        add_child($$,RB_node,4);
    }
    | Exp LB error RB {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Wrong expression");}
    | Exp DOT ID {
        struct Node* new_node = new Node(@1.begin.line,"Exp",Node::non_end,15);
        struct Node* DOT_node = new Node(@2.begin.line,"DOT",Node::end);
        struct Node* ID_node = new Node(@3.begin.line,"ID",Node::string_node);
        ID_node->m_value = $3;
        $$ = new_node;
        
        add_child($$,$1,1);
        add_child($$,DOT_node,2);
        add_child($$,ID_node,3);
    }
    | ID {
        struct Node* new_node = new Node(@1.begin.line,"Exp",Node::non_end,16);
        struct Node* ID_node = new Node(@1.begin.line,"ID",Node::string_node);
        ID_node->m_value = $1;
        $$ = new_node;
        
        add_child($$,ID_node,1);
    }
    | INT {
        struct Node* new_node = new Node(@1.begin.line,"Exp",Node::non_end,17);
        struct Node* int_node = new Node(@1.begin.line,"INT",Node::int_node);
        int_node->m_value = $1;
        $$ = new_node;
        
        add_child($$,int_node,1);
    }
    | FLOAT {
        struct Node* new_node = new Node(@1.begin.line,"Exp",Node::non_end,18);
        struct Node* float_node = new Node(@1.begin.line,"FLOAT",Node::float_node);
        float_node->m_value = $1;
        $$ = new_node;
        
        add_child($$,float_node,1);

    }
    | error RP {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Wrong expression");}
    ;
Args : Exp COMMA Args {
    struct Node* new_node = new Node(@1.begin.line,"Args",Node::non_end,1);
    struct Node* COMMA_node = new Node(@2.begin.line,"COMMA",Node::end);
    $$ = new_node;
    
    add_child($$,$1,1);
    add_child($$,COMMA_node,2);
    add_child($$,$3,3);
}
    | Exp {
        struct Node* new_node = new Node(@1.begin.line,"Args",Node::non_end,2);
        $$ = new_node;
        
        add_child($$,$1,1);
    }
    ;


%%

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
