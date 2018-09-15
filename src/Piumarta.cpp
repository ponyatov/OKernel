#include "Piumarta.hpp"

int main(int argc, char *argv[]) {
	cout << endl << "Piumarta object virtual machine: ";
   	cout << argv[0] << endl << endl;
	return yyparse();
}

#define YYERR "\n\n" << yylineno << ":" << msg << "[" << yytext << "]\n\n"
void yyerror(string msg) { cout << YYERR; cerr << YYERR ; exit(-1); }

