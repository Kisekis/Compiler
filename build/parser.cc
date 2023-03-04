// A Bison parser, made by GNU Bison 3.8.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hh"


// Unqualified %code blocks.
#line 26 "parser.yy"

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

#line 140 "/home/compiler/build/parser.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 232 "/home/compiler/build/parser.cc"

  /// Build a parser object.
  parser::parser (driver& drv_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false),
      drv (drv_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_Program: // Program
      case symbol_kind::S_ExtDefList: // ExtDefList
      case symbol_kind::S_ExtDef: // ExtDef
      case symbol_kind::S_ExtDecList: // ExtDecList
      case symbol_kind::S_Specifier: // Specifier
      case symbol_kind::S_StructSpecifier: // StructSpecifier
      case symbol_kind::S_OptTag: // OptTag
      case symbol_kind::S_Tag: // Tag
      case symbol_kind::S_VarDec: // VarDec
      case symbol_kind::S_FunDec: // FunDec
      case symbol_kind::S_VarList: // VarList
      case symbol_kind::S_ParamDec: // ParamDec
      case symbol_kind::S_CompSt: // CompSt
      case symbol_kind::S_StmtList: // StmtList
      case symbol_kind::S_Stmt: // Stmt
      case symbol_kind::S_DefList: // DefList
      case symbol_kind::S_Def: // Def
      case symbol_kind::S_DecList: // DecList
      case symbol_kind::S_Dec: // Dec
      case symbol_kind::S_Exp: // Exp
      case symbol_kind::S_Args: // Args
        value.YY_MOVE_OR_COPY< Node* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // "float"
        value.YY_MOVE_OR_COPY< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // "int"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_TYPE: // TYPE
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_Program: // Program
      case symbol_kind::S_ExtDefList: // ExtDefList
      case symbol_kind::S_ExtDef: // ExtDef
      case symbol_kind::S_ExtDecList: // ExtDecList
      case symbol_kind::S_Specifier: // Specifier
      case symbol_kind::S_StructSpecifier: // StructSpecifier
      case symbol_kind::S_OptTag: // OptTag
      case symbol_kind::S_Tag: // Tag
      case symbol_kind::S_VarDec: // VarDec
      case symbol_kind::S_FunDec: // FunDec
      case symbol_kind::S_VarList: // VarList
      case symbol_kind::S_ParamDec: // ParamDec
      case symbol_kind::S_CompSt: // CompSt
      case symbol_kind::S_StmtList: // StmtList
      case symbol_kind::S_Stmt: // Stmt
      case symbol_kind::S_DefList: // DefList
      case symbol_kind::S_Def: // Def
      case symbol_kind::S_DecList: // DecList
      case symbol_kind::S_Dec: // Dec
      case symbol_kind::S_Exp: // Exp
      case symbol_kind::S_Args: // Args
        value.move< Node* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_FLOAT: // "float"
        value.move< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // "int"
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_TYPE: // TYPE
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_Program: // Program
      case symbol_kind::S_ExtDefList: // ExtDefList
      case symbol_kind::S_ExtDef: // ExtDef
      case symbol_kind::S_ExtDecList: // ExtDecList
      case symbol_kind::S_Specifier: // Specifier
      case symbol_kind::S_StructSpecifier: // StructSpecifier
      case symbol_kind::S_OptTag: // OptTag
      case symbol_kind::S_Tag: // Tag
      case symbol_kind::S_VarDec: // VarDec
      case symbol_kind::S_FunDec: // FunDec
      case symbol_kind::S_VarList: // VarList
      case symbol_kind::S_ParamDec: // ParamDec
      case symbol_kind::S_CompSt: // CompSt
      case symbol_kind::S_StmtList: // StmtList
      case symbol_kind::S_Stmt: // Stmt
      case symbol_kind::S_DefList: // DefList
      case symbol_kind::S_Def: // Def
      case symbol_kind::S_DecList: // DecList
      case symbol_kind::S_Dec: // Dec
      case symbol_kind::S_Exp: // Exp
      case symbol_kind::S_Args: // Args
        value.copy< Node* > (that.value);
        break;

      case symbol_kind::S_FLOAT: // "float"
        value.copy< float > (that.value);
        break;

      case symbol_kind::S_INT: // "int"
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_TYPE: // TYPE
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_Program: // Program
      case symbol_kind::S_ExtDefList: // ExtDefList
      case symbol_kind::S_ExtDef: // ExtDef
      case symbol_kind::S_ExtDecList: // ExtDecList
      case symbol_kind::S_Specifier: // Specifier
      case symbol_kind::S_StructSpecifier: // StructSpecifier
      case symbol_kind::S_OptTag: // OptTag
      case symbol_kind::S_Tag: // Tag
      case symbol_kind::S_VarDec: // VarDec
      case symbol_kind::S_FunDec: // FunDec
      case symbol_kind::S_VarList: // VarList
      case symbol_kind::S_ParamDec: // ParamDec
      case symbol_kind::S_CompSt: // CompSt
      case symbol_kind::S_StmtList: // StmtList
      case symbol_kind::S_Stmt: // Stmt
      case symbol_kind::S_DefList: // DefList
      case symbol_kind::S_Def: // Def
      case symbol_kind::S_DecList: // DecList
      case symbol_kind::S_Dec: // Dec
      case symbol_kind::S_Exp: // Exp
      case symbol_kind::S_Args: // Args
        value.move< Node* > (that.value);
        break;

      case symbol_kind::S_FLOAT: // "float"
        value.move< float > (that.value);
        break;

      case symbol_kind::S_INT: // "int"
        value.move< int > (that.value);
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_TYPE: // TYPE
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        switch (yykind)
    {
      case symbol_kind::S_INT: // "int"
#line 129 "parser.yy"
                 { yyo << yysym.value.template as < int > (); }
#line 532 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_FLOAT: // "float"
#line 129 "parser.yy"
                 { yyo << yysym.value.template as < float > (); }
#line 538 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_ID: // ID
#line 129 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 544 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_TYPE: // TYPE
#line 129 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 550 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_Program: // Program
#line 129 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 556 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_ExtDefList: // ExtDefList
#line 129 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 562 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_ExtDef: // ExtDef
#line 129 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 568 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_ExtDecList: // ExtDecList
#line 129 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 574 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_Specifier: // Specifier
#line 129 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 580 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_StructSpecifier: // StructSpecifier
#line 129 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 586 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_OptTag: // OptTag
#line 129 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 592 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_Tag: // Tag
#line 129 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 598 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_VarDec: // VarDec
#line 129 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 604 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_FunDec: // FunDec
#line 129 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 610 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_VarList: // VarList
#line 129 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 616 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_ParamDec: // ParamDec
#line 129 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 622 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_CompSt: // CompSt
#line 129 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 628 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_StmtList: // StmtList
#line 129 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 634 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_Stmt: // Stmt
#line 129 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 640 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_DefList: // DefList
#line 129 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 646 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_Def: // Def
#line 129 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 652 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_DecList: // DecList
#line 129 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 658 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_Dec: // Dec
#line 129 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 664 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_Exp: // Exp
#line 129 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 670 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_Args: // Args
#line 129 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 676 "/home/compiler/build/parser.cc"
        break;

      default:
        break;
    }
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // Discard the LAC context in case there still is one left from a
    // previous invocation.
    yy_lac_discard_ ("init");

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (drv));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;

        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    yy_lac_discard_ ("shift");
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_Program: // Program
      case symbol_kind::S_ExtDefList: // ExtDefList
      case symbol_kind::S_ExtDef: // ExtDef
      case symbol_kind::S_ExtDecList: // ExtDecList
      case symbol_kind::S_Specifier: // Specifier
      case symbol_kind::S_StructSpecifier: // StructSpecifier
      case symbol_kind::S_OptTag: // OptTag
      case symbol_kind::S_Tag: // Tag
      case symbol_kind::S_VarDec: // VarDec
      case symbol_kind::S_FunDec: // FunDec
      case symbol_kind::S_VarList: // VarList
      case symbol_kind::S_ParamDec: // ParamDec
      case symbol_kind::S_CompSt: // CompSt
      case symbol_kind::S_StmtList: // StmtList
      case symbol_kind::S_Stmt: // Stmt
      case symbol_kind::S_DefList: // DefList
      case symbol_kind::S_Def: // Def
      case symbol_kind::S_DecList: // DecList
      case symbol_kind::S_Dec: // Dec
      case symbol_kind::S_Exp: // Exp
      case symbol_kind::S_Args: // Args
        yylhs.value.emplace< Node* > ();
        break;

      case symbol_kind::S_FLOAT: // "float"
        yylhs.value.emplace< float > ();
        break;

      case symbol_kind::S_INT: // "int"
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_TYPE: // TYPE
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // Program: ExtDefList
#line 152 "parser.yy"
                    {
    struct Node* new_node = construct_node(yystack_[0].location.begin.line,"Program",non_end);
    root = new_node;
    yylhs.value.as < Node* > () = new_node;
    add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > ());
}
#line 981 "/home/compiler/build/parser.cc"
    break;

  case 3: // ExtDefList: ExtDef ExtDefList
