#ifndef Piumarta_H_
#define Piumarta_H_

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <map>
#include <cassert>

// Piumarta core Object

struct Object {

	std::string tag;								// type/class tag
	std::string val;								// primitive value

	Object(std::string V);
	Object(std::string T, std::string V);			// <T:V> constructor

	std::vector<Object*> *nest;						// ordered container
													// (AST nest[]ed elements)
	Object* push(Object*);							// push to nest[] as stack
	Object* pop();									// pop from nest[] as stack

	std::map<std::string,Object*> attr;				// named object slots
														
	virtual std::string dump(int depth=0);			// dump object in tree
	virtual std::string head(std::string prefix="");// with header only
	std::string pad(int depth);						// pad tree with tabs

};

extern std::vector<Object*> *pool;					// global object pool

struct Environment:Object { Environment(std::string V); };

extern Environment *global;							// global environment

struct Symbol:Object	{ Symbol(std::string V); };

// lexer/parser interface

extern int yylex();					// get next lexer token
extern int yylineno;				// line number
extern char* yytext;				// lexeme string

#define TOC(C,X)	{ yylval.o = new C(yytext); return X; }	/* token */

extern int yyparse();				// run syntax parser
extern void yyerror(std::string);	// error callback
#include "Piumarta.tab.hpp"

#endif // Piumarta_H_

