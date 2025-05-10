#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Lexer.h"

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
	Lexer l;
	l.tokenize(source_code);

	return 0;
}
