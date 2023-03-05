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
#line 27 "parser.yy"

  #include "driver.hh"
  #include "ast.hh"
  #include "node.hh"
  AST* ast;

#line 53 "/home/compiler/build/parser.cc"


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
#line 145 "/home/compiler/build/parser.cc"

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
#line 43 "parser.yy"
                 { yyo << yysym.value.template as < int > (); }
#line 445 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_FLOAT: // "float"
#line 43 "parser.yy"
                 { yyo << yysym.value.template as < float > (); }
#line 451 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_ID: // ID
#line 43 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 457 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_TYPE: // TYPE
#line 43 "parser.yy"
                 { yyo << yysym.value.template as < std::string > (); }
#line 463 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_Program: // Program
#line 43 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 469 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_ExtDefList: // ExtDefList
#line 43 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 475 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_ExtDef: // ExtDef
#line 43 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 481 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_ExtDecList: // ExtDecList
#line 43 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 487 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_Specifier: // Specifier
#line 43 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 493 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_StructSpecifier: // StructSpecifier
#line 43 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 499 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_OptTag: // OptTag
#line 43 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 505 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_Tag: // Tag
#line 43 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 511 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_VarDec: // VarDec
#line 43 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 517 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_FunDec: // FunDec
#line 43 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 523 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_VarList: // VarList
#line 43 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 529 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_ParamDec: // ParamDec
#line 43 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 535 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_CompSt: // CompSt
#line 43 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 541 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_StmtList: // StmtList
#line 43 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 547 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_Stmt: // Stmt
#line 43 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 553 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_DefList: // DefList
#line 43 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 559 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_Def: // Def
#line 43 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 565 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_DecList: // DecList
#line 43 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 571 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_Dec: // Dec
#line 43 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 577 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_Exp: // Exp
#line 43 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 583 "/home/compiler/build/parser.cc"
        break;

      case symbol_kind::S_Args: // Args
#line 43 "parser.yy"
                 { yyo << yysym.value.template as < Node* > (); }
#line 589 "/home/compiler/build/parser.cc"
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
#line 66 "parser.yy"
                    {
    Node* new_node = new Node(yystack_[0].location.begin.line,"Program",Node::non_end,1);
    ast = new AST(new_node);
    yylhs.value.as < Node* > () = new_node;
    add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > (),1);
}
#line 894 "/home/compiler/build/parser.cc"
    break;

  case 3: // ExtDefList: ExtDef ExtDefList
#line 72 "parser.yy"
                              {
    struct Node* new_node = new Node(yystack_[1].location.begin.line,"ExtDefList",Node::non_end,1);
    yylhs.value.as < Node* > () = new_node;
    add_child(yylhs.value.as < Node* > (),yystack_[1].value.as < Node* > (),1);
    add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > (),2);
}
#line 905 "/home/compiler/build/parser.cc"
    break;

  case 4: // ExtDefList: %empty
#line 78 "parser.yy"
               {
        yylhs.value.as < Node* > () = NULL;
    }
#line 913 "/home/compiler/build/parser.cc"
    break;

  case 5: // ExtDef: Specifier ExtDecList SEMI
#line 82 "parser.yy"
                                  {
    struct Node* new_node = new Node(yystack_[2].location.begin.line,"ExtDef",Node::non_end,1);
    struct Node* SEMI_node = new Node(yystack_[0].location.begin.line,"SEMI",Node::end);
    yylhs.value.as < Node* > () = new_node;
    add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),1);
    add_child(yylhs.value.as < Node* > (),yystack_[1].value.as < Node* > (),2);
    add_child(yylhs.value.as < Node* > (),SEMI_node,3);
}
#line 926 "/home/compiler/build/parser.cc"
    break;

  case 6: // ExtDef: Specifier SEMI
#line 90 "parser.yy"
                     {
        struct Node* new_node = new Node(yystack_[1].location.begin.line,"ExtDef",Node::non_end,2);
        struct Node* SEMI_node = new Node(yystack_[0].location.begin.line,"SEMI",Node::end);
        yylhs.value.as < Node* > () = new_node;
        add_child(yylhs.value.as < Node* > (),yystack_[1].value.as < Node* > (),1);
        add_child(yylhs.value.as < Node* > (),SEMI_node,2);
    }
#line 938 "/home/compiler/build/parser.cc"
    break;

  case 7: // ExtDef: Specifier FunDec CompSt
