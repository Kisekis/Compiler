%skeleton "lalr1.cc" // -*- C++ -*-
%require "3.8.1"
%header

%define api.token.raw

%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
  # include <string>
  class driver;
  struct Node;
}

// The parsing context.
%param { driver& drv }

%locations

%define parse.trace
%define parse.error detailed
%define parse.lac full

%code {
  #include "driver.hh"
  enum node_type {non_end,end,int_node,string_node,float_node};
  struct Node {
      union {
          int type_int;
          float type_float;
          std::string type_string;
      }m_value;
      enum node_type m_type;
      int m_line_num;
      std::string m_name;
      struct Node* m_next;
      struct Node* m_first_child;
      struct Node* m_last_child;
      struct Node* m_parent;
      int m_children_num;
      int m_layer;
  };
  struct Node* root = NULL;
  struct Node* construct_node(int line_num, std::string name, enum node_type type) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->m_line_num = line_num;
    new_node->m_name = name;
    new_node->m_next = NULL;
    new_node->m_first_child = NULL;
    new_node->m_last_child = NULL;
    new_node->m_children_num = 0;
    new_node->m_layer = 0;
    new_node->m_parent = NULL;
    new_node->m_type = type;
    return new_node;
}

  void add_child(struct Node* parent, struct Node* child) {
      if(child == NULL) return;
      if(parent->m_first_child == NULL) {
          parent->m_first_child = child;
          parent->m_last_child = child;
      }else {
          parent->m_last_child->m_next = child;
          parent->m_last_child = child;
      }
      parent->m_children_num++;
      // parent->layer = child->layer+1;
      child->m_parent = parent;
  }
  void print_tree(struct Node* node) {
      if(node == NULL) {
          return;
      }
      struct Node* cur = node;
      while(cur!=NULL) {
          if(cur!=root) {
              cur->m_layer = cur->m_parent->m_layer+1;
              for(int i = 0;i<cur->m_layer;i++) {
                  printf("  ");
              }
          }
          std::cout<<cur->m_name;
          switch(cur->m_type) {
              case non_end:
                  printf(" (%d)", cur->m_line_num);
                  break;
              case end:
                  break;
              case int_node:
                  printf(": %d", cur->m_value.type_int);
                  break;
              case float_node:
                  printf(": %f", cur->m_value.type_float);
                  break;
              case string_node:
                  printf(": %s", cur->m_value.type_string.c_str());
                  break;
          }
          printf(" \n");
          print_tree(cur->m_first_child);
          cur = cur->m_next;
      }
  }
  void delete_tree(struct Node* root) {
      if(root == NULL) {
          return;
      }
      struct Node* cur = root->m_first_child;
      while(cur!=NULL) {
          delete_tree(cur);
          cur = cur->m_next;
      }
      free(root);
  }
}

%define api.token.prefix {TOK_}


%token <int> INT "int"
%token <float> FLOAT "float"
%token <std::string> ID TYPE
%token SEMI COMMA ASSIGNOP RELOP PLUS MINUS STAR DIV AND OR DOT NOT LP RP LB RB LC RC
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
    struct Node* new_node = construct_node(@1.begin.line,"Program",non_end);
    root = new_node;
    $$ = new_node;
    add_child($$,$1);
};
ExtDefList : ExtDef ExtDefList{
    struct Node* new_node = construct_node(@1.begin.line,"ExtDefList",non_end);
    $$ = new_node;
    add_child($$,$1);
    add_child($$,$2);
}
    | /*empty*/{
        $$ = NULL;
    }
    ;
