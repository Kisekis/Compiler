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
#line 28 "parser.yy"

  #include "driver.hh"
  #include "memory"
  #include "ast.hh"
  #include "node.hh"
  std::unique_ptr<AST> ast;

#line 54 "/home/compiler/build/parser.cc"


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
#line 146 "/home/compiler/build/parser.cc"

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
      case symbol_kind::S_RELOP: // RELOP
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
      case symbol_kind::S_RELOP: // RELOP
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
      case symbol_kind::S_RELOP: // RELOP
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
      case symbol_kind::S_RELOP: // RELOP
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
#line 45 "parser.yy"
                 { yyo << yysym.value.template as < int > (); }
#line 450 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_FLOAT: // "float"
#line 45 "parser.yy"
                 { yyo << yysym.value.template as < float > (); }
#line 456 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_ID: // ID
#line 45 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 462 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_TYPE: // TYPE
#line 45 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 468 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_RELOP: // RELOP
#line 45 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 474 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_Program: // Program
#line 45 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 480 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_ExtDefList: // ExtDefList
#line 45 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 486 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_ExtDef: // ExtDef
#line 45 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 492 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_ExtDecList: // ExtDecList
#line 45 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 498 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_Specifier: // Specifier
#line 45 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 504 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_StructSpecifier: // StructSpecifier
#line 45 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 510 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_OptTag: // OptTag
#line 45 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 516 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_Tag: // Tag
#line 45 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 522 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_VarDec: // VarDec
#line 45 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 528 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_FunDec: // FunDec
#line 45 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 534 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_VarList: // VarList
#line 45 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 540 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_ParamDec: // ParamDec
#line 45 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 546 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_CompSt: // CompSt
#line 45 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 552 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_StmtList: // StmtList
#line 45 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 558 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_Stmt: // Stmt
#line 45 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 564 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_DefList: // DefList
#line 45 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 570 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_Def: // Def
#line 45 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 576 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_DecList: // DecList
#line 45 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 582 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_Dec: // Dec
#line 45 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 588 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_Exp: // Exp
#line 45 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 594 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_Args: // Args
#line 45 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 600 "/home/compiler/build/parser.cc"
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
      case symbol_kind::S_RELOP: // RELOP
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
#line 68 "parser.yy"
                    {
    Node* new_node = new Node(yystack_[0].location.begin.line,"Program",Node::non_end,1);
    ast = std::make_unique<AST>(new_node);
    yylhs.value.as < Node* > () = new_node;
    add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > (),1);
}
#line 906 "/home/compiler/build/parser.cc"
    break;

  case 3: // ExtDefList: ExtDef ExtDefList
#line 74 "parser.yy"
                              {
    struct Node* new_node = new Node(yystack_[1].location.begin.line,"ExtDefList",Node::non_end,1);
    yylhs.value.as < Node* > () = new_node;
    add_child(yylhs.value.as < Node* > (),yystack_[1].value.as < Node* > (),1);
    add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > (),2);
}
#line 917 "/home/compiler/build/parser.cc"
    break;

  case 4: // ExtDefList: %empty
#line 80 "parser.yy"
               {
        yylhs.value.as < Node* > () = NULL;
    }
#line 925 "/home/compiler/build/parser.cc"
    break;

  case 5: // ExtDef: Specifier ExtDecList SEMI
#line 84 "parser.yy"
                                  {
    struct Node* new_node = new Node(yystack_[2].location.begin.line,"ExtDef",Node::non_end,1);
    struct Node* SEMI_node = new Node(yystack_[0].location.begin.line,"SEMI",Node::end);
    yylhs.value.as < Node* > () = new_node;
    add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),1);
    add_child(yylhs.value.as < Node* > (),yystack_[1].value.as < Node* > (),2);
    add_child(yylhs.value.as < Node* > (),SEMI_node,3);
}
#line 938 "/home/compiler/build/parser.cc"
    break;

  case 6: // ExtDef: Specifier SEMI
#line 92 "parser.yy"
                     {
        struct Node* new_node = new Node(yystack_[1].location.begin.line,"ExtDef",Node::non_end,2);
        struct Node* SEMI_node = new Node(yystack_[0].location.begin.line,"SEMI",Node::end);
        yylhs.value.as < Node* > () = new_node;
        add_child(yylhs.value.as < Node* > (),yystack_[1].value.as < Node* > (),1);
        add_child(yylhs.value.as < Node* > (),SEMI_node,2);
    }
#line 950 "/home/compiler/build/parser.cc"
    break;

  case 7: // ExtDef: Specifier FunDec CompSt
#line 99 "parser.yy"
                              {
        struct Node* new_node = new Node(yystack_[2].location.begin.line,"ExtDef",Node::non_end,3);
        yylhs.value.as < Node* > () = new_node;
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),1);
        add_child(yylhs.value.as < Node* > (),yystack_[1].value.as < Node* > (),2);
        add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > (),3);
    }
#line 962 "/home/compiler/build/parser.cc"
    break;

  case 8: // ExtDef: Specifier error
#line 106 "parser.yy"
                      {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[1].location.begin.line, "delcaration error");}
#line 968 "/home/compiler/build/parser.cc"
    break;

  case 9: // ExtDecList: VarDec
#line 108 "parser.yy"
                    {
    struct Node* new_node = new Node(yystack_[0].location.begin.line,"ExtDecList",Node::non_end,1);
    yylhs.value.as < Node* > () = new_node;
    add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > (),1);
}
#line 978 "/home/compiler/build/parser.cc"
    break;

  case 10: // ExtDecList: VarDec COMMA ExtDecList
#line 113 "parser.yy"
                              {
        struct Node* new_node = new Node(yystack_[2].location.begin.line,"ExtDecList",Node::non_end,2);
        struct Node* COMMA_node = new Node(yystack_[1].location.begin.line,"COMMA",Node::end);
        yylhs.value.as < Node* > () = new_node;
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),1);
        add_child(yylhs.value.as < Node* > (),COMMA_node,2);
        add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > (),3);
    }
#line 991 "/home/compiler/build/parser.cc"
    break;

  case 11: // ExtDecList: VarDec COMMA error
#line 121 "parser.yy"
                         {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "delcaration error");}
#line 997 "/home/compiler/build/parser.cc"
    break;

  case 12: // Specifier: TYPE