#line 97 "parser.yy"
                              {
        struct Node* new_node = new Node(yystack_[2].location.begin.line,"ExtDef",Node::non_end,3);
        yylhs.value.as < Node* > () = new_node;
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),1);
        add_child(yylhs.value.as < Node* > (),yystack_[1].value.as < Node* > (),2);
        add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > (),3);
    }
#line 950 "/home/compiler/build/parser.cc"
    break;

  case 8: // ExtDef: Specifier error
#line 104 "parser.yy"
                      {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[1].location.begin.line, "delcaration error");}
#line 956 "/home/compiler/build/parser.cc"
    break;

  case 9: // ExtDecList: VarDec
#line 106 "parser.yy"
                    {
    struct Node* new_node = new Node(yystack_[0].location.begin.line,"ExtDecList",Node::non_end,1);
    yylhs.value.as < Node* > () = new_node;
    add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > (),1);
}
#line 966 "/home/compiler/build/parser.cc"
    break;

  case 10: // ExtDecList: VarDec COMMA ExtDecList
#line 111 "parser.yy"
                              {
        struct Node* new_node = new Node(yystack_[2].location.begin.line,"ExtDecList",Node::non_end,2);
        struct Node* COMMA_node = new Node(yystack_[1].location.begin.line,"COMMA",Node::end);
        yylhs.value.as < Node* > () = new_node;
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),1);
        add_child(yylhs.value.as < Node* > (),COMMA_node,2);
        add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > (),3);
    }
#line 979 "/home/compiler/build/parser.cc"
    break;

  case 11: // ExtDecList: VarDec COMMA error
#line 119 "parser.yy"
                         {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "delcaration error");}
#line 985 "/home/compiler/build/parser.cc"
    break;

  case 12: // Specifier: TYPE
#line 121 "parser.yy"
                 {
    struct Node* new_node = new Node(yystack_[0].location.begin.line,"Specifier",Node::non_end,1);
    struct Node* TYPE_node = new Node(yystack_[0].location.begin.line,"TYPE",Node::string_node);
    TYPE_node->type_string = yystack_[0].value.as < std::string > ();
    yylhs.value.as < Node* > () = new_node;
    add_child(yylhs.value.as < Node* > (),TYPE_node,1);
}
#line 997 "/home/compiler/build/parser.cc"
    break;

  case 13: // Specifier: StructSpecifier
#line 128 "parser.yy"
                      {
        struct Node* new_node = new Node(yystack_[0].location.begin.line,"Specifier",Node::non_end,2);
        yylhs.value.as < Node* > () = new_node;
        add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > (),1);
    }
#line 1007 "/home/compiler/build/parser.cc"
    break;

  case 14: // StructSpecifier: STRUCT OptTag LC DefList RC
#line 134 "parser.yy"
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
#line 1024 "/home/compiler/build/parser.cc"
    break;

  case 15: // StructSpecifier: STRUCT Tag
#line 146 "parser.yy"
                 {
        struct Node* new_node = new Node(yystack_[1].location.begin.line,"StructSpecifier",Node::non_end,2);
        yylhs.value.as < Node* > () = new_node;
        struct Node* STRUCT_node = new Node(yystack_[1].location.begin.line,"STRUCT",Node::end);
        add_child(yylhs.value.as < Node* > (),STRUCT_node,1);
        add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > (),2);
    }
#line 1036 "/home/compiler/build/parser.cc"
    break;

  case 16: // StructSpecifier: STRUCT OptTag LC error RC
#line 153 "parser.yy"
                               {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[4].location.begin.line, "struct error");}
#line 1042 "/home/compiler/build/parser.cc"
    break;

  case 17: // OptTag: ID
#line 155 "parser.yy"
           {
    struct Node* new_node = new Node(yystack_[0].location.begin.line,"OptTag",Node::non_end,1);
    yylhs.value.as < Node* > () = new_node;
    struct Node* ID_node = new Node(yystack_[0].location.begin.line,"ID",Node::string_node);
    ID_node->type_string = yystack_[0].value.as < std::string > ();
    add_child(yylhs.value.as < Node* > (),ID_node,1);
}
#line 1054 "/home/compiler/build/parser.cc"
    break;

  case 18: // OptTag: %empty
#line 162 "parser.yy"
               {
        yylhs.value.as < Node* > () = NULL;
    }
#line 1062 "/home/compiler/build/parser.cc"
    break;

  case 19: // Tag: ID