#line 158 "parser.yy"
                              {
    struct Node* new_node = construct_node(yystack_[1].location.begin.line,"ExtDefList",non_end);
    yylhs.value.as < Node* > () = new_node;
    add_child(yylhs.value.as < Node* > (),yystack_[1].value.as < Node* > ());
    add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > ());
}
#line 992 "/home/compiler/build/parser.cc"
    break;

  case 4: // ExtDefList: %empty
#line 164 "parser.yy"
               {
        yylhs.value.as < Node* > () = NULL;
    }
#line 1000 "/home/compiler/build/parser.cc"
    break;

  case 5: // ExtDef: Specifier ExtDecList SEMI
#line 168 "parser.yy"
                                  {
    struct Node* new_node = construct_node(yystack_[2].location.begin.line,"ExtDef",non_end);
    struct Node* SEMI_node = construct_node(yystack_[0].location.begin.line,"SEMI",end);
    yylhs.value.as < Node* > () = new_node;
    add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > ());
    add_child(yylhs.value.as < Node* > (),yystack_[1].value.as < Node* > ());
    add_child(yylhs.value.as < Node* > (),SEMI_node);
}
#line 1013 "/home/compiler/build/parser.cc"
    break;

  case 6: // ExtDef: Specifier SEMI
#line 176 "parser.yy"
                     {
        struct Node* new_node = construct_node(yystack_[1].location.begin.line,"ExtDef",non_end);
        struct Node* SEMI_node = construct_node(yystack_[0].location.begin.line,"SEMI",end);
        yylhs.value.as < Node* > () = new_node;
        add_child(yylhs.value.as < Node* > (),yystack_[1].value.as < Node* > ());
        add_child(yylhs.value.as < Node* > (),SEMI_node);
    }
#line 1025 "/home/compiler/build/parser.cc"
    break;

  case 7: // ExtDef: Specifier FunDec CompSt
#line 183 "parser.yy"
                              {
        struct Node* new_node = construct_node(yystack_[2].location.begin.line,"ExtDef",non_end);
        yylhs.value.as < Node* > () = new_node;
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > ());
        add_child(yylhs.value.as < Node* > (),yystack_[1].value.as < Node* > ());
        add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > ());
    }
#line 1037 "/home/compiler/build/parser.cc"
    break;

  case 8: // ExtDef: Specifier error
#line 190 "parser.yy"
                      {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[1].location.begin.line, "delcaration error");}
#line 1043 "/home/compiler/build/parser.cc"
    break;

  case 9: // ExtDecList: VarDec
#line 192 "parser.yy"
                    {
    struct Node* new_node = construct_node(yystack_[0].location.begin.line,"ExtDecList",non_end);
    yylhs.value.as < Node* > () = new_node;
    add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > ());
}
#line 1053 "/home/compiler/build/parser.cc"
    break;

  case 10: // ExtDecList: VarDec COMMA ExtDecList
#line 197 "parser.yy"
                              {
        struct Node* new_node = construct_node(yystack_[2].location.begin.line,"ExtDecList",non_end);
        struct Node* COMMA_node = construct_node(yystack_[1].location.begin.line,"COMMA",end);
        yylhs.value.as < Node* > () = new_node;
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > ());
        add_child(yylhs.value.as < Node* > (),COMMA_node);
        add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > ());
    }
#line 1066 "/home/compiler/build/parser.cc"
    break;

  case 11: // ExtDecList: VarDec COMMA error
#line 205 "parser.yy"
                         {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "delcaration error");}
#line 1072 "/home/compiler/build/parser.cc"
    break;

  case 12: // Specifier: TYPE
#line 207 "parser.yy"
                 {
    struct Node* new_node = construct_node(yystack_[0].location.begin.line,"Specifier",non_end);
    struct Node* TYPE_node = construct_node(yystack_[0].location.begin.line,"TYPE",string_node);
    TYPE_node->m_value.type_string = yystack_[0].value.as < std::string > ();
    yylhs.value.as < Node* > () = new_node;
    add_child(yylhs.value.as < Node* > (),TYPE_node);
}
#line 1084 "/home/compiler/build/parser.cc"
    break;

  case 13: // Specifier: StructSpecifier
#line 214 "parser.yy"
                      {
        struct Node* new_node = construct_node(yystack_[0].location.begin.line,"Specifier",non_end);
        yylhs.value.as < Node* > () = new_node;
        add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > ());
    }
#line 1094 "/home/compiler/build/parser.cc"
    break;

  case 14: // StructSpecifier: STRUCT OptTag LC DefList RC
#line 220 "parser.yy"
                                              {
    struct Node* new_node = construct_node(yystack_[4].location.begin.line,"StructSpecifier",non_end);
    yylhs.value.as < Node* > () = new_node;
    struct Node* STRUCT_node = construct_node(yystack_[4].location.begin.line,"STRUCT",end);
    struct Node* LC_node = construct_node(yystack_[2].location.begin.line,"LC",end);
    struct Node* RC_node = construct_node(yystack_[0].location.begin.line,"RC",end);
    add_child(yylhs.value.as < Node* > (),STRUCT_node);
    add_child(yylhs.value.as < Node* > (),yystack_[3].value.as < Node* > ());
    add_child(yylhs.value.as < Node* > (),LC_node);
    add_child(yylhs.value.as < Node* > (),yystack_[1].value.as < Node* > ());
    add_child(yylhs.value.as < Node* > (),RC_node);
}
#line 1111 "/home/compiler/build/parser.cc"
    break;

  case 15: // StructSpecifier: STRUCT Tag
#line 232 "parser.yy"
                 {
        struct Node* new_node = construct_node(yystack_[1].location.begin.line,"StructSpecifier",non_end);
        yylhs.value.as < Node* > () = new_node;
        struct Node* STRUCT_node = construct_node(yystack_[1].location.begin.line,"STRUCT",end);
        add_child(yylhs.value.as < Node* > (),STRUCT_node);
        add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > ());
    }
#line 1123 "/home/compiler/build/parser.cc"
    break;

  case 16: // StructSpecifier: STRUCT OptTag LC error RC
#line 239 "parser.yy"
                               {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[4].location.begin.line, "struct error");}
#line 1129 "/home/compiler/build/parser.cc"
    break;

  case 17: // OptTag: ID
#line 241 "parser.yy"
           {
    struct Node* new_node = construct_node(yystack_[0].location.begin.line,"OptTag",non_end);
    yylhs.value.as < Node* > () = new_node;
    struct Node* ID_node = construct_node(yystack_[0].location.begin.line,"ID",string_node);
    ID_node->m_value.type_string = yystack_[0].value.as < std::string > ();
    add_child(yylhs.value.as < Node* > (),ID_node);
}
#line 1141 "/home/compiler/build/parser.cc"
    break;

  case 18: // OptTag: %empty