#line 123 "parser.yy"
                 {
    struct Node* new_node = new Node(yystack_[0].location.begin.line,"Specifier",Node::non_end,1);
    struct Node* TYPE_node = new Node(yystack_[0].location.begin.line,"TYPE",Node::string_node);
    TYPE_node->m_value = yystack_[0].value.as < std::string > ();
    yylhs.value.as < Node* > () = new_node;
    add_child(yylhs.value.as < Node* > (),TYPE_node,1);
}
#line 1009 "/home/compiler/build/parser.cc"
    break;

  case 13: // Specifier: StructSpecifier
#line 130 "parser.yy"
                      {
        struct Node* new_node = new Node(yystack_[0].location.begin.line,"Specifier",Node::non_end,2);
        yylhs.value.as < Node* > () = new_node;
        add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > (),1);
    }
#line 1019 "/home/compiler/build/parser.cc"
    break;

  case 14: // StructSpecifier: STRUCT OptTag LC DefList RC
#line 136 "parser.yy"
                                              {
    struct Node* new_node = new Node(yystack_[4].location.begin.line,"StructSpecifier",Node::non_end,1);
    yylhs.value.as < Node* > () = new_node;
    struct Node* STRUCT_node = new Node(yystack_[4].location.begin.line,"STRUCT",Node::end);
    struct Node* LC_node = new Node(yystack_[2].location.begin.line,"LC",Node::end);
    struct Node* RC_node = new Node(yystack_[0].location.begin.line,"RC",Node::end);
    add_child(yylhs.value.as < Node* > (),STRUCT_node,1);
    add_child(yylhs.value.as < Node* > (),yystack_[3].value.as < Node* > (),2);
    add_child(yylhs.value.as < Node* > (),LC_node,3);
    add_child(yylhs.value.as < Node* > (),yystack_[1].value.as < Node* > (),4);
    add_child(yylhs.value.as < Node* > (),RC_node,5);
}
#line 1036 "/home/compiler/build/parser.cc"
    break;

  case 15: // StructSpecifier: STRUCT Tag
#line 148 "parser.yy"
                 {
        struct Node* new_node = new Node(yystack_[1].location.begin.line,"StructSpecifier",Node::non_end,2);
        yylhs.value.as < Node* > () = new_node;
        struct Node* STRUCT_node = new Node(yystack_[1].location.begin.line,"STRUCT",Node::end);
        add_child(yylhs.value.as < Node* > (),STRUCT_node,1);
        add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > (),2);
    }
#line 1048 "/home/compiler/build/parser.cc"
    break;

  case 16: // StructSpecifier: STRUCT OptTag LC error RC
#line 155 "parser.yy"
                               {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[4].location.begin.line, "struct error");}
#line 1054 "/home/compiler/build/parser.cc"
    break;

  case 17: // OptTag: ID
#line 157 "parser.yy"
           {
    struct Node* new_node = new Node(yystack_[0].location.begin.line,"OptTag",Node::non_end,1);
    yylhs.value.as < Node* > () = new_node;
    struct Node* ID_node = new Node(yystack_[0].location.begin.line,"ID",Node::string_node);
    ID_node->m_value = yystack_[0].value.as < std::string > ();
    add_child(yylhs.value.as < Node* > (),ID_node,1);
}
#line 1066 "/home/compiler/build/parser.cc"
    break;

  case 18: // OptTag: %empty
#line 164 "parser.yy"
               {
        yylhs.value.as < Node* > () = NULL;
    }
#line 1074 "/home/compiler/build/parser.cc"
    break;

  case 19: // Tag: ID
#line 168 "parser.yy"
        {
    struct Node* new_node = new Node(yystack_[0].location.begin.line,"Tag",Node::non_end,1);
    yylhs.value.as < Node* > () = new_node;
    struct Node* ID_node = new Node(yystack_[0].location.begin.line,"ID",Node::string_node);
    ID_node->m_value = yystack_[0].value.as < std::string > ();
    add_child(yylhs.value.as < Node* > (),ID_node,1);
}
#line 1086 "/home/compiler/build/parser.cc"
    break;

  case 20: // VarDec: ID
#line 177 "parser.yy"
            {
    struct Node* new_node = new Node(yystack_[0].location.begin.line,"VarDec",Node::non_end,1);
    yylhs.value.as < Node* > () = new_node;
    struct Node* ID_node = new Node(yystack_[0].location.begin.line,"ID",Node::string_node);
    ID_node->m_value = yystack_[0].value.as < std::string > ();
    add_child(yylhs.value.as < Node* > (),ID_node,1);
}
#line 1098 "/home/compiler/build/parser.cc"
    break;

  case 21: // VarDec: VarDec LB "int" RB
#line 184 "parser.yy"
                       {
        struct Node* new_node = new Node(yystack_[3].location.begin.line,"VarDec",Node::non_end,2);
        yylhs.value.as < Node* > () = new_node;
        struct Node* LB_node = new Node(yystack_[2].location.begin.line,"LB",Node::end);
        struct Node* int_node = new Node(yystack_[1].location.begin.line,"INT",Node::int_node);
        int_node->m_value = yystack_[1].value.as < int > ();
        struct Node* RB_node = new Node(yystack_[0].location.begin.line,"RB",Node::end);
        add_child(yylhs.value.as < Node* > (),yystack_[3].value.as < Node* > (),1);
        add_child(yylhs.value.as < Node* > (), LB_node,2);
        add_child(yylhs.value.as < Node* > (),int_node,3);
        add_child(yylhs.value.as < Node* > (),RB_node,4);
    }
#line 1115 "/home/compiler/build/parser.cc"
    break;

  case 22: // VarDec: VarDec LB error RB
#line 196 "parser.yy"
                         {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[3].location.begin.line, "wrong variable declaration");}
#line 1121 "/home/compiler/build/parser.cc"
    break;

  case 23: // FunDec: ID LP VarList RP