#line 166 "parser.yy"
        {
    struct Node* new_node = new Node(yystack_[0].location.begin.line,"Tag",Node::non_end,1);
    yylhs.value.as < Node* > () = new_node;
    struct Node* ID_node = new Node(yystack_[0].location.begin.line,"ID",Node::string_node);
    ID_node->type_string = yystack_[0].value.as < std::string > ();
    add_child(yylhs.value.as < Node* > (),ID_node,1);
}
#line 1074 "/home/compiler/build/parser.cc"
    break;

  case 20: // VarDec: ID
#line 175 "parser.yy"
            {
    struct Node* new_node = new Node(yystack_[0].location.begin.line,"VarDec",Node::non_end,1);
    yylhs.value.as < Node* > () = new_node;
    struct Node* ID_node = new Node(yystack_[0].location.begin.line,"ID",Node::string_node);
    ID_node->type_string = yystack_[0].value.as < std::string > ();
    add_child(yylhs.value.as < Node* > (),ID_node,1);
}
#line 1086 "/home/compiler/build/parser.cc"
    break;

  case 21: // VarDec: VarDec LB "int" RB
#line 182 "parser.yy"
                       {
        struct Node* new_node = new Node(yystack_[3].location.begin.line,"VarDec",Node::non_end,2);
        yylhs.value.as < Node* > () = new_node;
        struct Node* LB_node = new Node(yystack_[2].location.begin.line,"LB",Node::end);
        struct Node* int_node = new Node(yystack_[1].location.begin.line,"INT",Node::int_node);
        int_node->type_int = yystack_[1].value.as < int > ();
        struct Node* RB_node = new Node(yystack_[0].location.begin.line,"RB",Node::end);
        add_child(yylhs.value.as < Node* > (),yystack_[3].value.as < Node* > (),1);
        add_child(yylhs.value.as < Node* > (), LB_node,2);
        add_child(yylhs.value.as < Node* > (),int_node,3);
        add_child(yylhs.value.as < Node* > (),RB_node,4);
    }
#line 1103 "/home/compiler/build/parser.cc"
    break;

  case 22: // VarDec: VarDec LB error RB
#line 194 "parser.yy"
                         {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[3].location.begin.line, "wrong variable declaration");}
#line 1109 "/home/compiler/build/parser.cc"
    break;

  case 23: // FunDec: ID LP VarList RP
#line 196 "parser.yy"
                          {
    struct Node* new_node = new Node(yystack_[3].location.begin.line,"FunDec",Node::non_end,1);
    yylhs.value.as < Node* > () = new_node;
    struct Node* ID_node = new Node(yystack_[3].location.begin.line,"ID",Node::string_node);
    ID_node->type_string = yystack_[3].value.as < std::string > ();
    struct Node* LP_node = new Node(yystack_[2].location.begin.line,"LP",Node::end);
    struct Node* RP_node = new Node(yystack_[0].location.begin.line,"RP",Node::end);
    add_child(yylhs.value.as < Node* > (),ID_node,1);
    add_child(yylhs.value.as < Node* > (), LP_node,2);
    add_child(yylhs.value.as < Node* > (),yystack_[1].value.as < Node* > (),3);
    add_child(yylhs.value.as < Node* > (),RP_node,4);
}
#line 1126 "/home/compiler/build/parser.cc"
    break;

  case 24: // FunDec: ID LP RP
#line 208 "parser.yy"
               {
        struct Node* new_node = new Node(yystack_[2].location.begin.line,"FunDec",Node::non_end,2);
        yylhs.value.as < Node* > () = new_node;
        struct Node* ID_node = new Node(yystack_[2].location.begin.line,"ID",Node::string_node);
        ID_node->type_string = yystack_[2].value.as < std::string > ();
        struct Node* LP_node = new Node(yystack_[1].location.begin.line,"LP",Node::end);
        struct Node* RP_node = new Node(yystack_[0].location.begin.line,"RP",Node::end);
        add_child(yylhs.value.as < Node* > (),ID_node,1);
        add_child(yylhs.value.as < Node* > (), LP_node,2);
        add_child(yylhs.value.as < Node* > (),RP_node,3);
    }
#line 1142 "/home/compiler/build/parser.cc"
    break;

  case 25: // VarList: ParamDec COMMA VarList
#line 220 "parser.yy"
                                 {
    struct Node* new_node = new Node(yystack_[2].location.begin.line,"VarList",Node::non_end,1);
    yylhs.value.as < Node* > () = new_node;
    struct Node* COMMA_node = new Node(yystack_[1].location.begin.line,"COMMA",Node::end);
    add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),1);
    add_child(yylhs.value.as < Node* > (), COMMA_node,2);
    add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > (),3);
}
#line 1155 "/home/compiler/build/parser.cc"
    break;

  case 26: // VarList: ParamDec