#line 248 "parser.yy"
               {
        yylhs.value.as < Node* > () = NULL;
    }
#line 1149 "/home/compiler/build/parser.cc"
    break;

  case 19: // Tag: ID
#line 252 "parser.yy"
        {
    struct Node* new_node = construct_node(yystack_[0].location.begin.line,"Tag",non_end);
    yylhs.value.as < Node* > () = new_node;
    struct Node* ID_node = construct_node(yystack_[0].location.begin.line,"ID",string_node);
    ID_node->m_value.type_string = yystack_[0].value.as < std::string > ();
    add_child(yylhs.value.as < Node* > (),ID_node);
}
#line 1161 "/home/compiler/build/parser.cc"
    break;

  case 20: // VarDec: ID
#line 261 "parser.yy"
            {
    struct Node* new_node = construct_node(yystack_[0].location.begin.line,"VarDec",non_end);
    yylhs.value.as < Node* > () = new_node;
    struct Node* ID_node = construct_node(yystack_[0].location.begin.line,"ID",string_node);
    ID_node->m_value.type_string = yystack_[0].value.as < std::string > ();
    add_child(yylhs.value.as < Node* > (),ID_node);
}
#line 1173 "/home/compiler/build/parser.cc"
    break;

  case 21: // VarDec: VarDec LB "int" RB
#line 268 "parser.yy"
                       {
        struct Node* new_node = construct_node(yystack_[3].location.begin.line,"VarDec",non_end);
        yylhs.value.as < Node* > () = new_node;
        struct Node* LB_node = construct_node(yystack_[2].location.begin.line,"LB",end);
        struct Node* INT_node = construct_node(yystack_[1].location.begin.line,"INT",int_node);
        INT_node->m_value.type_int = yystack_[1].value.as < int > ();
        struct Node* RB_node = construct_node(yystack_[0].location.begin.line,"RB",end);
        add_child(yylhs.value.as < Node* > (),yystack_[3].value.as < Node* > ());
        add_child(yylhs.value.as < Node* > (), LB_node);
        add_child(yylhs.value.as < Node* > (),INT_node);
        add_child(yylhs.value.as < Node* > (),RB_node);
    }
#line 1190 "/home/compiler/build/parser.cc"
    break;

  case 22: // VarDec: VarDec LB error RB
#line 280 "parser.yy"
                         {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[3].location.begin.line, "wrong variable declaration");}
#line 1196 "/home/compiler/build/parser.cc"
    break;

  case 23: // FunDec: ID LP VarList RP
#line 282 "parser.yy"
                          {
    struct Node* new_node = construct_node(yystack_[3].location.begin.line,"FunDec",non_end);
    yylhs.value.as < Node* > () = new_node;
    struct Node* ID_node = construct_node(yystack_[3].location.begin.line,"ID",string_node);
    ID_node->m_value.type_string = yystack_[3].value.as < std::string > ();
    struct Node* LP_node = construct_node(yystack_[2].location.begin.line,"LP",end);
    struct Node* RP_node = construct_node(yystack_[0].location.begin.line,"RP",end);
    add_child(yylhs.value.as < Node* > (),ID_node);
    add_child(yylhs.value.as < Node* > (), LP_node);
    add_child(yylhs.value.as < Node* > (),yystack_[1].value.as < Node* > ());
    add_child(yylhs.value.as < Node* > (),RP_node);
}
#line 1213 "/home/compiler/build/parser.cc"
    break;

  case 24: // FunDec: ID LP RP
#line 294 "parser.yy"
               {
        struct Node* new_node = construct_node(yystack_[2].location.begin.line,"FunDec",non_end);
        yylhs.value.as < Node* > () = new_node;
        struct Node* ID_node = construct_node(yystack_[2].location.begin.line,"ID",string_node);
        ID_node->m_value.type_string = yystack_[2].value.as < std::string > ();
        struct Node* LP_node = construct_node(yystack_[1].location.begin.line,"LP",end);
        struct Node* RP_node = construct_node(yystack_[0].location.begin.line,"RP",end);
        add_child(yylhs.value.as < Node* > (),ID_node);
        add_child(yylhs.value.as < Node* > (), LP_node);
        add_child(yylhs.value.as < Node* > (),RP_node);
    }
#line 1229 "/home/compiler/build/parser.cc"
    break;

  case 25: // VarList: ParamDec COMMA VarList
#line 306 "parser.yy"
                                 {
    struct Node* new_node = construct_node(yystack_[2].location.begin.line,"VarList",non_end);
    yylhs.value.as < Node* > () = new_node;
    struct Node* COMMA_node = construct_node(yystack_[1].location.begin.line,"COMMA",end);
    add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > ());
    add_child(yylhs.value.as < Node* > (), COMMA_node);
    add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > ());
}
#line 1242 "/home/compiler/build/parser.cc"
    break;

  case 26: // VarList: ParamDec
#line 314 "parser.yy"
               {
        struct Node* new_node = construct_node(yystack_[0].location.begin.line,"VarList",non_end);
        yylhs.value.as < Node* > () = new_node;
        add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > ());
    }
#line 1252 "/home/compiler/build/parser.cc"
    break;

  case 27: // ParamDec: Specifier VarDec
#line 320 "parser.yy"
                            {
    struct Node* new_node = construct_node(yystack_[1].location.begin.line,"ParamDec",non_end);
    yylhs.value.as < Node* > () = new_node;
    add_child(yylhs.value.as < Node* > (),yystack_[1].value.as < Node* > ());
    add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > ());
}
#line 1263 "/home/compiler/build/parser.cc"
    break;

  case 28: // CompSt: LC DefList StmtList RC
#line 328 "parser.yy"
                                {
    struct Node* new_node = construct_node(yystack_[3].location.begin.line,"CompSt",non_end);
    yylhs.value.as < Node* > () = new_node;
    struct Node* LC_node = construct_node(yystack_[3].location.begin.line,"LC",end);
    struct Node* RC_node = construct_node(yystack_[0].location.begin.line,"RC",end);
    add_child(yylhs.value.as < Node* > (),LC_node);
    add_child(yylhs.value.as < Node* > (), yystack_[2].value.as < Node* > ());
    add_child(yylhs.value.as < Node* > (),yystack_[1].value.as < Node* > ());
    add_child(yylhs.value.as < Node* > (),RC_node);
}
#line 1278 "/home/compiler/build/parser.cc"
    break;

  case 29: // CompSt: error DefList StmtList RC
#line 338 "parser.yy"
                                {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[3].location.begin.line, "Missing {");}
#line 1284 "/home/compiler/build/parser.cc"
    break;

  case 30: // StmtList: Stmt StmtList
#line 340 "parser.yy"
                         {
    struct Node* new_node = construct_node(yystack_[1].location.begin.line,"StmtList",non_end);
    yylhs.value.as < Node* > () = new_node;
    add_child(yylhs.value.as < Node* > (), yystack_[1].value.as < Node* > ());
    add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > ());
}
#line 1295 "/home/compiler/build/parser.cc"
    break;

  case 31: // StmtList: %empty
#line 346 "parser.yy"
                {
        yylhs.value.as < Node* > () = NULL;
    }
#line 1303 "/home/compiler/build/parser.cc"
    break;

  case 32: // Stmt: Exp SEMI
#line 350 "parser.yy"
               {
    struct Node* new_node = construct_node(yystack_[1].location.begin.line,"Stmt",non_end);
    struct Node* SEMI_node = construct_node(yystack_[0].location.begin.line,"SEMI",end);
    yylhs.value.as < Node* > () = new_node;
    add_child(yylhs.value.as < Node* > (), yystack_[1].value.as < Node* > ());
    add_child(yylhs.value.as < Node* > (),SEMI_node);
}
#line 1315 "/home/compiler/build/parser.cc"
    break;

  case 33: // Stmt: error SEMI