#line 198 "parser.yy"
                          {
    struct Node* new_node = new Node(yystack_[3].location.begin.line,"FunDec",Node::non_end,1);
    yylhs.value.as < Node* > () = new_node;
    struct Node* ID_node = new Node(yystack_[3].location.begin.line,"ID",Node::string_node);
    ID_node->m_value = yystack_[3].value.as < std::string > ();
    struct Node* LP_node = new Node(yystack_[2].location.begin.line,"LP",Node::end);
    struct Node* RP_node = new Node(yystack_[0].location.begin.line,"RP",Node::end);
    add_child(yylhs.value.as < Node* > (),ID_node,1);
    add_child(yylhs.value.as < Node* > (), LP_node,2);
    add_child(yylhs.value.as < Node* > (),yystack_[1].value.as < Node* > (),3);
    add_child(yylhs.value.as < Node* > (),RP_node,4);
}
#line 1138 "/home/compiler/build/parser.cc"
    break;

  case 24: // FunDec: ID LP RP
#line 210 "parser.yy"
               {
        struct Node* new_node = new Node(yystack_[2].location.begin.line,"FunDec",Node::non_end,2);
        yylhs.value.as < Node* > () = new_node;
        struct Node* ID_node = new Node(yystack_[2].location.begin.line,"ID",Node::string_node);
        ID_node->m_value = yystack_[2].value.as < std::string > ();
        struct Node* LP_node = new Node(yystack_[1].location.begin.line,"LP",Node::end);
        struct Node* RP_node = new Node(yystack_[0].location.begin.line,"RP",Node::end);
        add_child(yylhs.value.as < Node* > (),ID_node,1);
        add_child(yylhs.value.as < Node* > (), LP_node,2);
        add_child(yylhs.value.as < Node* > (),RP_node,3);
    }
#line 1154 "/home/compiler/build/parser.cc"
    break;

  case 25: // VarList: ParamDec COMMA VarList
#line 222 "parser.yy"
                                 {
    struct Node* new_node = new Node(yystack_[2].location.begin.line,"VarList",Node::non_end,1);
    yylhs.value.as < Node* > () = new_node;
    struct Node* COMMA_node = new Node(yystack_[1].location.begin.line,"COMMA",Node::end);
    add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),1);
    add_child(yylhs.value.as < Node* > (), COMMA_node,2);
    add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > (),3);
}
#line 1167 "/home/compiler/build/parser.cc"
    break;

  case 26: // VarList: ParamDec
#line 230 "parser.yy"
               {
        struct Node* new_node = new Node(yystack_[0].location.begin.line,"VarList",Node::non_end,2);
        yylhs.value.as < Node* > () = new_node;
        add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > (),1);
    }
#line 1177 "/home/compiler/build/parser.cc"
    break;

  case 27: // ParamDec: Specifier VarDec
#line 236 "parser.yy"
                            {
    struct Node* new_node = new Node(yystack_[1].location.begin.line,"ParamDec",Node::non_end,1);
    yylhs.value.as < Node* > () = new_node;
    add_child(yylhs.value.as < Node* > (),yystack_[1].value.as < Node* > (),1);
    add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > (),2);
}
#line 1188 "/home/compiler/build/parser.cc"
    break;

  case 28: // CompSt: LC DefList StmtList RC
#line 244 "parser.yy"
                                {
    struct Node* new_node = new Node(yystack_[3].location.begin.line,"CompSt",Node::non_end,1);
    yylhs.value.as < Node* > () = new_node;
    struct Node* LC_node = new Node(yystack_[3].location.begin.line,"LC",Node::end);
    struct Node* RC_node = new Node(yystack_[0].location.begin.line,"RC",Node::end);
    add_child(yylhs.value.as < Node* > (),LC_node,1);
    add_child(yylhs.value.as < Node* > (), yystack_[2].value.as < Node* > (),2);
    add_child(yylhs.value.as < Node* > (),yystack_[1].value.as < Node* > (),3);
    add_child(yylhs.value.as < Node* > (),RC_node,4);
}
#line 1203 "/home/compiler/build/parser.cc"
    break;

  case 29: // CompSt: error DefList StmtList RC
#line 254 "parser.yy"
                                {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[3].location.begin.line, "Missing {");}
#line 1209 "/home/compiler/build/parser.cc"
    break;

  case 30: // StmtList: Stmt StmtList
#line 256 "parser.yy"
                         {
    struct Node* new_node = new Node(yystack_[1].location.begin.line,"StmtList",Node::non_end,1);
    yylhs.value.as < Node* > () = new_node;
    add_child(yylhs.value.as < Node* > (), yystack_[1].value.as < Node* > (),1);
    add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > (),2);
}
#line 1220 "/home/compiler/build/parser.cc"
    break;

  case 31: // StmtList: %empty
#line 262 "parser.yy"
                {
        yylhs.value.as < Node* > () = NULL;
    }
#line 1228 "/home/compiler/build/parser.cc"
    break;

  case 32: // Stmt: Exp SEMI
#line 266 "parser.yy"
               {
    struct Node* new_node = new Node(yystack_[1].location.begin.line,"Stmt",Node::non_end,1);
    struct Node* SEMI_node = new Node(yystack_[0].location.begin.line,"SEMI",Node::end);
    yylhs.value.as < Node* > () = new_node;
    add_child(yylhs.value.as < Node* > (), yystack_[1].value.as < Node* > (),1);
    add_child(yylhs.value.as < Node* > (),SEMI_node,2);
}
#line 1240 "/home/compiler/build/parser.cc"
    break;

  case 33: // Stmt: error SEMI
#line 273 "parser.yy"
                 {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[1].location.begin.line, "wrong expression");}
#line 1246 "/home/compiler/build/parser.cc"
    break;

  case 34: // Stmt: Exp error
#line 274 "parser.yy"
                {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[1].location.begin.line, "Missing ;");}
#line 1252 "/home/compiler/build/parser.cc"
    break;

  case 35: // Stmt: CompSt
#line 275 "parser.yy"
            {
        struct Node* new_node = new Node(yystack_[0].location.begin.line,"Stmt",Node::non_end,2);
        yylhs.value.as < Node* > () = new_node;
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > (),1);
    }
#line 1262 "/home/compiler/build/parser.cc"
    break;

  case 36: // Stmt: RETURN Exp SEMI