#line 228 "parser.yy"
               {
        struct Node* new_node = new Node(yystack_[0].location.begin.line,"VarList",Node::non_end,2);
        yylhs.value.as < Node* > () = new_node;
        add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > (),1);
    }
#line 1165 "/home/compiler/build/parser.cc"
    break;

  case 27: // ParamDec: Specifier VarDec
#line 234 "parser.yy"
                            {
    struct Node* new_node = new Node(yystack_[1].location.begin.line,"ParamDec",Node::non_end,1);
    yylhs.value.as < Node* > () = new_node;
    add_child(yylhs.value.as < Node* > (),yystack_[1].value.as < Node* > (),1);
    add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > (),2);
}
#line 1176 "/home/compiler/build/parser.cc"
    break;

  case 28: // CompSt: LC DefList StmtList RC
#line 242 "parser.yy"
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
#line 1191 "/home/compiler/build/parser.cc"
    break;

  case 29: // CompSt: error DefList StmtList RC
#line 252 "parser.yy"
                                {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[3].location.begin.line, "Missing {");}
#line 1197 "/home/compiler/build/parser.cc"
    break;

  case 30: // StmtList: Stmt StmtList
#line 254 "parser.yy"
                         {
    struct Node* new_node = new Node(yystack_[1].location.begin.line,"StmtList",Node::non_end,1);
    yylhs.value.as < Node* > () = new_node;
    add_child(yylhs.value.as < Node* > (), yystack_[1].value.as < Node* > (),1);
    add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > (),2);
}
#line 1208 "/home/compiler/build/parser.cc"
    break;

  case 31: // StmtList: %empty
#line 260 "parser.yy"
                {
        yylhs.value.as < Node* > () = NULL;
    }
#line 1216 "/home/compiler/build/parser.cc"
    break;

  case 32: // Stmt: Exp SEMI
#line 264 "parser.yy"
               {
    struct Node* new_node = new Node(yystack_[1].location.begin.line,"Stmt",Node::non_end,1);
    struct Node* SEMI_node = new Node(yystack_[0].location.begin.line,"SEMI",Node::end);
    yylhs.value.as < Node* > () = new_node;
    add_child(yylhs.value.as < Node* > (), yystack_[1].value.as < Node* > (),1);
    add_child(yylhs.value.as < Node* > (),SEMI_node,2);
}
#line 1228 "/home/compiler/build/parser.cc"
    break;

  case 33: // Stmt: error SEMI
#line 271 "parser.yy"
                 {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[1].location.begin.line, "wrong expression");}
#line 1234 "/home/compiler/build/parser.cc"
    break;

  case 34: // Stmt: Exp error
#line 272 "parser.yy"
                {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[1].location.begin.line, "Missing ;");}
#line 1240 "/home/compiler/build/parser.cc"
    break;

  case 35: // Stmt: CompSt
#line 273 "parser.yy"
            {
        struct Node* new_node = new Node(yystack_[0].location.begin.line,"Stmt",Node::non_end,2);
        yylhs.value.as < Node* > () = new_node;
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > (),1);
    }
#line 1250 "/home/compiler/build/parser.cc"
    break;

  case 36: // Stmt: RETURN Exp SEMI
#line 278 "parser.yy"
                      {
        struct Node* new_node = new Node(yystack_[2].location.begin.line,"Stmt",Node::non_end,3);
        struct Node* RETURN_node = new Node(yystack_[2].location.begin.line,"RETURN",Node::end);
        struct Node* SEMI_node = new Node(yystack_[0].location.begin.line,"SEMI",Node::end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),RETURN_node,1);
        add_child(yylhs.value.as < Node* > (), yystack_[1].value.as < Node* > (),2);
        add_child(yylhs.value.as < Node* > (),SEMI_node,3);
    }
#line 1265 "/home/compiler/build/parser.cc"
    break;

  case 37: // Stmt: RETURN Exp error