ExtDef : Specifier ExtDecList SEMI{
    struct Node* new_node = construct_node(@1.begin.line,"ExtDef",non_end);
    struct Node* SEMI_node = construct_node(@3.begin.line,"SEMI",end);
    $$ = new_node;
    add_child($$,$1);
    add_child($$,$2);
    add_child($$,SEMI_node);
}
    | Specifier SEMI {
        struct Node* new_node = construct_node(@1.begin.line,"ExtDef",non_end);
        struct Node* SEMI_node = construct_node(@2.begin.line,"SEMI",end);
        $$ = new_node;
        add_child($$,$1);
        add_child($$,SEMI_node);
    }
    | Specifier FunDec CompSt {
        struct Node* new_node = construct_node(@1.begin.line,"ExtDef",non_end);
        $$ = new_node;
        add_child($$,$1);
        add_child($$,$2);
        add_child($$,$3);
    }
    | Specifier error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "delcaration error");}
    ;
ExtDecList : VarDec {
    struct Node* new_node = construct_node(@1.begin.line,"ExtDecList",non_end);
    $$ = new_node;
    add_child($$,$1);
}
    | VarDec COMMA ExtDecList {
        struct Node* new_node = construct_node(@1.begin.line,"ExtDecList",non_end);
        struct Node* COMMA_node = construct_node(@2.begin.line,"COMMA",end);
        $$ = new_node;
        add_child($$,$1);
        add_child($$,COMMA_node);
        add_child($$,$3);
    }
    | VarDec COMMA error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "delcaration error");}
    ;
Specifier : TYPE {
    struct Node* new_node = construct_node(@1.begin.line,"Specifier",non_end);
    struct Node* TYPE_node = construct_node(@1.begin.line,"TYPE",string_node);
    TYPE_node->m_value.type_string = $1;
    $$ = new_node;
    add_child($$,TYPE_node);
}
    | StructSpecifier {
        struct Node* new_node = construct_node(@1.begin.line,"Specifier",non_end);
        $$ = new_node;
        add_child($$,$1);
    }
    ;
StructSpecifier : STRUCT OptTag LC DefList RC {
    struct Node* new_node = construct_node(@1.begin.line,"StructSpecifier",non_end);
    $$ = new_node;
    struct Node* STRUCT_node = construct_node(@1.begin.line,"STRUCT",end);
    struct Node* LC_node = construct_node(@3.begin.line,"LC",end);
    struct Node* RC_node = construct_node(@5.begin.line,"RC",end);
    add_child($$,STRUCT_node);
    add_child($$,$2);
    add_child($$,LC_node);
    add_child($$,$4);
    add_child($$,RC_node);
}
    | STRUCT Tag {
        struct Node* new_node = construct_node(@1.begin.line,"StructSpecifier",non_end);
        $$ = new_node;
        struct Node* STRUCT_node = construct_node(@1.begin.line,"STRUCT",end);
        add_child($$,STRUCT_node);
        add_child($$,$2);
    }
    | STRUCT OptTag LC error RC{fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "struct error");}
    ;
OptTag : ID{
    struct Node* new_node = construct_node(@1.begin.line,"OptTag",non_end);
    $$ = new_node;
    struct Node* ID_node = construct_node(@1.begin.line,"ID",string_node);
    ID_node->m_value.type_string = $1;
    add_child($$,ID_node);
}
    | /*empty*/{
        $$ = NULL;
    }
    ;
Tag : ID{
    struct Node* new_node = construct_node(@1.begin.line,"Tag",non_end);
    $$ = new_node;
    struct Node* ID_node = construct_node(@1.begin.line,"ID",string_node);
    ID_node->m_value.type_string = $1;
    add_child($$,ID_node);
}
    ;
/*declaraitons*/
VarDec : ID {
    struct Node* new_node = construct_node(@1.begin.line,"VarDec",non_end);
    $$ = new_node;
    struct Node* ID_node = construct_node(@1.begin.line,"ID",string_node);
    ID_node->m_value.type_string = $1;
    add_child($$,ID_node);
}
    | VarDec LB INT RB {
        struct Node* new_node = construct_node(@1.begin.line,"VarDec",non_end);
        $$ = new_node;
        struct Node* LB_node = construct_node(@2.begin.line,"LB",end);
        struct Node* INT_node = construct_node(@3.begin.line,"INT",int_node);
        INT_node->m_value.type_int = $3;
        struct Node* RB_node = construct_node(@4.begin.line,"RB",end);
        add_child($$,$1);
        add_child($$, LB_node);
        add_child($$,INT_node);
        add_child($$,RB_node);
    }
    | VarDec LB error RB {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "wrong variable declaration");}
    ;