#line 280 "parser.yy"
                      {
        struct Node* new_node = new Node(yystack_[2].location.begin.line,"Stmt",Node::non_end,3);
        struct Node* RETURN_node = new Node(yystack_[2].location.begin.line,"RETURN",Node::end);
        struct Node* SEMI_node = new Node(yystack_[0].location.begin.line,"SEMI",Node::end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),RETURN_node,1);
        add_child(yylhs.value.as < Node* > (), yystack_[1].value.as < Node* > (),2);
        add_child(yylhs.value.as < Node* > (),SEMI_node,3);
    }
#line 1277 "/home/compiler/build/parser.cc"
    break;

  case 37: // Stmt: RETURN Exp error
#line 290 "parser.yy"
                       {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Missing ;");}
#line 1283 "/home/compiler/build/parser.cc"
    break;

  case 38: // Stmt: RETURN error SEMI
#line 291 "parser.yy"
                        {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong return expression");}
#line 1289 "/home/compiler/build/parser.cc"
    break;

  case 39: // Stmt: IF LP Exp RP Stmt
#line 292 "parser.yy"
                        {
        struct Node* new_node = new Node(yystack_[4].location.begin.line,"Stmt",Node::non_end,4);
        struct Node* IF_node = new Node(yystack_[4].location.begin.line,"IF",Node::end);
        struct Node* LP_node = new Node(yystack_[3].location.begin.line,"LP",Node::end);
        struct Node* RP_node = new Node(yystack_[1].location.begin.line,"RP",Node::end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),IF_node,1);
        add_child(yylhs.value.as < Node* > (), LP_node,2);
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),3);
        add_child(yylhs.value.as < Node* > (),RP_node,4);
        add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > (),5);
    }
#line 1307 "/home/compiler/build/parser.cc"
    break;

  case 40: // Stmt: IF LP Exp RP Stmt ELSE Stmt
#line 305 "parser.yy"
                                  {
        struct Node* new_node = new Node(yystack_[6].location.begin.line,"Stmt",Node::non_end,5);
        struct Node* IF_node = new Node(yystack_[6].location.begin.line,"IF",Node::end);
        struct Node* LP_node = new Node(yystack_[5].location.begin.line,"LP",Node::end);
        struct Node* RP_node = new Node(yystack_[3].location.begin.line,"RP",Node::end);
        struct Node* ELSE_node = new Node(yystack_[1].location.begin.line,"ELSE",Node::end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),IF_node,1);
        add_child(yylhs.value.as < Node* > (), LP_node,2);
        add_child(yylhs.value.as < Node* > (),yystack_[4].value.as < Node* > (),3);
        add_child(yylhs.value.as < Node* > (),RP_node,4);
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),5);
        add_child(yylhs.value.as < Node* > (),ELSE_node,6);
        add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > (),7);
    }
#line 1328 "/home/compiler/build/parser.cc"
    break;

  case 41: // Stmt: WHILE LP Exp RP Stmt
#line 321 "parser.yy"
                           {
        struct Node* new_node = new Node(yystack_[4].location.begin.line,"Stmt",Node::non_end,6);
        struct Node* WHILE_node = new Node(yystack_[4].location.begin.line,"WHILE",Node::end);
        struct Node* LP_node = new Node(yystack_[3].location.begin.line,"LP",Node::end);
        struct Node* RP_node = new Node(yystack_[1].location.begin.line,"RP",Node::end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),WHILE_node,1);
        add_child(yylhs.value.as < Node* > (), LP_node,2);
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),3);
        add_child(yylhs.value.as < Node* > (),RP_node,4);
        add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > (),5);
    }
#line 1346 "/home/compiler/build/parser.cc"
    break;

  case 42: // DefList: Def DefList
#line 336 "parser.yy"
                      {
    struct Node* new_node = new Node(yystack_[1].location.begin.line,"DefList",Node::non_end,1);
    yylhs.value.as < Node* > () = new_node;
    
    add_child(yylhs.value.as < Node* > (),yystack_[1].value.as < Node* > (),1);
    add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > (),2);
}
#line 1358 "/home/compiler/build/parser.cc"
    break;

  case 43: // DefList: %empty
#line 343 "parser.yy"
               {
        yylhs.value.as < Node* > () = NULL;
    }
#line 1366 "/home/compiler/build/parser.cc"
    break;

  case 44: // Def: Specifier DecList SEMI
#line 347 "parser.yy"
                             {
    struct Node* new_node = new Node(yystack_[2].location.begin.line,"Def",Node::non_end,1);
    struct Node* SEMI_node = new Node(yystack_[0].location.begin.line,"SEMI",Node::end);
    yylhs.value.as < Node* > () = new_node;
    
    add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),1);
    add_child(yylhs.value.as < Node* > (), yystack_[1].value.as < Node* > (),2);
    add_child(yylhs.value.as < Node* > (), SEMI_node,2);
}
#line 1380 "/home/compiler/build/parser.cc"
    break;

  case 45: // Def: error DecList SEMI
#line 356 "parser.yy"
                         {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong declaration");}
#line 1386 "/home/compiler/build/parser.cc"
    break;

  case 46: // Def: Specifier error SEMI
#line 357 "parser.yy"
                           {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong declaration");}
#line 1392 "/home/compiler/build/parser.cc"
    break;

  case 47: // DecList: Dec
#line 359 "parser.yy"
              {
    struct Node* new_node = new Node(yystack_[0].location.begin.line,"DecList",Node::non_end,1);
    yylhs.value.as < Node* > () = new_node;
    
    add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > (),1);
}
#line 1403 "/home/compiler/build/parser.cc"
    break;

  case 48: // DecList: Dec COMMA DecList
#line 365 "parser.yy"
                        {
        struct Node* new_node = new Node(yystack_[2].location.begin.line,"DecList",Node::non_end);
        struct Node* COMMA_node = new Node(yystack_[1].location.begin.line,"COMMA",Node::end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),1);
        add_child(yylhs.value.as < Node* > (), COMMA_node,2);
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > (),3);
    }
#line 1417 "/home/compiler/build/parser.cc"
    break;

  case 49: // Dec: VarDec
#line 375 "parser.yy"
             {
    struct Node* new_node = new Node(yystack_[0].location.begin.line,"Dec",Node::non_end,1);
    yylhs.value.as < Node* > () = new_node;
    
    add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > (),1);
}
#line 1428 "/home/compiler/build/parser.cc"
    break;

  case 50: // Dec: VarDec ASSIGNOP Exp