#line 288 "parser.yy"
                       {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Missing ;");}
#line 1271 "/home/compiler/build/parser.cc"
    break;

  case 38: // Stmt: RETURN error SEMI
#line 289 "parser.yy"
                        {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong return expression");}
#line 1277 "/home/compiler/build/parser.cc"
    break;

  case 39: // Stmt: IF LP Exp RP Stmt
#line 290 "parser.yy"
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
#line 1295 "/home/compiler/build/parser.cc"
    break;

  case 40: // Stmt: IF LP Exp RP Stmt ELSE Stmt
#line 303 "parser.yy"
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
#line 1316 "/home/compiler/build/parser.cc"
    break;

  case 41: // Stmt: WHILE LP Exp RP Stmt
#line 319 "parser.yy"
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
#line 1334 "/home/compiler/build/parser.cc"
    break;

  case 42: // DefList: Def DefList
#line 334 "parser.yy"
                      {
    struct Node* new_node = new Node(yystack_[1].location.begin.line,"DefList",Node::non_end,1);
    yylhs.value.as < Node* > () = new_node;
    
    add_child(yylhs.value.as < Node* > (),yystack_[1].value.as < Node* > (),1);
    add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > (),2);
}
#line 1346 "/home/compiler/build/parser.cc"
    break;

  case 43: // DefList: %empty
#line 341 "parser.yy"
               {
        yylhs.value.as < Node* > () = NULL;
    }
#line 1354 "/home/compiler/build/parser.cc"
    break;

  case 44: // Def: Specifier DecList SEMI
#line 345 "parser.yy"
                             {
    struct Node* new_node = new Node(yystack_[2].location.begin.line,"Def",Node::non_end,1);
    struct Node* SEMI_node = new Node(yystack_[0].location.begin.line,"SEMI",Node::end);
    yylhs.value.as < Node* > () = new_node;
    
    add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),1);
    add_child(yylhs.value.as < Node* > (), yystack_[1].value.as < Node* > (),2);
    add_child(yylhs.value.as < Node* > (), SEMI_node,2);
}
#line 1368 "/home/compiler/build/parser.cc"
    break;

  case 45: // Def: error DecList SEMI
#line 354 "parser.yy"
                         {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong declaration");}
#line 1374 "/home/compiler/build/parser.cc"
    break;

  case 46: // Def: Specifier error SEMI
#line 355 "parser.yy"
                           {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong declaration");}
#line 1380 "/home/compiler/build/parser.cc"
    break;

  case 47: // DecList: Dec
#line 357 "parser.yy"
              {
    struct Node* new_node = new Node(yystack_[0].location.begin.line,"DecList",Node::non_end,1);
    yylhs.value.as < Node* > () = new_node;
    
    add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > (),1);
}
#line 1391 "/home/compiler/build/parser.cc"
    break;

  case 48: // DecList: Dec COMMA DecList
#line 363 "parser.yy"
                        {
        struct Node* new_node = new Node(yystack_[2].location.begin.line,"DecList",Node::non_end);
        struct Node* COMMA_node = new Node(yystack_[1].location.begin.line,"COMMA",Node::end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),1);
        add_child(yylhs.value.as < Node* > (), COMMA_node,2);
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > (),3);
    }
#line 1405 "/home/compiler/build/parser.cc"
    break;

  case 49: // Dec: VarDec
#line 373 "parser.yy"
             {
    struct Node* new_node = new Node(yystack_[0].location.begin.line,"Dec",Node::non_end,1);
    yylhs.value.as < Node* > () = new_node;
    
    add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > (),1);
}
#line 1416 "/home/compiler/build/parser.cc"
    break;

  case 50: // Dec: VarDec ASSIGNOP Exp
#line 379 "parser.yy"
                          {
        struct Node* new_node = new Node(yystack_[2].location.begin.line,"Dec",Node::non_end,2);
        struct Node* ASSIGNOP_node = new Node(yystack_[1].location.begin.line,"ASSIGNOP",Node::end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),1);
        add_child(yylhs.value.as < Node* > (), ASSIGNOP_node,2);
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > (),3);
    }
#line 1430 "/home/compiler/build/parser.cc"
    break;

  case 51: // Dec: VarDec ASSIGNOP error
#line 388 "parser.yy"
                            {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong expression");}
#line 1436 "/home/compiler/build/parser.cc"
    break;

  case 52: // Exp: Exp ASSIGNOP Exp
#line 391 "parser.yy"
                      {
    struct Node* new_node = new Node(yystack_[2].location.begin.line,"Exp",Node::non_end,1);
    struct Node* ASSIGNOP_node = new Node(yystack_[1].location.begin.line,"ASSIGNOP",Node::end);
    yylhs.value.as < Node* > () = new_node;
    
    add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),1);
    add_child(yylhs.value.as < Node* > (), ASSIGNOP_node,2);
    add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > (),3);
}
#line 1450 "/home/compiler/build/parser.cc"
    break;

  case 53: // Exp: Exp ASSIGNOP error