#line 357 "parser.yy"
                 {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[1].location.begin.line, "wrong expression");}
#line 1321 "/home/compiler/build/parser.cc"
    break;

  case 34: // Stmt: Exp error
#line 358 "parser.yy"
                {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[1].location.begin.line, "Missing ;");}
#line 1327 "/home/compiler/build/parser.cc"
    break;

  case 35: // Stmt: CompSt
#line 359 "parser.yy"
            {
        struct Node* new_node = construct_node(yystack_[0].location.begin.line,"Stmt",non_end);
        yylhs.value.as < Node* > () = new_node;
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > ());
    }
#line 1337 "/home/compiler/build/parser.cc"
    break;

  case 36: // Stmt: RETURN Exp SEMI
#line 364 "parser.yy"
                      {
        struct Node* new_node = construct_node(yystack_[2].location.begin.line,"Stmt",non_end);
        struct Node* RETURN_node = construct_node(yystack_[2].location.begin.line,"RETURN",end);
        struct Node* SEMI_node = construct_node(yystack_[0].location.begin.line,"SEMI",end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),RETURN_node);
        add_child(yylhs.value.as < Node* > (), yystack_[1].value.as < Node* > ());
        add_child(yylhs.value.as < Node* > (),SEMI_node);
    }
#line 1352 "/home/compiler/build/parser.cc"
    break;

  case 37: // Stmt: RETURN Exp error
#line 374 "parser.yy"
                       {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Missing ;");}
#line 1358 "/home/compiler/build/parser.cc"
    break;

  case 38: // Stmt: RETURN error SEMI
#line 375 "parser.yy"
                        {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong return expression");}
#line 1364 "/home/compiler/build/parser.cc"
    break;

  case 39: // Stmt: IF LP Exp RP Stmt
#line 376 "parser.yy"
                        {
        struct Node* new_node = construct_node(yystack_[4].location.begin.line,"Stmt",non_end);
        struct Node* IF_node = construct_node(yystack_[4].location.begin.line,"IF",end);
        struct Node* LP_node = construct_node(yystack_[3].location.begin.line,"LP",end);
        struct Node* RP_node = construct_node(yystack_[1].location.begin.line,"RP",end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),IF_node);
        add_child(yylhs.value.as < Node* > (), LP_node);
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > ());
        add_child(yylhs.value.as < Node* > (),RP_node);
        add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > ());
    }
#line 1382 "/home/compiler/build/parser.cc"
    break;

  case 40: // Stmt: IF LP Exp RP Stmt ELSE Stmt
#line 389 "parser.yy"
                                  {
        struct Node* new_node = construct_node(yystack_[6].location.begin.line,"Stmt",non_end);
        struct Node* IF_node = construct_node(yystack_[6].location.begin.line,"IF",end);
        struct Node* LP_node = construct_node(yystack_[5].location.begin.line,"LP",end);
        struct Node* RP_node = construct_node(yystack_[3].location.begin.line,"RP",end);
        struct Node* ELSE_node = construct_node(yystack_[1].location.begin.line,"ELSE",end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),IF_node);
        add_child(yylhs.value.as < Node* > (), LP_node);
        add_child(yylhs.value.as < Node* > (),yystack_[4].value.as < Node* > ());
        add_child(yylhs.value.as < Node* > (),RP_node);
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > ());
        add_child(yylhs.value.as < Node* > (),ELSE_node);
        add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > ());
    }
#line 1403 "/home/compiler/build/parser.cc"
    break;

  case 41: // Stmt: WHILE LP Exp RP Stmt
#line 405 "parser.yy"
                           {
        struct Node* new_node = construct_node(yystack_[4].location.begin.line,"Stmt",non_end);
        struct Node* WHILE_node = construct_node(yystack_[4].location.begin.line,"WHILE",end);
        struct Node* LP_node = construct_node(yystack_[3].location.begin.line,"LP",end);
        struct Node* RP_node = construct_node(yystack_[1].location.begin.line,"RP",end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),WHILE_node);
        add_child(yylhs.value.as < Node* > (), LP_node);
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > ());
        add_child(yylhs.value.as < Node* > (),RP_node);
        add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > ());
    }
#line 1421 "/home/compiler/build/parser.cc"
    break;

  case 42: // DefList: Def DefList
#line 420 "parser.yy"
                      {
    struct Node* new_node = construct_node(yystack_[1].location.begin.line,"DefList",non_end);
    yylhs.value.as < Node* > () = new_node;
    
    add_child(yylhs.value.as < Node* > (),yystack_[1].value.as < Node* > ());
    add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > ());
}
#line 1433 "/home/compiler/build/parser.cc"
    break;

  case 43: // DefList: %empty
#line 427 "parser.yy"
               {
        yylhs.value.as < Node* > () = NULL;
    }
#line 1441 "/home/compiler/build/parser.cc"
    break;

  case 44: // Def: Specifier DecList SEMI
#line 431 "parser.yy"
                             {
    struct Node* new_node = construct_node(yystack_[2].location.begin.line,"Def",non_end);
    struct Node* SEMI_node = construct_node(yystack_[0].location.begin.line,"SEMI",end);
    yylhs.value.as < Node* > () = new_node;
    
    add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > ());
    add_child(yylhs.value.as < Node* > (), yystack_[1].value.as < Node* > ());
    add_child(yylhs.value.as < Node* > (), SEMI_node);
}
#line 1455 "/home/compiler/build/parser.cc"
    break;

  case 45: // Def: error DecList SEMI
#line 440 "parser.yy"
                         {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong declaration");}
#line 1461 "/home/compiler/build/parser.cc"
    break;

  case 46: // Def: Specifier error SEMI
#line 441 "parser.yy"
                           {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong declaration");}
#line 1467 "/home/compiler/build/parser.cc"
    break;

  case 47: // DecList: Dec
#line 443 "parser.yy"
              {
    struct Node* new_node = construct_node(yystack_[0].location.begin.line,"DecList",non_end);
    yylhs.value.as < Node* > () = new_node;
    
    add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > ());
}
#line 1478 "/home/compiler/build/parser.cc"
    break;

  case 48: // DecList: Dec COMMA DecList
#line 449 "parser.yy"
                        {
        struct Node* new_node = construct_node(yystack_[2].location.begin.line,"DecList",non_end);
        struct Node* COMMA_node = construct_node(yystack_[1].location.begin.line,"COMMA",end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > ());
        add_child(yylhs.value.as < Node* > (), COMMA_node);
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > ());
    }
#line 1492 "/home/compiler/build/parser.cc"
    break;

  case 49: // Dec: VarDec
#line 459 "parser.yy"
             {
    struct Node* new_node = construct_node(yystack_[0].location.begin.line,"Dec",non_end);
    yylhs.value.as < Node* > () = new_node;
    
    add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > ());
}
#line 1503 "/home/compiler/build/parser.cc"
    break;

  case 50: // Dec: VarDec ASSIGNOP Exp
#line 465 "parser.yy"
                          {
        struct Node* new_node = construct_node(yystack_[2].location.begin.line,"Dec",non_end);
        struct Node* ASSIGNOP_node = construct_node(yystack_[1].location.begin.line,"ASSIGNOP",end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > ());
        add_child(yylhs.value.as < Node* > (), ASSIGNOP_node);
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > ());
    }
#line 1517 "/home/compiler/build/parser.cc"
    break;

  case 51: // Dec: VarDec ASSIGNOP error