#line 381 "parser.yy"
                          {
        struct Node* new_node = new Node(yystack_[2].location.begin.line,"Dec",Node::non_end,2);
        struct Node* ASSIGNOP_node = new Node(yystack_[1].location.begin.line,"ASSIGNOP",Node::end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),1);
        add_child(yylhs.value.as < Node* > (), ASSIGNOP_node,2);
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > (),3);
    }
#line 1442 "/home/compiler/build/parser.cc"
    break;

  case 51: // Dec: VarDec ASSIGNOP error
#line 390 "parser.yy"
                            {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong expression");}
#line 1448 "/home/compiler/build/parser.cc"
    break;

  case 52: // Exp: Exp ASSIGNOP Exp
#line 393 "parser.yy"
                      {
    struct Node* new_node = new Node(yystack_[2].location.begin.line,"Exp",Node::non_end,1);
    struct Node* ASSIGNOP_node = new Node(yystack_[1].location.begin.line,"ASSIGNOP",Node::end);
    yylhs.value.as < Node* > () = new_node;
    
    add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),1);
    add_child(yylhs.value.as < Node* > (), ASSIGNOP_node,2);
    add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > (),3);
}
#line 1462 "/home/compiler/build/parser.cc"
    break;

  case 53: // Exp: Exp ASSIGNOP error
#line 402 "parser.yy"
                         {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong expression");}
#line 1468 "/home/compiler/build/parser.cc"
    break;

  case 54: // Exp: Exp AND Exp
#line 403 "parser.yy"
                  {
        struct Node* new_node = new Node(yystack_[2].location.begin.line,"Exp",Node::non_end,2);
        struct Node* AND_node = new Node(yystack_[1].location.begin.line,"AND",Node::end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),1);
        add_child(yylhs.value.as < Node* > (), AND_node,2);
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > (),3);
    }
#line 1482 "/home/compiler/build/parser.cc"
    break;

  case 55: // Exp: Exp AND error
#line 412 "parser.yy"
                    {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong expression");}
#line 1488 "/home/compiler/build/parser.cc"
    break;

  case 56: // Exp: Exp OR Exp
#line 413 "parser.yy"
                 {
        struct Node* new_node = new Node(yystack_[2].location.begin.line,"Exp",Node::non_end,3);
        struct Node* OR_node = new Node(yystack_[1].location.begin.line,"OR",Node::end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),1);
        add_child(yylhs.value.as < Node* > (), OR_node,2);
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > (),3);
    }
#line 1502 "/home/compiler/build/parser.cc"
    break;

  case 57: // Exp: Exp OR error
#line 422 "parser.yy"
                   {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong expression");}
#line 1508 "/home/compiler/build/parser.cc"
    break;

  case 58: // Exp: Exp RELOP Exp
#line 423 "parser.yy"
                    {
        struct Node* new_node = new Node(yystack_[2].location.begin.line,"Exp",Node::non_end,4);
        struct Node* RELOP_node = new Node(yystack_[1].location.begin.line,"RELOP",Node::end);
        RELOP_node->m_value = yystack_[1].value.as < std::string > ();
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),1);
        add_child(yylhs.value.as < Node* > (), RELOP_node,2);
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > (),3);
    }
#line 1523 "/home/compiler/build/parser.cc"
    break;

  case 59: // Exp: Exp RELOP error
#line 433 "parser.yy"
                      {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong expression");}
#line 1529 "/home/compiler/build/parser.cc"
    break;

  case 60: // Exp: Exp PLUS Exp
#line 434 "parser.yy"
                   {
        struct Node* new_node = new Node(yystack_[2].location.begin.line,"Exp",Node::non_end,5);
        struct Node* PLUS_node = new Node(yystack_[1].location.begin.line,"PLUS",Node::end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),1);
        add_child(yylhs.value.as < Node* > (), PLUS_node,2);
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > (),3);
    }
#line 1543 "/home/compiler/build/parser.cc"
    break;

  case 61: // Exp: Exp PLUS error
#line 443 "parser.yy"
                     {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong expression");}
#line 1549 "/home/compiler/build/parser.cc"
    break;

  case 62: // Exp: Exp MINUS Exp
#line 444 "parser.yy"
                    {
        struct Node* new_node = new Node(yystack_[2].location.begin.line,"Exp",Node::non_end,6);
        struct Node* MINUS_node = new Node(yystack_[1].location.begin.line,"MINUS",Node::end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),1);
        add_child(yylhs.value.as < Node* > (), MINUS_node,2);
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > (),3);
    }
#line 1563 "/home/compiler/build/parser.cc"
    break;

  case 63: // Exp: Exp MINUS error
#line 453 "parser.yy"
                      {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong expression");}
#line 1569 "/home/compiler/build/parser.cc"
    break;

  case 64: // Exp: Exp STAR Exp
#line 454 "parser.yy"
                   {
        struct Node* new_node = new Node(yystack_[2].location.begin.line,"Exp",Node::non_end,7);
        struct Node* STAR_node = new Node(yystack_[1].location.begin.line,"STAR",Node::end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),1);
        add_child(yylhs.value.as < Node* > (), STAR_node,2);
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > (),3);
    }
#line 1583 "/home/compiler/build/parser.cc"
    break;

  case 65: // Exp: Exp STAR error
#line 463 "parser.yy"
                     {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong expression");}
#line 1589 "/home/compiler/build/parser.cc"
    break;

  case 66: // Exp: Exp DIV Exp
#line 464 "parser.yy"
                  {
        struct Node* new_node = new Node(yystack_[2].location.begin.line,"Exp",Node::non_end,8);
        struct Node* DIV_node = new Node(yystack_[1].location.begin.line,"DIV",Node::end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),1);
        add_child(yylhs.value.as < Node* > (), DIV_node,2);
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > (),3);
    }
#line 1603 "/home/compiler/build/parser.cc"
    break;

  case 67: // Exp: Exp DIV error
