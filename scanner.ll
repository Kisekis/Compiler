%{ /* -*- C++ -*- */
# include <cerrno>
# include <climits>
# include <cstdlib>
# include <cstring> // strerror
# include <string>
# include "driver.hh"
# include "parser.hh"
bool error = false;
%}

%option noyywrap nounput noinput batch debug

%{
  // A number symbol corresponding to the value in S.
  yy::parser::symbol_type
  make_INT (const std::string &s, const yy::parser::location_type& loc);
  yy::parser::symbol_type
  make_FLOAT (const std::string &s, const yy::parser::location_type& loc);
%}

digit [0-9]
positive [1-9]
letter [_a-zA-Z]
octal [0-7]
hex [0-9A-Fa-f]
numdot [0-9.]
extern int yylineno;

%{
  // Code run each time a pattern is matched.
  # define YY_USER_ACTION  loc.columns (yyleng);
%}
%%
%{
  // A handy shortcut to the location held by the driver.
  yy::location& loc = drv.location;
  // Code run each time yylex is called.
  loc.step ();
%}
\n+        loc.lines (yyleng); loc.step ();
[ \t]	;
"int"|"float" {return yy::parser::make_TYPE (yytext, loc);}
"struct" {return yy::parser::make_STRUCT (loc);}
"return" {return yy::parser::make_RETURN(loc);}
"if" {return yy::parser::make_IF(loc);}
"else" {return yy::parser::make_ELSE(loc);}
"while" {return yy::parser::make_WHILE(loc);}

{letter}+({digit}|{letter})* {return yy::parser::make_ID (yytext, loc);}


"0"|{positive}{digit}* {return make_INT (yytext, loc);}
"0"{octal}+ {return make_INT (yytext, loc);}
("0x"|"0X")({hex}+) {return make_INT (yytext, loc);}



("0"|{positive}{digit}*)\.{digit}+ {return make_FLOAT (yytext, loc);}
{digit}+\.{digit}*("E"|"e")(("+"|"-")?){digit}+ {return make_FLOAT (yytext, loc);}
{digit}*\.{digit}+("E"|"e")(("+"|"-")?){digit}+ {return make_FLOAT (yytext, loc);}
"." {return yy::parser::make_DOT(loc);}
{digit}{numdot}+("E"|"e")(("+"|"-")?){numdot}* {error = true;printf("Error type A at Line %d: Mysterious characters \'%s\'\n",yylineno, yytext);return make_FLOAT (yytext, loc);}

("0"|{positive}{digit}*)(\.{digit}+)+ {error = true;printf("Error type A at Line %d: Mysterious characters \'%s\'\n",yylineno, yytext);return make_FLOAT (yytext, loc);}


";"	{return yy::parser::make_SEMI(loc);}
"," {return yy::parser::make_COMMA(loc);}
"=" {return yy::parser::make_ASSIGNOP(loc);}
">"|"<"|">="|"<="|"=="|"!=" {return yy::parser::make_RELOP(loc);}
"+" {return yy::parser::make_PLUS(loc);}
"-" {return yy::parser::make_MINUS  (loc);}
"*" {return yy::parser::make_STAR(loc);}
"/" {return yy::parser::make_DIV(loc);}
"&&" {return yy::parser::make_AND(loc);}
"||" {return yy::parser::make_OR(loc);}

"!" {return yy::parser::make_NOT(loc);}

"(" {return yy::parser::make_LP(loc);}
")" {return yy::parser::make_RP(loc);}
"[" {return yy::parser::make_LB(loc);}
"]" {return yy::parser::make_RB(loc);}
"{" {return yy::parser::make_LC(loc);}
"}" {return yy::parser::make_RC(loc);}

. {
    error = true;
    printf("Error type A at Line %d: Mysterious characters \'%s\'\n",yylineno, yytext);
}
<<EOF>>    return yy::parser::make_YYEOF (loc);
%%

yy::parser::symbol_type
make_INT (const std::string &s, const yy::parser::location_type& loc)
{
  errno = 0;
  long n = strtol (s.c_str(), NULL, 10);
  if (! (INT_MIN <= n && n <= INT_MAX && errno != ERANGE))
    throw yy::parser::syntax_error (loc, "integer is out of range: " + s);
  return yy::parser::make_INT ((int) n, loc);
}
yy::parser::symbol_type
make_FLOAT (const std::string &s, const yy::parser::location_type& loc)
{
  errno = 0;
  float n = stof(s);
  return yy::parser::make_FLOAT ((float) n, loc);
}

void
driver::scan_begin ()
{
  yy_flex_debug = trace_scanning;
  if (file.empty () || file == "-")
    yyin = stdin;
  else if (!(yyin = fopen (file.c_str (), "r")))
    {
      std::cerr << "cannot open " << file << ": " << strerror (errno) << '\n';
      exit (EXIT_FAILURE);
    }
}

void
driver::scan_end ()
{
  fclose (yyin);
}