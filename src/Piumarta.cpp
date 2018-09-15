#include "Piumarta.hpp"

std::vector<Object*>	*pool	=NULL;
Environment				*global	=NULL;
void init() {
	// pool must be initialized before any object created
		pool = new std::vector<Object*>; assert(pool);
	// create global environment
		global = new Environment("global"); assert(global);
	// patch global env: nest[]ed -> pool
		delete global->nest; global->nest = pool;
}	

int main(int argc, char *argv[]) {
	init();
	std::cout << std::endl << "Piumarta object virtual machine: ";
   	std::cout << argv[0] << std::endl << std::endl;
	yyparse();
	assert(global);
	std::cout << global->dump() << std::endl;
	return 0;
}

Object::Object(std::string T, std::string V) {
	tag=T; val=V;
	nest = new std::vector<Object*>; assert(nest);
	pool->push_back(this);
}

Symbol::Symbol(std::string V):Object("symbol",V){}

Object::Object(std::string V):Object("object",V){}

Object* Object::push(Object *o)	{ nest->push_back(o); return this; }
Object* Object::pop()			{ nest->pop_back(); }

std::string Object::head(std::string prefix) {
	std::ostringstream os;
	os << prefix << "<" << tag << ":" << val << "> @ " << this;
	return os.str(); }

std::map<Object*,bool> dumped;

std::string Object::dump(int depth)				{
	std::string S = pad(depth) + head()+"\n";
	for (auto j = nest->begin(), je=nest->end() ; j!=je ; j++)
		if ( !dumped[*j] )
			S += pad(depth+1) + (*j)->head("...");
		else {
			S += (*j)->dump(depth+1);
			dumped[*j] = true;
		}
	if (depth==0) dumped.clear();				// clean up memory after dump
	return S;
}

std::string Object::pad(int depth) {
	std::string S = "\n";
	for (int i=0;i<depth;i++) S += '\t';
	return S;
}

Environment::Environment(std::string V):Object("environment",V){}