#line 400 "parser.yy"
                         {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong expression");}
#line 1456 "/home/compiler/build/parser.cc"
    break;

  case 54: // Exp: Exp AND Exp
#line 401 "parser.yy"
                  {
        struct Node* new_node = new Node(yystack_[2].location.begin.line,"Exp",Node::non_end,2);
        struct Node* AND_node = new Node(yystack_[1].location.begin.line,"AND",Node::end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),1);
        add_child(yylhs.value.as < Node* > (), AND_node,2);
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > (),3);
    }
#line 1470 "/home/compiler/build/parser.cc"
    break;

  case 55: // Exp: Exp AND error
#line 410 "parser.yy"
                    {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong expression");}
#line 1476 "/home/compiler/build/parser.cc"
    break;

  case 56: // Exp: Exp OR Exp
#line 411 "parser.yy"
                 {
        struct Node* new_node = new Node(yystack_[2].location.begin.line,"Exp",Node::non_end,3);
        struct Node* OR_node = new Node(yystack_[1].location.begin.line,"OR",Node::end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),1);
        add_child(yylhs.value.as < Node* > (), OR_node,2);
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > (),3);
    }
#line 1490 "/home/compiler/build/parser.cc"
    break;

  case 57: // Exp: Exp OR error
#line 420 "parser.yy"
                   {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong expression");}
#line 1496 "/home/compiler/build/parser.cc"
    break;

  case 58: // Exp: Exp RELOP Exp
#line 421 "parser.yy"
                    {
        struct Node* new_node = new Node(yystack_[2].location.begin.line,"Exp",Node::non_end,4);
        struct Node* RELOP_node = new Node(yystack_[1].location.begin.line,"RELOP",Node::end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),1);
        add_child(yylhs.value.as < Node* > (), RELOP_node,2);
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > (),3);
    }
#line 1510 "/home/compiler/build/parser.cc"
    break;

  case 59: // Exp: Exp RELOP error
#line 430 "parser.yy"
                      {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong expression");}
#line 1516 "/home/compiler/build/parser.cc"
    break;

  case 60: // Exp: Exp PLUS Exp
#line 431 "parser.yy"
                   {
        struct Node* new_node = new Node(yystack_[2].location.begin.line,"Exp",Node::non_end,5);
        struct Node* PLUS_node = new Node(yystack_[1].location.begin.line,"PLUS",Node::end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),1);
        add_child(yylhs.value.as < Node* > (), PLUS_node,2);
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > (),3);
    }
#line 1530 "/home/compiler/build/parser.cc"
    break;

  case 61: // Exp: Exp PLUS error
#line 440 "parser.yy"
                     {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong expression");}
#line 1536 "/home/compiler/build/parser.cc"
    break;

  case 62: // Exp: Exp MINUS Exp
#line 441 "parser.yy"
                    {
        struct Node* new_node = new Node(yystack_[2].location.begin.line,"Exp",Node::non_end,6);
        struct Node* MINUS_node = new Node(yystack_[1].location.begin.line,"MINUS",Node::end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),1);
        add_child(yylhs.value.as < Node* > (), MINUS_node,2);
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > (),3);
    }
#line 1550 "/home/compiler/build/parser.cc"
    break;

  case 63: // Exp: Exp MINUS error
#line 450 "parser.yy"
                      {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong expression");}
#line 1556 "/home/compiler/build/parser.cc"
    break;

  case 64: // Exp: Exp STAR Exp
#line 451 "parser.yy"
                   {
        struct Node* new_node = new Node(yystack_[2].location.begin.line,"Exp",Node::non_end,7);
        struct Node* STAR_node = new Node(yystack_[1].location.begin.line,"STAR",Node::end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),1);
        add_child(yylhs.value.as < Node* > (), STAR_node,2);
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > (),3);
    }
#line 1570 "/home/compiler/build/parser.cc"
    break;

  case 65: // Exp: Exp STAR error
#line 460 "parser.yy"
                     {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong expression");}
#line 1576 "/home/compiler/build/parser.cc"
    break;

  case 66: // Exp: Exp DIV Exp
#line 461 "parser.yy"
                  {
        struct Node* new_node = new Node(yystack_[2].location.begin.line,"Exp",Node::non_end,8);
        struct Node* DIV_node = new Node(yystack_[1].location.begin.line,"DIV",Node::end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),1);
        add_child(yylhs.value.as < Node* > (), DIV_node,2);
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > (),3);
    }
#line 1590 "/home/compiler/build/parser.cc"
    break;

  case 67: // Exp: Exp DIV error
