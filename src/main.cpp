#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Lexer.h"
#include "Parser.h"
#include "Interpretor.h"
#include "utils.h"

int main(int argc, char **argv){
	if(argc != 2){
		std::cerr<<"Usage: mlcompiler <source>\n";
		return 1;
	}

	//open the source file
	std::ifstream source_file(argv[1]);
	if(!source_file.is_open()){
		std::cerr << "Error: failed to open file\n";
		return 1;
	}

	//storing the contents of the source file into a string for lexical analysis
	std::stringstream buffer;
	buffer << source_file.rdbuf();
	std::string source_code = buffer.str();

	//lexical analysis
	Lexer l(source_code);
	l.tokenize();
	for(auto token : l.tokens){
		token.print();
	}	

	//parsing the tokens
	Parser p(l.tokens);
	Node* ast = p.parse();
	std::cout <<"Ast:";
	p.ast->print(0);
	std::cout << std::endl;
	
	//interpreting 
	Interpretor i;
	Type* value = i.interpret(ast);
	value->printvalue();
	std::cout << std::endl;


	//freeing value:
	delete value;
	return 0;
}