FunDec : ID LP VarList RP {
    struct Node* new_node = construct_node(@1.begin.line,"FunDec",non_end);
    $$ = new_node;
    struct Node* ID_node = construct_node(@1.begin.line,"ID",string_node);
    ID_node->m_value.type_string = $1;
    struct Node* LP_node = construct_node(@2.begin.line,"LP",end);
    struct Node* RP_node = construct_node(@4.begin.line,"RP",end);
    add_child($$,ID_node);
    add_child($$, LP_node);
    add_child($$,$3);
    add_child($$,RP_node);
}
    | ID LP RP {
        struct Node* new_node = construct_node(@1.begin.line,"FunDec",non_end);
        $$ = new_node;
        struct Node* ID_node = construct_node(@1.begin.line,"ID",string_node);
        ID_node->m_value.type_string = $1;
        struct Node* LP_node = construct_node(@2.begin.line,"LP",end);
        struct Node* RP_node = construct_node(@3.begin.line,"RP",end);
        add_child($$,ID_node);
        add_child($$, LP_node);
        add_child($$,RP_node);
    }
    ;
VarList : ParamDec COMMA VarList {
    struct Node* new_node = construct_node(@1.begin.line,"VarList",non_end);
    $$ = new_node;
    struct Node* COMMA_node = construct_node(@2.begin.line,"COMMA",end);
    add_child($$,$1);
    add_child($$, COMMA_node);
    add_child($$,$3);
}
    | ParamDec {
        struct Node* new_node = construct_node(@1.begin.line,"VarList",non_end);
        $$ = new_node;
        add_child($$,$1);
    }
    ;
ParamDec : Specifier VarDec {
    struct Node* new_node = construct_node(@1.begin.line,"ParamDec",non_end);
    $$ = new_node;
    add_child($$,$1);
    add_child($$,$2);
}
    ;
