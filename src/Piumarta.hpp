#ifndef Piumarta_H_
#define Piumarta_H_

#include <iostream>
#include <cstdlib>

using namespace std;

// lexer/parser interface

extern int yylex();				// get next lexer token
extern int yylineno;			// line number
extern char* yytext;			// lexeme string

extern int yyparse();			// run syntax parser
extern void yyerror(string);	// error callback
#include "Piumarta.tab.hpp"

#endif // Piumarta_H_