#line 474 "parser.yy"
                            {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong expression");}
#line 1523 "/home/compiler/build/parser.cc"
    break;

  case 52: // Exp: Exp ASSIGNOP Exp
#line 477 "parser.yy"
                      {
    struct Node* new_node = construct_node(yystack_[2].location.begin.line,"Exp",non_end);
    struct Node* ASSIGNOP_node = construct_node(yystack_[1].location.begin.line,"ASSIGNOP",end);
    yylhs.value.as < Node* > () = new_node;
    
    add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > ());
    add_child(yylhs.value.as < Node* > (), ASSIGNOP_node);
    add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > ());
}
#line 1537 "/home/compiler/build/parser.cc"
    break;

  case 53: // Exp: Exp ASSIGNOP error
#line 486 "parser.yy"
                         {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong expression");}
#line 1543 "/home/compiler/build/parser.cc"
    break;

  case 54: // Exp: Exp AND Exp
#line 487 "parser.yy"
                  {
        struct Node* new_node = construct_node(yystack_[2].location.begin.line,"Exp",non_end);
        struct Node* AND_node = construct_node(yystack_[1].location.begin.line,"AND",end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > ());
        add_child(yylhs.value.as < Node* > (), AND_node);
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > ());
    }
#line 1557 "/home/compiler/build/parser.cc"
    break;

  case 55: // Exp: Exp AND error
#line 496 "parser.yy"
                    {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong expression");}
#line 1563 "/home/compiler/build/parser.cc"
    break;

  case 56: // Exp: Exp OR Exp
#line 497 "parser.yy"
                 {
        struct Node* new_node = construct_node(yystack_[2].location.begin.line,"Exp",non_end);
        struct Node* OR_node = construct_node(yystack_[1].location.begin.line,"OR",end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > ());
        add_child(yylhs.value.as < Node* > (), OR_node);
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > ());
    }
#line 1577 "/home/compiler/build/parser.cc"
    break;

  case 57: // Exp: Exp OR error
#line 506 "parser.yy"
                   {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong expression");}
#line 1583 "/home/compiler/build/parser.cc"
    break;

  case 58: // Exp: Exp RELOP Exp
#line 507 "parser.yy"
                    {
        struct Node* new_node = construct_node(yystack_[2].location.begin.line,"Exp",non_end);
        struct Node* RELOP_node = construct_node(yystack_[1].location.begin.line,"RELOP",end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > ());
        add_child(yylhs.value.as < Node* > (), RELOP_node);
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > ());
    }
#line 1597 "/home/compiler/build/parser.cc"
    break;

  case 59: // Exp: Exp RELOP error
#line 516 "parser.yy"
                      {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong expression");}
#line 1603 "/home/compiler/build/parser.cc"
    break;

  case 60: // Exp: Exp PLUS Exp
#line 517 "parser.yy"
                   {
        struct Node* new_node = construct_node(yystack_[2].location.begin.line,"Exp",non_end);
        struct Node* PLUS_node = construct_node(yystack_[1].location.begin.line,"PLUS",end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > ());
        add_child(yylhs.value.as < Node* > (), PLUS_node);
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > ());
    }
#line 1617 "/home/compiler/build/parser.cc"
    break;

  case 61: // Exp: Exp PLUS error
#line 526 "parser.yy"
                     {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong expression");}
#line 1623 "/home/compiler/build/parser.cc"
    break;

  case 62: // Exp: Exp MINUS Exp
#line 527 "parser.yy"
                    {
        struct Node* new_node = construct_node(yystack_[2].location.begin.line,"Exp",non_end);
        struct Node* MINUS_node = construct_node(yystack_[1].location.begin.line,"MINUS",end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > ());
        add_child(yylhs.value.as < Node* > (), MINUS_node);
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > ());
    }
#line 1637 "/home/compiler/build/parser.cc"
    break;

  case 63: // Exp: Exp MINUS error
#line 536 "parser.yy"
                      {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong expression");}
#line 1643 "/home/compiler/build/parser.cc"
    break;

  case 64: // Exp: Exp STAR Exp
#line 537 "parser.yy"
                   {
        struct Node* new_node = construct_node(yystack_[2].location.begin.line,"Exp",non_end);
        struct Node* STAR_node = construct_node(yystack_[1].location.begin.line,"STAR",end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > ());
        add_child(yylhs.value.as < Node* > (), STAR_node);
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > ());
    }
#line 1657 "/home/compiler/build/parser.cc"
    break;

  case 65: // Exp: Exp STAR error
#line 546 "parser.yy"
                     {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong expression");}
#line 1663 "/home/compiler/build/parser.cc"
    break;

  case 66: // Exp: Exp DIV Exp
#line 547 "parser.yy"
                  {
        struct Node* new_node = construct_node(yystack_[2].location.begin.line,"Exp",non_end);
        struct Node* DIV_node = construct_node(yystack_[1].location.begin.line,"DIV",end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > ());
        add_child(yylhs.value.as < Node* > (), DIV_node);
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > ());
    }
#line 1677 "/home/compiler/build/parser.cc"
    break;

  case 67: // Exp: Exp DIV error
#line 556 "parser.yy"
                    {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong expression");}
#line 1683 "/home/compiler/build/parser.cc"
    break;

  case 68: // Exp: LP Exp RP
#line 557 "parser.yy"
                {
        struct Node* new_node = construct_node(yystack_[2].location.begin.line,"Exp",non_end);
        struct Node* LP_node = construct_node(yystack_[2].location.begin.line,"LP",end);
        struct Node* RP_node = construct_node(yystack_[0].location.begin.line,"RP",end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),LP_node);
        add_child(yylhs.value.as < Node* > (), yystack_[1].value.as < Node* > ());
        add_child(yylhs.value.as < Node* > (), RP_node);
    }
#line 1698 "/home/compiler/build/parser.cc"
    break;

  case 69: // Exp: LP error
#line 567 "parser.yy"
               {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[1].location.begin.line, "Missing )");}
#line 1704 "/home/compiler/build/parser.cc"
    break;

  case 70: // Exp: MINUS Exp
#line 568 "parser.yy"
                {
        struct Node* new_node = construct_node(yystack_[1].location.begin.line,"Exp",non_end);
        struct Node* MINUS_node = construct_node(yystack_[1].location.begin.line,"MINUS",end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),MINUS_node);
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > ());
    }
#line 1717 "/home/compiler/build/parser.cc"
    break;

  case 71: // Exp: MINUS error
#line 576 "parser.yy"
                  {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[1].location.begin.line, "Wrong expression");}
#line 1723 "/home/compiler/build/parser.cc"
    break;

  case 72: // Exp: NOT Exp
#line 577 "parser.yy"
              {
        struct Node* new_node = construct_node(yystack_[1].location.begin.line,"Exp",non_end);
        struct Node* NOT_node = construct_node(yystack_[1].location.begin.line,"NOT",end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),NOT_node);
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > ());
    }
#line 1736 "/home/compiler/build/parser.cc"
    break;

  case 73: // Exp: NOT error
#line 585 "parser.yy"
                {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[1].location.begin.line, "Wrong expression");}
#line 1742 "/home/compiler/build/parser.cc"
    break;

  case 74: // Exp: ID LP Args RP
#line 586 "parser.yy"
                    {
        struct Node* new_node = construct_node(yystack_[3].location.begin.line,"Exp",non_end);
        struct Node* ID_node = construct_node(yystack_[3].location.begin.line,"ID",string_node);
        ID_node->m_value.type_string = yystack_[3].value.as < std::string > ();
        struct Node* LP_node = construct_node(yystack_[2].location.begin.line,"LP",end);
        struct Node* RP_node = construct_node(yystack_[0].location.begin.line,"RP",end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),ID_node);
        add_child(yylhs.value.as < Node* > (),LP_node);
        add_child(yylhs.value.as < Node* > (), yystack_[1].value.as < Node* > ());
        add_child(yylhs.value.as < Node* > (),RP_node);
    }
#line 1760 "/home/compiler/build/parser.cc"
    break;

  case 75: // Exp: ID LP Args error