#line 473 "parser.yy"
                    {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong expression");}
#line 1609 "/home/compiler/build/parser.cc"
    break;

  case 68: // Exp: LP Exp RP
#line 474 "parser.yy"
                {
        struct Node* new_node = new Node(yystack_[2].location.begin.line,"Exp",Node::non_end,9);
        struct Node* LP_node = new Node(yystack_[2].location.begin.line,"LP",Node::end);
        struct Node* RP_node = new Node(yystack_[0].location.begin.line,"RP",Node::end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),LP_node,1);
        add_child(yylhs.value.as < Node* > (), yystack_[1].value.as < Node* > (),2);
        add_child(yylhs.value.as < Node* > (), RP_node,3);
    }
#line 1624 "/home/compiler/build/parser.cc"
    break;

  case 69: // Exp: LP error
#line 484 "parser.yy"
               {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[1].location.begin.line, "Missing )");}
#line 1630 "/home/compiler/build/parser.cc"
    break;

  case 70: // Exp: MINUS Exp
#line 485 "parser.yy"
                {
        struct Node* new_node = new Node(yystack_[1].location.begin.line,"Exp",Node::non_end,10);
        struct Node* MINUS_node = new Node(yystack_[1].location.begin.line,"MINUS",Node::end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),MINUS_node,1);
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > (),2);
    }
#line 1643 "/home/compiler/build/parser.cc"
    break;

  case 71: // Exp: MINUS error
#line 493 "parser.yy"
                  {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[1].location.begin.line, "Wrong expression");}
#line 1649 "/home/compiler/build/parser.cc"
    break;

  case 72: // Exp: NOT Exp
#line 494 "parser.yy"
              {
        struct Node* new_node = new Node(yystack_[1].location.begin.line,"Exp",Node::non_end,11);
        struct Node* NOT_node = new Node(yystack_[1].location.begin.line,"NOT",Node::end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),NOT_node,1);
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > (),2);
    }
#line 1662 "/home/compiler/build/parser.cc"
    break;

  case 73: // Exp: NOT error
#line 502 "parser.yy"
                {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[1].location.begin.line, "Wrong expression");}
#line 1668 "/home/compiler/build/parser.cc"
    break;

  case 74: // Exp: ID LP Args RP
#line 503 "parser.yy"
                    {
        struct Node* new_node = new Node(yystack_[3].location.begin.line,"Exp",Node::non_end,12);
        struct Node* ID_node = new Node(yystack_[3].location.begin.line,"ID",Node::string_node);
        ID_node->m_value = yystack_[3].value.as < std::string > ();
        struct Node* LP_node = new Node(yystack_[2].location.begin.line,"LP",Node::end);
        struct Node* RP_node = new Node(yystack_[0].location.begin.line,"RP",Node::end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),ID_node,1);
        add_child(yylhs.value.as < Node* > (),LP_node,2);
        add_child(yylhs.value.as < Node* > (), yystack_[1].value.as < Node* > (),3);
        add_child(yylhs.value.as < Node* > (),RP_node,4);
    }
#line 1686 "/home/compiler/build/parser.cc"
    break;

  case 75: // Exp: ID LP Args error
#line 516 "parser.yy"
                       {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[3].location.begin.line, "Missing )");}
#line 1692 "/home/compiler/build/parser.cc"
    break;

  case 76: // Exp: ID LP RP
#line 517 "parser.yy"
               {
        struct Node* new_node = new Node(yystack_[2].location.begin.line,"Exp",Node::non_end,13);
        struct Node* ID_node = new Node(yystack_[2].location.begin.line,"ID",Node::string_node);
        ID_node->m_value = yystack_[2].value.as < std::string > ();
        struct Node* LP_node = new Node(yystack_[1].location.begin.line,"LP",Node::end);
        struct Node* RP_node = new Node(yystack_[0].location.begin.line,"RP",Node::end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),ID_node,1);
        add_child(yylhs.value.as < Node* > (),LP_node,2);
        add_child(yylhs.value.as < Node* > (),RP_node,3);
    }
#line 1709 "/home/compiler/build/parser.cc"
    break;

  case 77: // Exp: ID LP error
#line 529 "parser.yy"
                  {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Missing )");}
#line 1715 "/home/compiler/build/parser.cc"
    break;

  case 78: // Exp: Exp LB Exp RB
#line 530 "parser.yy"
                    {
        struct Node* new_node = new Node(yystack_[3].location.begin.line,"Exp",Node::non_end,14);
        struct Node* LB_node = new Node(yystack_[2].location.begin.line,"LB",Node::end);
        struct Node* RB_node = new Node(yystack_[0].location.begin.line,"RB",Node::end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[3].value.as < Node* > (),1);
        add_child(yylhs.value.as < Node* > (),LB_node,2);
        add_child(yylhs.value.as < Node* > (),yystack_[1].value.as < Node* > (),3);
        add_child(yylhs.value.as < Node* > (),RB_node,4);
    }
#line 1731 "/home/compiler/build/parser.cc"
    break;

  case 79: // Exp: Exp LB error RB
#line 541 "parser.yy"
                      {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[3].location.begin.line, "Wrong expression");}
#line 1737 "/home/compiler/build/parser.cc"
    break;

  case 80: // Exp: Exp DOT ID
#line 542 "parser.yy"
                 {
        struct Node* new_node = new Node(yystack_[2].location.begin.line,"Exp",Node::non_end,15);
        struct Node* DOT_node = new Node(yystack_[1].location.begin.line,"DOT",Node::end);
        struct Node* ID_node = new Node(yystack_[0].location.begin.line,"ID",Node::string_node);
        ID_node->m_value = yystack_[0].value.as < std::string > ();
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),1);
        add_child(yylhs.value.as < Node* > (),DOT_node,2);
        add_child(yylhs.value.as < Node* > (),ID_node,3);
    }
#line 1753 "/home/compiler/build/parser.cc"
    break;

  case 81: // Exp: ID
#line 553 "parser.yy"
         {
        struct Node* new_node = new Node(yystack_[0].location.begin.line,"Exp",Node::non_end,16);
        struct Node* ID_node = new Node(yystack_[0].location.begin.line,"ID",Node::string_node);
        ID_node->m_value = yystack_[0].value.as < std::string > ();
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),ID_node,1);
    }
#line 1766 "/home/compiler/build/parser.cc"
    break;

  case 82: // Exp: "int"