#line 470 "parser.yy"
                    {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Wrong expression");}
#line 1596 "/home/compiler/build/parser.cc"
    break;

  case 68: // Exp: LP Exp RP
#line 471 "parser.yy"
                {
        struct Node* new_node = new Node(yystack_[2].location.begin.line,"Exp",Node::non_end,9);
        struct Node* LP_node = new Node(yystack_[2].location.begin.line,"LP",Node::end);
        struct Node* RP_node = new Node(yystack_[0].location.begin.line,"RP",Node::end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),LP_node,1);
        add_child(yylhs.value.as < Node* > (), yystack_[1].value.as < Node* > (),2);
        add_child(yylhs.value.as < Node* > (), RP_node,3);
    }
#line 1611 "/home/compiler/build/parser.cc"
    break;

  case 69: // Exp: LP error
#line 481 "parser.yy"
               {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[1].location.begin.line, "Missing )");}
#line 1617 "/home/compiler/build/parser.cc"
    break;

  case 70: // Exp: MINUS Exp
#line 482 "parser.yy"
                {
        struct Node* new_node = new Node(yystack_[1].location.begin.line,"Exp",Node::non_end,10);
        struct Node* MINUS_node = new Node(yystack_[1].location.begin.line,"MINUS",Node::end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),MINUS_node,1);
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > (),2);
    }
#line 1630 "/home/compiler/build/parser.cc"
    break;

  case 71: // Exp: MINUS error
#line 490 "parser.yy"
                  {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[1].location.begin.line, "Wrong expression");}
#line 1636 "/home/compiler/build/parser.cc"
    break;

  case 72: // Exp: NOT Exp
#line 491 "parser.yy"
              {
        struct Node* new_node = new Node(yystack_[1].location.begin.line,"Exp",Node::non_end,11);
        struct Node* NOT_node = new Node(yystack_[1].location.begin.line,"NOT",Node::end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),NOT_node,1);
        add_child(yylhs.value.as < Node* > (), yystack_[0].value.as < Node* > (),2);
    }
#line 1649 "/home/compiler/build/parser.cc"
    break;

  case 73: // Exp: NOT error
#line 499 "parser.yy"
                {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[1].location.begin.line, "Wrong expression");}
#line 1655 "/home/compiler/build/parser.cc"
    break;

  case 74: // Exp: ID LP Args RP
#line 500 "parser.yy"
                    {
        struct Node* new_node = new Node(yystack_[3].location.begin.line,"Exp",Node::non_end,12);
        struct Node* ID_node = new Node(yystack_[3].location.begin.line,"ID",Node::string_node);
        ID_node->type_string = yystack_[3].value.as < std::string > ();
        struct Node* LP_node = new Node(yystack_[2].location.begin.line,"LP",Node::end);
        struct Node* RP_node = new Node(yystack_[0].location.begin.line,"RP",Node::end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),ID_node,1);
        add_child(yylhs.value.as < Node* > (),LP_node,2);
        add_child(yylhs.value.as < Node* > (), yystack_[1].value.as < Node* > (),3);
        add_child(yylhs.value.as < Node* > (),RP_node,4);
    }
#line 1673 "/home/compiler/build/parser.cc"
    break;

  case 75: // Exp: ID LP Args error
#line 513 "parser.yy"
                       {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[3].location.begin.line, "Missing )");}
#line 1679 "/home/compiler/build/parser.cc"
    break;

  case 76: // Exp: ID LP RP
#line 514 "parser.yy"
               {
        struct Node* new_node = new Node(yystack_[2].location.begin.line,"Exp",Node::non_end,13);
        struct Node* ID_node = new Node(yystack_[2].location.begin.line,"ID",Node::string_node);
        ID_node->type_string = yystack_[2].value.as < std::string > ();
        struct Node* LP_node = new Node(yystack_[1].location.begin.line,"LP",Node::end);
        struct Node* RP_node = new Node(yystack_[0].location.begin.line,"RP",Node::end);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),ID_node,1);
        add_child(yylhs.value.as < Node* > (),LP_node,2);
        add_child(yylhs.value.as < Node* > (),RP_node,3);
    }
#line 1696 "/home/compiler/build/parser.cc"
    break;

  case 77: // Exp: ID LP error
#line 526 "parser.yy"
                  {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[2].location.begin.line, "Missing )");}
#line 1702 "/home/compiler/build/parser.cc"
    break;

  case 78: // Exp: Exp LB Exp RB