/*statements*/
CompSt : LC DefList StmtList RC {
    struct Node* new_node = construct_node(@1.begin.line,"CompSt",non_end);
    $$ = new_node;
    struct Node* LC_node = construct_node(@1.begin.line,"LC",end);
    struct Node* RC_node = construct_node(@4.begin.line,"RC",end);
    add_child($$,LC_node);
    add_child($$, $2);
    add_child($$,$3);
    add_child($$,RC_node);
}
    | error DefList StmtList RC {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Missing {");}
    ;
StmtList : Stmt StmtList {
    struct Node* new_node = construct_node(@1.begin.line,"StmtList",non_end);
    $$ = new_node;
    add_child($$, $1);
    add_child($$,$2);
}
    | /*empty*/ {
        $$ = NULL;
    }
    ;
Stmt : Exp SEMI{
    struct Node* new_node = construct_node(@1.begin.line,"Stmt",non_end);
    struct Node* SEMI_node = construct_node(@2.begin.line,"SEMI",end);
    $$ = new_node;
    add_child($$, $1);
    add_child($$,SEMI_node);
}
    | error SEMI {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "wrong expression");}
    | Exp error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Missing ;");}
    | CompSt{
        struct Node* new_node = construct_node(@1.begin.line,"Stmt",non_end);
        $$ = new_node;
        add_child($$, $1);
    }
    | RETURN Exp SEMI {
        struct Node* new_node = construct_node(@1.begin.line,"Stmt",non_end);
        struct Node* RETURN_node = construct_node(@1.begin.line,"RETURN",end);
        struct Node* SEMI_node = construct_node(@3.begin.line,"SEMI",end);
        $$ = new_node;
        
        add_child($$,RETURN_node);
        add_child($$, $2);
        add_child($$,SEMI_node);
    }
    | RETURN Exp error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Missing ;");}
    | RETURN error SEMI {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Wrong return expression");}
    | IF LP Exp RP Stmt {
        struct Node* new_node = construct_node(@1.begin.line,"Stmt",non_end);
        struct Node* IF_node = construct_node(@1.begin.line,"IF",end);
        struct Node* LP_node = construct_node(@2.begin.line,"LP",end);
        struct Node* RP_node = construct_node(@4.begin.line,"RP",end);
        $$ = new_node;
        
        add_child($$,IF_node);
        add_child($$, LP_node);
        add_child($$,$3);
        add_child($$,RP_node);
        add_child($$,$5);
    }
    | IF LP Exp RP Stmt ELSE Stmt {
        struct Node* new_node = construct_node(@1.begin.line,"Stmt",non_end);
        struct Node* IF_node = construct_node(@1.begin.line,"IF",end);
        struct Node* LP_node = construct_node(@2.begin.line,"LP",end);
        struct Node* RP_node = construct_node(@4.begin.line,"RP",end);
        struct Node* ELSE_node = construct_node(@6.begin.line,"ELSE",end);
        $$ = new_node;
        
        add_child($$,IF_node);
        add_child($$, LP_node);
        add_child($$,$3);
        add_child($$,RP_node);
        add_child($$,$5);
        add_child($$,ELSE_node);
        add_child($$,$7);
    }
    | WHILE LP Exp RP Stmt {
        struct Node* new_node = construct_node(@1.begin.line,"Stmt",non_end);
        struct Node* WHILE_node = construct_node(@1.begin.line,"WHILE",end);
        struct Node* LP_node = construct_node(@2.begin.line,"LP",end);
        struct Node* RP_node = construct_node(@4.begin.line,"RP",end);
        $$ = new_node;
        
        add_child($$,WHILE_node);
        add_child($$, LP_node);
        add_child($$,$3);
        add_child($$,RP_node);
        add_child($$,$5);
    }
    
    ;
DefList : Def DefList {
    struct Node* new_node = construct_node(@1.begin.line,"DefList",non_end);
    $$ = new_node;
    
    add_child($$,$1);
    add_child($$, $2);
}
    | /*empty*/{
        $$ = NULL;
    }
    ;
Def : Specifier DecList SEMI {
    struct Node* new_node = construct_node(@1.begin.line,"Def",non_end);
    struct Node* SEMI_node = construct_node(@3.begin.line,"SEMI",end);
    $$ = new_node;
    
    add_child($$,$1);
    add_child($$, $2);
    add_child($$, SEMI_node);
}
    | error DecList SEMI {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Wrong declaration");}
    | Specifier error SEMI {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Wrong declaration");}
    ;
DecList : Dec {
    struct Node* new_node = construct_node(@1.begin.line,"DecList",non_end);
    $$ = new_node;
    
    add_child($$,$1);
}
    | Dec COMMA DecList {
        struct Node* new_node = construct_node(@1.begin.line,"DecList",non_end);
        struct Node* COMMA_node = construct_node(@2.begin.line,"COMMA",end);
        $$ = new_node;
        
        add_child($$,$1);
        add_child($$, COMMA_node);
        add_child($$, $3);
    }
    ;
Dec : VarDec {
    struct Node* new_node = construct_node(@1.begin.line,"Dec",non_end);
    $$ = new_node;
    
    add_child($$,$1);
}
    | VarDec ASSIGNOP Exp {
        struct Node* new_node = construct_node(@1.begin.line,"Dec",non_end);
        struct Node* ASSIGNOP_node = construct_node(@2.begin.line,"ASSIGNOP",end);
        $$ = new_node;
        
        add_child($$,$1);
        add_child($$, ASSIGNOP_node);
        add_child($$, $3);
    }
    | VarDec ASSIGNOP error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Wrong expression");}
    ;

Exp : Exp ASSIGNOP Exp{
    struct Node* new_node = construct_node(@1.begin.line,"Exp",non_end);
    struct Node* ASSIGNOP_node = construct_node(@2.begin.line,"ASSIGNOP",end);
    $$ = new_node;
    
    add_child($$,$1);
    add_child($$, ASSIGNOP_node);
    add_child($$, $3);
}
    | Exp ASSIGNOP error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Wrong expression");}
    | Exp AND Exp {
        struct Node* new_node = construct_node(@1.begin.line,"Exp",non_end);
        struct Node* AND_node = construct_node(@2.begin.line,"AND",end);
        $$ = new_node;
        
        add_child($$,$1);
        add_child($$, AND_node);
        add_child($$, $3);
    }
    | Exp AND error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Wrong expression");}
    | Exp OR Exp {
        struct Node* new_node = construct_node(@1.begin.line,"Exp",non_end);
        struct Node* OR_node = construct_node(@2.begin.line,"OR",end);
        $$ = new_node;
        
        add_child($$,$1);
        add_child($$, OR_node);
        add_child($$, $3);
    }
    | Exp OR error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Wrong expression");}
    | Exp RELOP Exp {
        struct Node* new_node = construct_node(@1.begin.line,"Exp",non_end);
        struct Node* RELOP_node = construct_node(@2.begin.line,"RELOP",end);
        $$ = new_node;
        
        add_child($$,$1);
        add_child($$, RELOP_node);
        add_child($$, $3);
    }
    | Exp RELOP error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Wrong expression");}
    | Exp PLUS Exp {
        struct Node* new_node = construct_node(@1.begin.line,"Exp",non_end);
        struct Node* PLUS_node = construct_node(@2.begin.line,"PLUS",end);
        $$ = new_node;
        
        add_child($$,$1);
        add_child($$, PLUS_node);
        add_child($$, $3);
    }
    | Exp PLUS error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Wrong expression");}
    | Exp MINUS Exp {
        struct Node* new_node = construct_node(@1.begin.line,"Exp",non_end);
        struct Node* MINUS_node = construct_node(@2.begin.line,"MINUS",end);
        $$ = new_node;
        
        add_child($$,$1);
        add_child($$, MINUS_node);
        add_child($$, $3);
    }
    | Exp MINUS error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Wrong expression");}
    | Exp STAR Exp {
        struct Node* new_node = construct_node(@1.begin.line,"Exp",non_end);
        struct Node* STAR_node = construct_node(@2.begin.line,"STAR",end);
        $$ = new_node;
        
        add_child($$,$1);
        add_child($$, STAR_node);
        add_child($$, $3);
    }
    | Exp STAR error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Wrong expression");}
    | Exp DIV Exp {
        struct Node* new_node = construct_node(@1.begin.line,"Exp",non_end);
        struct Node* DIV_node = construct_node(@2.begin.line,"DIV",end);
        $$ = new_node;
        
        add_child($$,$1);
        add_child($$, DIV_node);
        add_child($$, $3);
    }
    | Exp DIV error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Wrong expression");}
    | LP Exp RP {
        struct Node* new_node = construct_node(@1.begin.line,"Exp",non_end);
        struct Node* LP_node = construct_node(@1.begin.line,"LP",end);
        struct Node* RP_node = construct_node(@3.begin.line,"RP",end);
        $$ = new_node;
        
        add_child($$,LP_node);
        add_child($$, $2);
        add_child($$, RP_node);
    }
    | LP error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Missing )");}
    | MINUS Exp {
        struct Node* new_node = construct_node(@1.begin.line,"Exp",non_end);
        struct Node* MINUS_node = construct_node(@1.begin.line,"MINUS",end);
        $$ = new_node;
        
        add_child($$,MINUS_node);
        add_child($$, $2);
    }
    | MINUS error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Wrong expression");}
    | NOT Exp {
        struct Node* new_node = construct_node(@1.begin.line,"Exp",non_end);
        struct Node* NOT_node = construct_node(@1.begin.line,"NOT",end);
        $$ = new_node;
        
        add_child($$,NOT_node);
        add_child($$, $2);
    }
    | NOT error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Wrong expression");}
    | ID LP Args RP {
        struct Node* new_node = construct_node(@1.begin.line,"Exp",non_end);
        struct Node* ID_node = construct_node(@1.begin.line,"ID",string_node);
        ID_node->m_value.type_string = $1;
        struct Node* LP_node = construct_node(@2.begin.line,"LP",end);
        struct Node* RP_node = construct_node(@4.begin.line,"RP",end);
        $$ = new_node;
        
        add_child($$,ID_node);
        add_child($$,LP_node);
        add_child($$, $3);
        add_child($$,RP_node);
    }
    | ID LP Args error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Missing )");}
    | ID LP RP {
        struct Node* new_node = construct_node(@1.begin.line,"Exp",non_end);
        struct Node* ID_node = construct_node(@1.begin.line,"ID",string_node);
        ID_node->m_value.type_string = $1;
        struct Node* LP_node = construct_node(@2.begin.line,"LP",end);
        struct Node* RP_node = construct_node(@3.begin.line,"RP",end);
        $$ = new_node;
        
        add_child($$,ID_node);
        add_child($$,LP_node);
        add_child($$,RP_node);
    }
    | ID LP error {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Missing )");}
    | Exp LB Exp RB {
        struct Node* new_node = construct_node(@1.begin.line,"Exp",non_end);
        struct Node* LB_node = construct_node(@2.begin.line,"LB",end);
        struct Node* RB_node = construct_node(@4.begin.line,"RB",end);
        $$ = new_node;
        
        add_child($$,$1);
        add_child($$,LB_node);
        add_child($$,$3);
        add_child($$,RB_node);
    }
    | Exp LB error RB {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Wrong expression");}
    | Exp DOT ID {
        struct Node* new_node = construct_node(@1.begin.line,"Exp",non_end);
        struct Node* DOT_node = construct_node(@2.begin.line,"DOT",end);
        struct Node* ID_node = construct_node(@3.begin.line,"ID",string_node);
        ID_node->m_value.type_string = $3;
        $$ = new_node;
        
        add_child($$,$1);
        add_child($$,DOT_node);
        add_child($$,ID_node);
    }
    | ID {
        struct Node* new_node = construct_node(@1.begin.line,"Exp",non_end);
        struct Node* ID_node = construct_node(@1.begin.line,"ID",string_node);
        ID_node->m_value.type_string = $1;
        $$ = new_node;
        
        add_child($$,ID_node);
    }
    | INT {
        struct Node* new_node = construct_node(@1.begin.line,"Exp",non_end);
        struct Node* INT_node = construct_node(@1.begin.line,"INT",int_node);
        INT_node->m_value.type_int = $1;
        $$ = new_node;
        
        add_child($$,INT_node);
    }
    | FLOAT {
        struct Node* new_node = construct_node(@1.begin.line,"Exp",non_end);
        struct Node* FLOAT_node = construct_node(@1.begin.line,"FLOAT",float_node);
        FLOAT_node->m_value.type_float = $1;
        $$ = new_node;
        
        add_child($$,FLOAT_node);

    }
    | error RP {fprintf(stderr, "ERROR type B at Line %d: %s\n", @1.begin.line, "Wrong expression");}
    ;
Args : Exp COMMA Args {
    struct Node* new_node = construct_node(@1.begin.line,"Args",non_end);
    struct Node* COMMA_node = construct_node(@2.begin.line,"COMMA",end);
    $$ = new_node;
    
    add_child($$,$1);
    add_child($$,COMMA_node);
    add_child($$,$3);
}
    | Exp {
        struct Node* new_node = construct_node(@1.begin.line,"Args",non_end);
        $$ = new_node;
        
        add_child($$,$1);
    }
    ;


%%

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