#line 561 "parser.yy"
          {
        struct Node* new_node = new Node(yystack_[0].location.begin.line,"Exp",Node::non_end,17);
        struct Node* int_node = new Node(yystack_[0].location.begin.line,"INT",Node::int_node);
        int_node->m_value = yystack_[0].value.as < int > ();
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),int_node,1);
    }
#line 1779 "/home/compiler/build/parser.cc"
    break;

  case 83: // Exp: "float"
#line 569 "parser.yy"
            {
        struct Node* new_node = new Node(yystack_[0].location.begin.line,"Exp",Node::non_end,18);
        struct Node* float_node = new Node(yystack_[0].location.begin.line,"FLOAT",Node::float_node);
        float_node->m_value = yystack_[0].value.as < float > ();
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),float_node,1);

    }
#line 1793 "/home/compiler/build/parser.cc"
    break;

  case 84: // Exp: error RP
#line 578 "parser.yy"
               {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[1].location.begin.line, "Wrong expression");}
#line 1799 "/home/compiler/build/parser.cc"
    break;

  case 85: // Args: Exp COMMA Args
#line 580 "parser.yy"
                      {
    struct Node* new_node = new Node(yystack_[2].location.begin.line,"Args",Node::non_end,1);
    struct Node* COMMA_node = new Node(yystack_[1].location.begin.line,"COMMA",Node::end);
    yylhs.value.as < Node* > () = new_node;
    
    add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),1);
    add_child(yylhs.value.as < Node* > (),COMMA_node,2);
    add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > (),3);
}
#line 1813 "/home/compiler/build/parser.cc"
    break;

  case 86: // Args: Exp
#line 589 "parser.yy"
          {
        struct Node* new_node = new Node(yystack_[0].location.begin.line,"Args",Node::non_end,2);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > (),1);
    }
#line 1824 "/home/compiler/build/parser.cc"
    break;


