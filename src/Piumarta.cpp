#include "Piumarta.hpp"

int main(int argc, char *argv[]) {
	std::cout << std::endl << "Piumarta object virtual machine: ";
   	std::cout << argv[0] << std::endl << std::endl;
	return yyparse();
}

Object::Object(std::string T, std::string V) { tag=T; val=V; }
Object::Object(std::string V):Object("object",V){}

std::string Object::head(std::string prefix) { return head(); }
std::string Object::dump(int depth) { return "<"+tag+":"+val+">\n"; }