#line 527 "parser.yy"
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
#line 1718 "/home/compiler/build/parser.cc"
    break;

  case 79: // Exp: Exp LB error RB
#line 538 "parser.yy"
                      {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[3].location.begin.line, "Wrong expression");}
#line 1724 "/home/compiler/build/parser.cc"
    break;

  case 80: // Exp: Exp DOT ID
#line 539 "parser.yy"
                 {
        struct Node* new_node = new Node(yystack_[2].location.begin.line,"Exp",Node::non_end,15);
        struct Node* DOT_node = new Node(yystack_[1].location.begin.line,"DOT",Node::end);
        struct Node* ID_node = new Node(yystack_[0].location.begin.line,"ID",Node::string_node);
        ID_node->type_string = yystack_[0].value.as < std::string > ();
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),1);
        add_child(yylhs.value.as < Node* > (),DOT_node,2);
        add_child(yylhs.value.as < Node* > (),ID_node,3);
    }
#line 1740 "/home/compiler/build/parser.cc"
    break;

  case 81: // Exp: ID
#line 550 "parser.yy"
         {
        struct Node* new_node = new Node(yystack_[0].location.begin.line,"Exp",Node::non_end,16);
        struct Node* ID_node = new Node(yystack_[0].location.begin.line,"ID",Node::string_node);
        ID_node->type_string = yystack_[0].value.as < std::string > ();
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),ID_node,1);
    }
#line 1753 "/home/compiler/build/parser.cc"
    break;

  case 82: // Exp: "int"
#line 558 "parser.yy"
          {
        struct Node* new_node = new Node(yystack_[0].location.begin.line,"Exp",Node::non_end,17);
        struct Node* int_node = new Node(yystack_[0].location.begin.line,"INT",Node::int_node);
        int_node->type_int = yystack_[0].value.as < int > ();
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),int_node,1);
    }
#line 1766 "/home/compiler/build/parser.cc"
    break;

  case 83: // Exp: "float"
#line 566 "parser.yy"
            {
        struct Node* new_node = new Node(yystack_[0].location.begin.line,"Exp",Node::non_end,18);
        struct Node* float_node = new Node(yystack_[0].location.begin.line,"FLOAT",Node::float_node);
        float_node->type_float = yystack_[0].value.as < float > ();
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),float_node,1);

    }
#line 1780 "/home/compiler/build/parser.cc"
    break;

  case 84: // Exp: error RP
#line 575 "parser.yy"
               {fprintf(stderr, "ERROR type B at Line %d: %s\n", yystack_[1].location.begin.line, "Wrong expression");}
#line 1786 "/home/compiler/build/parser.cc"
    break;

  case 85: // Args: Exp COMMA Args
#line 577 "parser.yy"
                      {
    struct Node* new_node = new Node(yystack_[2].location.begin.line,"Args",Node::non_end,1);
    struct Node* COMMA_node = new Node(yystack_[1].location.begin.line,"COMMA",Node::end);
    yylhs.value.as < Node* > () = new_node;
    
    add_child(yylhs.value.as < Node* > (),yystack_[2].value.as < Node* > (),1);
    add_child(yylhs.value.as < Node* > (),COMMA_node,2);
    add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > (),3);
}
#line 1800 "/home/compiler/build/parser.cc"
    break;

  case 86: // Args: Exp
#line 586 "parser.yy"
          {
        struct Node* new_node = new Node(yystack_[0].location.begin.line,"Args",Node::non_end,2);
        yylhs.value.as < Node* > () = new_node;
        
        add_child(yylhs.value.as < Node* > (),yystack_[0].value.as < Node* > (),1);
    }
#line 1811 "/home/compiler/build/parser.cc"
    break;


#line 1815 "/home/compiler/build/parser.cc"

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
       0,    66,    66,    72,    78,    82,    90,    97,   104,   106,
     111,   119,   121,   128,   134,   146,   153,   155,   162,   166,
     175,   182,   194,   196,   208,   220,   228,   234,   242,   252,
     254,   260,   264,   271,   272,   273,   278,   288,   289,   290,
     303,   319,   334,   341,   345,   354,   355,   357,   363,   373,
     379,   388,   391,   400,   401,   410,   411,   420,   421,   430,
     431,   440,   441,   450,   451,   460,   461,   470,   471,   481,
     482,   490,   491,   499,   500,   513,   514,   526,   527,   538,
     539,   550,   558,   566,   575,   577,   586
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
#line 2527 "/home/compiler/build/parser.cc"

#line 595 "parser.yy"


void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