#line 1828 "/home/compiler/build/parser.cc"

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
  "RELOP", "SEMI", "COMMA", "ASSIGNOP", "PLUS", "MINUS", "STAR", "DIV",
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
      50,   -61,    15,    83,   -61,    50,   130,   -61,    61,    65,
     -61,   -61,   -61,   -61,    66,   -61,    98,    80,    25,     6,
      56,   -61,    13,    14,    68,    68,   -61,    53,    22,    87,
      68,   -61,   110,    97,   111,   -61,   -61,   -61,   108,   117,
     110,    95,    95,   -61,    69,   125,   128,   134,   135,   -61,
     -61,   123,   -61,    50,   -61,   -61,    41,   -61,   -61,   131,
     186,   191,   210,   215,   146,   148,   -61,   140,    95,   145,
     144,   220,   -61,   110,   -61,   -61,   -61,   -61,   -61,   181,
     127,   115,   127,    34,   127,   349,     5,   162,   239,   239,
     -61,   -61,   -61,   244,   -61,   249,   268,   273,   278,   297,
     302,   307,   149,   326,   -61,   127,   400,   -61,   127,   -61,
     364,    62,   -61,   -61,   -61,   -61,   127,   376,   388,   127,
      91,   127,   400,   127,   115,   127,   115,   127,    34,   127,
      34,   127,   422,   127,   411,   -61,    32,   336,   239,   -61,
     -61,   122,   122,   -61,   -61,   -61,   143,   -61,   122,   -61
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
      29,    30,    34,     0,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    28,    51,    50,    48,    77,    76,
      86,     0,    68,    38,    37,    36,     0,     0,     0,    59,
      58,    53,    52,    61,    60,    63,    62,    65,    64,    67,
      66,    55,    54,    57,    56,    80,     0,     0,     0,    75,
      74,     0,     0,    79,    78,    85,    39,    41,     0,    40
  };

  const short
  parser::yypgoto_[] =
  {
     -61,   -61,   175,   -61,   159,     4,   -61,   -61,   -61,     0,
     -61,   153,   -61,   170,   -34,   -32,    -9,   -61,   -23,   -61,
     -60,    59
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
      81,    83,    85,    87,     6,    48,    17,    27,    70,     6,
      29,   106,     1,   113,    35,    38,    42,    39,    36,   110,
       8,    50,    17,    47,    32,    78,    24,    36,   117,   118,
     -43,     2,    51,   120,    91,   122,   124,   126,   128,   130,
     132,   134,    40,   137,   -43,   -43,   -43,     1,    25,    77,
     107,   102,    78,   -43,   143,   103,     1,    32,    36,   -43,
     -43,    78,     1,   139,   -43,   -43,     2,   -43,   -43,    40,
     -43,   -43,   -43,   -43,     1,     2,    31,    43,   110,    71,
     -43,     2,   140,    11,   -17,    20,   -43,   -43,    19,    22,
      23,   -43,   -43,     2,   -43,   -43,    56,   -43,    57,    58,
      59,    23,    96,    97,    98,    99,    21,    60,   102,   146,
     147,    49,   103,    61,    62,    36,   149,    52,    25,   -31,
      53,    63,    64,    56,    65,    57,    58,    59,    98,    99,
      54,    13,   102,    72,    60,    14,   103,    73,    15,    55,
      61,    62,    74,    75,    23,    25,    92,    78,    63,    64,
      79,    65,    93,    94,   135,    95,    96,    97,    98,    99,
     100,   101,   102,   114,    90,    88,   103,    89,   104,    93,
     115,   148,    95,    96,    97,    98,    99,   100,   101,   102,
      12,    37,   108,   103,    57,    58,    59,    80,    26,    57,
      58,    59,    82,    60,    57,    58,    59,   145,    60,    61,
      62,   109,     0,    60,    61,    62,    76,     0,     0,    61,
      62,    84,     0,    57,    58,    59,    86,     0,    57,    58,
      59,   105,    60,    57,    58,    59,     0,    60,    61,    62,
       0,     0,    60,    61,    62,     0,     0,     0,    61,    62,
     116,     0,    57,    58,    59,   119,     0,    57,    58,    59,
     121,    60,    57,    58,    59,     0,    60,    61,    62,     0,
       0,    60,    61,    62,     0,     0,     0,    61,    62,   123,
       0,    57,    58,    59,   125,     0,    57,    58,    59,   127,
      60,    57,    58,    59,     0,    60,    61,    62,     0,     0,
      60,    61,    62,     0,     0,     0,    61,    62,   129,     0,
      57,    58,    59,   131,     0,    57,    58,    59,   133,    60,
      57,    58,    59,     0,    60,    61,    62,     0,     0,    60,
      61,    62,     0,     0,     0,    61,    62,   136,     0,    57,
      58,    59,     0,     0,     0,     0,     0,     0,    60,     0,
       0,     0,     0,    93,    61,    62,    95,    96,    97,    98,
      99,   100,   101,   102,     0,     0,    93,   103,   144,    95,
      96,    97,    98,    99,   100,   101,   102,     0,     0,   112,
     103,    93,     0,   138,    95,    96,    97,    98,    99,   100,
     101,   102,     0,    93,     0,   103,    95,    96,    97,    98,
      99,   100,   101,   102,     0,    93,   141,   103,    95,    96,
      97,    98,    99,   100,   101,   102,     0,    93,   142,   103,
      95,    96,    97,    98,    99,   100,   101,   102,    93,     0,
       0,   103,    96,    97,    98,    99,   100,     0,   102,    93,
       0,     0,   103,    96,    97,    98,    99,     0,     0,   102,
       0,     0,     0,   103
  };

  const short
  parser::yycheck_[] =
  {
      60,    61,    62,    63,     0,    28,     6,     1,    42,     5,
      19,    71,     6,     8,     1,     1,    25,     3,     5,    79,
       5,    30,    22,     1,    20,    20,     1,     5,    88,    89,
      24,    25,    32,    93,    68,    95,    96,    97,    98,    99,
     100,   101,     1,   103,     3,     4,     5,     6,    23,     8,
      73,    17,    20,    12,    22,    21,     6,    53,     5,    18,
      19,    20,     6,     1,    23,    24,    25,    26,    27,     1,
      29,     3,     4,     5,     6,    25,    20,    24,   138,    10,
      12,    25,    20,     0,    23,    19,    18,    19,    23,     9,
      21,    23,    24,    25,    26,    27,     1,    29,     3,     4,
       5,    21,    11,    12,    13,    14,     8,    12,    17,   141,
     142,    24,    21,    18,    19,     5,   148,    20,    23,    24,
       9,    26,    27,     1,    29,     3,     4,     5,    13,    14,
      22,     1,    17,     8,    12,     5,    21,     9,     8,    22,
      18,    19,     8,     8,    21,    23,     1,    20,    26,    27,
      19,    29,     7,     8,     5,    10,    11,    12,    13,    14,
      15,    16,    17,     1,    24,    19,    21,    19,    24,     7,
       8,    28,    10,    11,    12,    13,    14,    15,    16,    17,
       5,    22,     1,    21,     3,     4,     5,     1,    18,     3,
       4,     5,     1,    12,     3,     4,     5,   138,    12,    18,
      19,    20,    -1,    12,    18,    19,    53,    -1,    -1,    18,
      19,     1,    -1,     3,     4,     5,     1,    -1,     3,     4,
       5,     1,    12,     3,     4,     5,    -1,    12,    18,    19,
      -1,    -1,    12,    18,    19,    -1,    -1,    -1,    18,    19,
       1,    -1,     3,     4,     5,     1,    -1,     3,     4,     5,
       1,    12,     3,     4,     5,    -1,    12,    18,    19,    -1,
      -1,    12,    18,    19,    -1,    -1,    -1,    18,    19,     1,
      -1,     3,     4,     5,     1,    -1,     3,     4,     5,     1,
      12,     3,     4,     5,    -1,    12,    18,    19,    -1,    -1,
      12,    18,    19,    -1,    -1,    -1,    18,    19,     1,    -1,
       3,     4,     5,     1,    -1,     3,     4,     5,     1,    12,
       3,     4,     5,    -1,    12,    18,    19,    -1,    -1,    12,
      18,    19,    -1,    -1,    -1,    18,    19,     1,    -1,     3,
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    12,    -1,
      -1,    -1,    -1,     7,    18,    19,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    -1,     7,    21,    22,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    20,
      21,     7,    -1,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,     7,    -1,    21,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,     7,    20,    21,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,     7,    20,    21,
      10,    11,    12,    13,    14,    15,    16,    17,     7,    -1,
      -1,    21,    11,    12,    13,    14,    15,    -1,    17,     7,
      -1,    -1,    21,    11,    12,    13,    14,    -1,    -1,    17,
      -1,    -1,    -1,    21
  };

  const signed char
  parser::yystos_[] =
  {
       0,     6,    25,    32,    33,    34,    36,    37,     5,    38,
      39,     0,    33,     1,     5,     8,    35,    40,    41,    23,
      19,     8,     9,    21,     1,    23,    44,     1,    36,    47,
      48,    20,    36,    42,    43,     1,     5,    35,     1,     3,
       1,    47,    47,    24,    40,    49,    50,     1,    49,    24,
      47,    40,    20,     9,    22,    22,     1,     3,     4,     5,
      12,    18,    19,    26,    27,    29,    44,    45,    46,    51,
      45,    10,     8,     9,     8,     8,    42,     8,    20,    19,
       1,    51,     1,    51,     1,    51,     1,    51,    19,    19,
      24,    45,     1,     7,     8,    10,    11,    12,    13,    14,
      15,    16,    17,    21,    24,     1,    51,    49,     1,    20,
      51,    52,    20,     8,     1,     8,     1,    51,    51,     1,
      51,     1,    51,     1,    51,     1,    51,     1,    51,     1,
      51,     1,    51,     1,    51,     5,     1,    51,     9,     1,
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
       0,    68,    68,    74,    80,    84,    92,    99,   106,   108,
     113,   121,   123,   130,   136,   148,   155,   157,   164,   168,
     177,   184,   196,   198,   210,   222,   230,   236,   244,   254,
     256,   262,   266,   273,   274,   275,   280,   290,   291,   292,
     305,   321,   336,   343,   347,   356,   357,   359,   365,   375,
     381,   390,   393,   402,   403,   412,   413,   422,   423,   433,
     434,   443,   444,   453,   454,   463,   464,   473,   474,   484,
     485,   493,   494,   502,   503,   516,   517,   529,   530,   541,
     542,   553,   561,   569,   578,   580,   589
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
#line 2542 "/home/compiler/build/parser.cc"

#line 598 "parser.yy"


void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