#line 599 "parser.yy"
                       {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[3].location.begin.line, "Missing )");}
#line 1766 "/home/compiler/build/parser.cc"
    break;

  case 76: // Exp: ID LP RP
#line 600 "parser.yy"
               {
        struct Node* new_node = construct_node(yystack_[2].location.begin.line,"Exp",non_end);
        struct Node* ID_node = construct_node(yystack_[2].location.begin.line,"ID",string_node);
        ID_node->m_value.type_string = yystack_[2].value.as < std::string > ();
        struct Node* LP_node = construct_node(yystack_[1].location.begin.line,"LP",end);
        struct Node* RP_node = construct_node(yystack_[0].location.begin.line,"RP",end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),ID_node);
        add_child(yylhs.value.as < Node* > (),LP_node);
        add_child(yylhs.value.as < Node* > (),RP_node);
    }
#line 1783 "/home/compiler/build/parser.cc"
    break;

  case 77: // Exp: ID LP error
#line 612 "parser.yy"
                  {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Missing )");}
#line 1789 "/home/compiler/build/parser.cc"
    break;

  case 78: // Exp: Exp LB Exp RB
#line 613 "parser.yy"
                    {
        struct Node* new_node = construct_node(yystack_[3].location.begin.line,"Exp",non_end);
        struct Node* LB_node = construct_node(yystack_[2].location.begin.line,"LB",end);
        struct Node* RB_node = construct_node(yystack_[0].location.begin.line,"RB",end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[3].value.as < Node* > ());
        add_child(yylhs.value.as < Node* > (),LB_node);
        add_child(yylhs.value.as < Node* > (),yystack_[1].value.as < Node* > ());
        add_child(yylhs.value.as < Node* > (),RB_node);
    }
#line 1805 "/home/compiler/build/parser.cc"
    break;

  case 79: // Exp: Exp LB error RB
#line 624 "parser.yy"
                      {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[3].location.begin.line, "Wrong expression");}
#line 1811 "/home/compiler/build/parser.cc"
    break;

  case 80: // Exp: Exp DOT ID
#line 625 "parser.yy"
                 {
        struct Node* new_node = construct_node(yystack_[2].location.begin.line,"Exp",non_end);
        struct Node* DOT_node = construct_node(yystack_[1].location.begin.line,"DOT",end);
        struct Node* ID_node = construct_node(yystack_[0].location.begin.line,"ID",string_node);
        ID_node->m_value.type_string = yystack_[0].value.as < std::string > ();
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > ());
        add_child(yylhs.value.as < Node* > (),DOT_node);
        add_child(yylhs.value.as < Node* > (),ID_node);
    }
#line 1827 "/home/compiler/build/parser.cc"
    break;

  case 81: // Exp: ID
#line 636 "parser.yy"
         {
        struct Node* new_node = construct_node(yystack_[0].location.begin.line,"Exp",non_end);
        struct Node* ID_node = construct_node(yystack_[0].location.begin.line,"ID",string_node);
        ID_node->m_value.type_string = yystack_[0].value.as < std::string > ();
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),ID_node);
    }
#line 1840 "/home/compiler/build/parser.cc"
    break;

  case 82: // Exp: "int"
#line 644 "parser.yy"
          {
        struct Node* new_node = construct_node(yystack_[0].location.begin.line,"Exp",non_end);
        struct Node* INT_node = construct_node(yystack_[0].location.begin.line,"INT",int_node);
        INT_node->m_value.type_int = yystack_[0].value.as < int > ();
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),INT_node);
    }
#line 1853 "/home/compiler/build/parser.cc"
    break;

  case 83: // Exp: "float"
#line 652 "parser.yy"
            {
        struct Node* new_node = construct_node(yystack_[0].location.begin.line,"Exp",non_end);
        struct Node* FLOAT_node = construct_node(yystack_[0].location.begin.line,"FLOAT",float_node);
        FLOAT_node->m_value.type_float = yystack_[0].value.as < float > ();
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),FLOAT_node);

    }
#line 1867 "/home/compiler/build/parser.cc"
    break;

  case 84: // Exp: error RP
#line 661 "parser.yy"
               {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[1].location.begin.line, "Wrong expression");}
#line 1873 "/home/compiler/build/parser.cc"
    break;

  case 85: // Args: Exp COMMA Args
#line 663 "parser.yy"
                      {
    struct Node* new_node = construct_node(yystack_[2].location.begin.line,"Args",non_end);
    struct Node* COMMA_node = construct_node(yystack_[1].location.begin.line,"COMMA",end);
    yylhs.value.as < Node* > () = new_node;
    
    add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > ());
    add_child(yylhs.value.as < Node* > (),COMMA_node);
    add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > ());
}
#line 1887 "/home/compiler/build/parser.cc"
    break;

  case 86: // Args: Exp
#line 672 "parser.yy"
          {
        struct Node* new_node = construct_node(yystack_[0].location.begin.line,"Args",non_end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > ());
    }
#line 1898 "/home/compiler/build/parser.cc"
    break;


#line 1902 "/home/compiler/build/parser.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      yy_lac_discard_ ("error recovery");
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    static const char *const yy_sname[] =
    {
    "end of file", "error", "invalid token", "int", "float", "ID", "TYPE",
  "SEMI", "COMMA", "ASSIGNOP", "RELOP", "PLUS", "MINUS", "STAR", "DIV",
  "AND", "OR", "DOT", "NOT", "LP", "RP", "LB", "RB", "LC", "RC", "STRUCT",
  "RETURN", "IF", "ELSE", "WHILE", "LOWER_THAN_ELSE", "$accept", "Program",
  "ExtDefList", "ExtDef", "ExtDecList", "Specifier", "StructSpecifier",
  "OptTag", "Tag", "VarDec", "FunDec", "VarList", "ParamDec", "CompSt",
  "StmtList", "Stmt", "DefList", "Def", "DecList", "Dec", "Exp", "Args", YY_NULLPTR
    };
    return yy_sname[yysymbol];
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

#if YYDEBUG
    // Execute LAC once. We don't care if it is successful, we
    // only do it for the sake of debugging output.
    if (!yyparser_.yy_lac_established_)
      yyparser_.yy_lac_check_ (yyla_.kind ());
