#ifndef Piumarta_H_
#define Piumarta_H_

#include <iostream>
#include <cstdlib>

// Piumarta core Object

struct Object {
	std::string tag;									// type/class tag
	std::string val;									// primitive value

	Object(std::string V);
	Object(std::string T, std::string V);				// <T:V> constructor
														
	virtual std::string dump(int depth=0);				// dump object in tree
	virtual std::string head(std::string prefix="");	// with header only
};

// lexer/parser interface

extern int yylex();					// get next lexer token
extern int yylineno;				// line number
extern char* yytext;				// lexeme string

#define TOC(C,X)	{ yylval.o = new C(yytext); return X; }	/* token */

extern int yyparse();				// run syntax parser
extern void yyerror(std::string);	// error callback
#include "Piumarta.tab.hpp"

#endif // Piumarta_H_