#endif

    for (int yyx = 0; yyx < YYNTOKENS; ++yyx)
      {
        symbol_kind_type yysym = YY_CAST (symbol_kind_type, yyx);
        if (yysym != symbol_kind::S_YYerror
            && yysym != symbol_kind::S_YYUNDEF
            && yyparser_.yy_lac_check_ (yysym))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
      }
    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }




  bool
  parser::yy_lac_check_ (symbol_kind_type yytoken) const
  {
    // Logically, the yylac_stack's lifetime is confined to this function.
    // Clear it, to get rid of potential left-overs from previous call.
    yylac_stack_.clear ();
    // Reduce until we encounter a shift and thereby accept the token.
#if YYDEBUG
    YYCDEBUG << "LAC: checking lookahead " << symbol_name (yytoken) << ':';
#endif
    std::ptrdiff_t lac_top = 0;
    while (true)
      {
        state_type top_state = (yylac_stack_.empty ()
                                ? yystack_[lac_top].state
                                : yylac_stack_.back ());
        int yyrule = yypact_[+top_state];
        if (yy_pact_value_is_default_ (yyrule)
            || (yyrule += yytoken) < 0 || yylast_ < yyrule
            || yycheck_[yyrule] != yytoken)
          {
            // Use the default action.
            yyrule = yydefact_[+top_state];
            if (yyrule == 0)
              {
                YYCDEBUG << " Err\n";
                return false;
              }
          }
        else
          {
            // Use the action from yytable.
            yyrule = yytable_[yyrule];
            if (yy_table_value_is_error_ (yyrule))
              {
                YYCDEBUG << " Err\n";
                return false;
              }
            if (0 < yyrule)
              {
                YYCDEBUG << " S" << yyrule << '\n';
                return true;
              }
            yyrule = -yyrule;
          }
        // By now we know we have to simulate a reduce.
        YYCDEBUG << " R" << yyrule - 1;
        // Pop the corresponding number of values from the stack.
        {
          std::ptrdiff_t yylen = yyr2_[yyrule];
          // First pop from the LAC stack as many tokens as possible.
          std::ptrdiff_t lac_size = std::ptrdiff_t (yylac_stack_.size ());
          if (yylen < lac_size)
            {
              yylac_stack_.resize (std::size_t (lac_size - yylen));
              yylen = 0;
            }
          else if (lac_size)
            {
              yylac_stack_.clear ();
              yylen -= lac_size;
            }
          // Only afterwards look at the main stack.
          // We simulate popping elements by incrementing lac_top.
          lac_top += yylen;
        }
        // Keep top_state in sync with the updated stack.
        top_state = (yylac_stack_.empty ()
                     ? yystack_[lac_top].state
                     : yylac_stack_.back ());
        // Push the resulting state of the reduction.
        state_type state = yy_lr_goto_state_ (top_state, yyr1_[yyrule]);
        YYCDEBUG << " G" << int (state);
        yylac_stack_.push_back (state);
      }
  }

  // Establish the initial context if no initial context currently exists.
  bool
  parser::yy_lac_establish_ (symbol_kind_type yytoken)
  {
    /* Establish the initial context for the current lookahead if no initial
       context is currently established.

       We define a context as a snapshot of the parser stacks.  We define
       the initial context for a lookahead as the context in which the
       parser initially examines that lookahead in order to select a
       syntactic action.  Thus, if the lookahead eventually proves
       syntactically unacceptable (possibly in a later context reached via a
       series of reductions), the initial context can be used to determine
       the exact set of tokens that would be syntactically acceptable in the
       lookahead's place.  Moreover, it is the context after which any
       further semantic actions would be erroneous because they would be
       determined by a syntactically unacceptable token.

       yy_lac_establish_ should be invoked when a reduction is about to be
       performed in an inconsistent state (which, for the purposes of LAC,
       includes consistent states that don't know they're consistent because
       their default reductions have been disabled).

       For parse.lac=full, the implementation of yy_lac_establish_ is as
       follows.  If no initial context is currently established for the
       current lookahead, then check if that lookahead can eventually be
       shifted if syntactic actions continue from the current context.  */
    if (yy_lac_established_)
      return true;
    else
      {
#if YYDEBUG
        YYCDEBUG << "LAC: initial context established for "
                 << symbol_name (yytoken) << '\n';
#endif
        yy_lac_established_ = true;
        return yy_lac_check_ (yytoken);
      }
  }

  // Discard any previous initial lookahead context.
  void
  parser::yy_lac_discard_ (const char* event)
  {
   /* Discard any previous initial lookahead context because of Event,
      which may be a lookahead change or an invalidation of the currently
      established initial context for the current lookahead.

      The most common example of a lookahead change is a shift.  An example
      of both cases is syntax error recovery.  That is, a syntax error
      occurs when the lookahead is syntactically erroneous for the
      currently established initial context, so error recovery manipulates
      the parser stacks to try to find a new initial context in which the
      current lookahead is syntactically acceptable.  If it fails to find
      such a context, it discards the lookahead.  */
    if (yy_lac_established_)
      {
        YYCDEBUG << "LAC: initial context discarded due to "
                 << event << '\n';
        yy_lac_established_ = false;
      }
  }


  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
         In the first two cases, it might appear that the current syntax
         error should have been detected in the previous state when
         yy_lac_check was invoked.  However, at that time, there might
         have been a different syntax error that discarded a different
         initial context during error recovery, leaving behind the
         current lookahead.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -61;

  const signed char parser::yytable_ninf_ = -44;

  const short
  parser::yypact_[] =
  {
      50,   -61,    10,    21,   -61,    50,   110,   -61,    54,    56,
     -61,   -61,   -61,   -61,     8,   -61,    94,     2,     7,    57,
       6,   -61,    12,    15,    68,    68,   -61,    78,    84,    66,
      68,   -61,   101,   100,   128,   -61,   -61,   -61,   115,   116,
     101,    95,    95,   -61,    67,   135,   138,   136,   140,   -61,
     -61,   141,   -61,    50,   -61,   -61,    41,   -61,   -61,   144,
     184,   189,   208,   213,   146,   147,   -61,   154,    95,   143,
     155,   218,   -61,   101,   -61,   -61,   -61,   -61,   -61,   179,
     148,    91,   148,    34,   148,   363,    42,   160,   237,   237,
     -61,   -61,   -61,   -61,   242,   247,   266,   271,   276,   295,
     300,   305,   181,   324,   -61,   148,   402,   -61,   148,   -61,
     336,    83,   -61,   -61,   -61,   -61,   148,   376,   389,   148,
     402,   148,   413,   148,    91,   148,    91,   148,    34,   148,
      34,   148,   320,   148,   118,   -61,    32,   349,   237,   -61,
     -61,   122,   122,   -61,   -61,   -61,   167,   -61,   122,   -61
  };

  const signed char
  parser::yydefact_[] =
  {
       4,    12,    18,     0,     2,     4,     0,    13,    19,     0,
      15,     1,     3,     8,    20,     6,     0,     9,     0,     0,
       0,     5,     0,     0,     0,     0,     7,     0,     0,     0,
       0,    24,     0,     0,    26,    11,    20,    10,     0,     0,
       0,     0,     0,    16,    49,     0,    47,     0,     0,    14,
      42,    27,    23,     0,    22,    21,     0,    82,    83,    81,
       0,     0,     0,     0,     0,     0,    35,     0,     0,     0,
       0,     0,    45,     0,    46,    44,    25,    33,    84,     0,
      71,    70,    73,    72,    69,     0,     0,     0,     0,     0,
      29,    30,    34,    32,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    28,    51,    50,    48,    77,    76,
      86,     0,    68,    38,    37,    36,     0,     0,     0,    53,
      52,    59,    58,    61,    60,    63,    62,    65,    64,    67,
      66,    55,    54,    57,    56,    80,     0,     0,     0,    75,
      74,     0,     0,    79,    78,    85,    39,    41,     0,    40
  };

  const short
  parser::yypgoto_[] =
  {
     -61,   -61,   195,   -61,   182,     4,   -61,   -61,   -61,     0,
     -61,   152,   -61,   188,   -35,   -32,    -5,   -61,   -23,   -61,
     -60,    72
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     3,     4,     5,    16,    28,     7,     9,    10,    44,
      18,    33,    34,    66,    67,    68,    41,    30,    45,    46,
      69,   111
  };

  const short
  parser::yytable_[] =
  {
      81,    83,    85,    87,     6,    48,    17,    70,    24,     6,
      22,   106,     1,    35,    29,     8,    38,    36,    39,   110,
      42,    11,    17,    23,    32,    50,    31,    20,   117,   118,
      25,     2,    51,    91,   120,   122,   124,   126,   128,   130,
     132,   134,    40,   137,   -43,   -43,   -43,     1,    77,   113,
     107,   102,    78,   -43,   143,   103,     1,    32,    27,   -43,
     -43,    78,    78,     1,   -43,   -43,     2,   -43,   -43,    40,
     -43,   -43,   -43,   -43,     1,     2,    71,   -17,   110,    19,
     -43,   -43,     2,    36,   139,    47,   -43,   -43,    23,    36,
      49,   -43,   -43,     2,   -43,   -43,    56,   -43,    57,    58,
      59,    21,    43,   140,    98,    99,    36,    60,   102,   146,
     147,    13,   103,    61,    62,    14,   149,    15,    25,   -31,
      52,    63,    64,    56,    65,    57,    58,    59,    95,    96,
      97,    98,    99,   100,    60,   102,    53,    54,    55,   103,
      61,    62,    72,    74,    92,    25,    73,    75,    63,    64,
      93,    65,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   114,    23,    79,   103,    88,    89,   115,    78,    94,
      95,    96,    97,    98,    99,   100,   101,   102,    90,   104,
     108,   103,    57,    58,    59,    80,   135,    57,    58,    59,
      82,    60,    57,    58,    59,   148,    60,    61,    62,   109,
      12,    60,    61,    62,    37,    76,    26,    61,    62,    84,
     145,    57,    58,    59,    86,     0,    57,    58,    59,   105,
      60,    57,    58,    59,     0,    60,    61,    62,     0,     0,
      60,    61,    62,     0,     0,     0,    61,    62,   116,     0,
      57,    58,    59,   119,     0,    57,    58,    59,   121,    60,
      57,    58,    59,     0,    60,    61,    62,     0,     0,    60,
      61,    62,     0,     0,     0,    61,    62,   123,     0,    57,
      58,    59,   125,     0,    57,    58,    59,   127,    60,    57,
      58,    59,     0,    60,    61,    62,     0,     0,    60,    61,
      62,     0,     0,     0,    61,    62,   129,     0,    57,    58,
      59,   131,     0,    57,    58,    59,   133,    60,    57,    58,
      59,     0,    60,    61,    62,     0,     0,    60,    61,    62,
       0,     0,     0,    61,    62,   136,     0,    57,    58,    59,
      95,    96,    97,    98,    99,     0,    60,   102,     0,     0,
       0,   103,    61,    62,   138,    94,    95,    96,    97,    98,
      99,   100,   101,   102,     0,     0,     0,   103,    94,    95,
      96,    97,    98,    99,   100,   101,   102,     0,     0,     0,
     103,   144,    94,    95,    96,    97,    98,    99,   100,   101,
     102,     0,     0,   112,   103,    94,    95,    96,    97,    98,
      99,   100,   101,   102,     0,     0,   141,   103,    94,    95,
      96,    97,    98,    99,   100,   101,   102,     0,     0,   142,
     103,    94,    95,    96,    97,    98,    99,   100,   101,   102,
       0,     0,     0,   103,    96,    97,    98,    99,     0,     0,
     102,     0,     0,     0,   103
  };

  const short
  parser::yycheck_[] =
  {
      60,    61,    62,    63,     0,    28,     6,    42,     1,     5,
       8,    71,     6,     1,    19,     5,     1,     5,     3,    79,
      25,     0,    22,    21,    20,    30,    20,    19,    88,    89,
      23,    25,    32,    68,    94,    95,    96,    97,    98,    99,
     100,   101,     1,   103,     3,     4,     5,     6,     7,     7,
      73,    17,    20,    12,    22,    21,     6,    53,     1,    18,
      19,    20,    20,     6,    23,    24,    25,    26,    27,     1,
      29,     3,     4,     5,     6,    25,     9,    23,   138,    23,
      12,    24,    25,     5,     1,     1,    18,    19,    21,     5,
      24,    23,    24,    25,    26,    27,     1,    29,     3,     4,
       5,     7,    24,    20,    13,    14,     5,    12,    17,   141,
     142,     1,    21,    18,    19,     5,   148,     7,    23,    24,
      20,    26,    27,     1,    29,     3,     4,     5,    10,    11,
      12,    13,    14,    15,    12,    17,     8,    22,    22,    21,
      18,    19,     7,     7,     1,    23,     8,     7,    26,    27,
       7,    29,     9,    10,    11,    12,    13,    14,    15,    16,
      17,     1,    21,    19,    21,    19,    19,     7,    20,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    24,    24,
       1,    21,     3,     4,     5,     1,     5,     3,     4,     5,
       1,    12,     3,     4,     5,    28,    12,    18,    19,    20,
       5,    12,    18,    19,    22,    53,    18,    18,    19,     1,
     138,     3,     4,     5,     1,    -1,     3,     4,     5,     1,
      12,     3,     4,     5,    -1,    12,    18,    19,    -1,    -1,
      12,    18,    19,    -1,    -1,    -1,    18,    19,     1,    -1,
       3,     4,     5,     1,    -1,     3,     4,     5,     1,    12,
       3,     4,     5,    -1,    12,    18,    19,    -1,    -1,    12,
      18,    19,    -1,    -1,    -1,    18,    19,     1,    -1,     3,
       4,     5,     1,    -1,     3,     4,     5,     1,    12,     3,
       4,     5,    -1,    12,    18,    19,    -1,    -1,    12,    18,
      19,    -1,    -1,    -1,    18,    19,     1,    -1,     3,     4,
       5,     1,    -1,     3,     4,     5,     1,    12,     3,     4,
       5,    -1,    12,    18,    19,    -1,    -1,    12,    18,    19,
      -1,    -1,    -1,    18,    19,     1,    -1,     3,     4,     5,
      10,    11,    12,    13,    14,    -1,    12,    17,    -1,    -1,
      -1,    21,    18,    19,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    21,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    -1,
      21,    22,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    -1,    20,    21,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    -1,    20,    21,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    20,
      21,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    21,    11,    12,    13,    14,    -1,    -1,
      17,    -1,    -1,    -1,    21
  };

  const signed char
  parser::yystos_[] =
  {
       0,     6,    25,    32,    33,    34,    36,    37,     5,    38,
      39,     0,    33,     1,     5,     7,    35,    40,    41,    23,
      19,     7,     8,    21,     1,    23,    44,     1,    36,    47,
      48,    20,    36,    42,    43,     1,     5,    35,     1,     3,
       1,    47,    47,    24,    40,    49,    50,     1,    49,    24,
      47,    40,    20,     8,    22,    22,     1,     3,     4,     5,
      12,    18,    19,    26,    27,    29,    44,    45,    46,    51,
      45,     9,     7,     8,     7,     7,    42,     7,    20,    19,
       1,    51,     1,    51,     1,    51,     1,    51,    19,    19,
      24,    45,     1,     7,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    21,    24,     1,    51,    49,     1,    20,
      51,    52,    20,     7,     1,     7,     1,    51,    51,     1,
      51,     1,    51,     1,    51,     1,    51,     1,    51,     1,
      51,     1,    51,     1,    51,     5,     1,    51,     8,     1,
      20,    20,    20,    22,    22,    52,    46,    46,    28,    46
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    31,    32,    33,    33,    34,    34,    34,    34,    35,
      35,    35,    36,    36,    37,    37,    37,    38,    38,    39,
      40,    40,    40,    41,    41,    42,    42,    43,    44,    44,
      45,    45,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    47,    47,    48,    48,    48,    49,    49,    50,
      50,    50,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    52,    52
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     0,     3,     2,     3,     2,     1,
       3,     3,     1,     1,     5,     2,     5,     1,     0,     1,
       1,     4,     4,     4,     3,     3,     1,     2,     4,     4,
       2,     0,     2,     2,     2,     1,     3,     3,     3,     5,
       7,     5,     2,     0,     3,     3,     3,     1,     3,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     2,     2,     4,     4,     3,     3,     4,     4,
       3,     1,     1,     1,     2,     3,     1
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   152,   152,   158,   164,   168,   176,   183,   190,   192,
     197,   205,   207,   214,   220,   232,   239,   241,   248,   252,
     261,   268,   280,   282,   294,   306,   314,   320,   328,   338,
     340,   346,   350,   357,   358,   359,   364,   374,   375,   376,
     389,   405,   420,   427,   431,   440,   441,   443,   449,   459,
     465,   474,   477,   486,   487,   496,   497,   506,   507,   516,
     517,   526,   527,   536,   537,   546,   547,   556,   557,   567,
     568,   576,   577,   585,   586,   599,   600,   612,   613,   624,
     625,   636,   644,   652,   661,   663,   672
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 2614 "/home/compiler/build/parser.cc"

#line 681 "parser.yy"


void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
