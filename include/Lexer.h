#ifndef LEXER_H
#define LEXER_H

#include "Token.h"

#include <vector>
#include <string>

class Lexer{
	int line = 1;
	int start_pointer = 0;
	int current_pointer = 0;
	std::string source;
public:
	std::vector<Token> tokens;
	
	Lexer(std::string source);
	
	void error(std::string,int);	
	void tokenize();
	char advance();			//advances the current_pointer, comsumes the charecter
	char peek();			//peek at current charecter
	char lookahead();		//peek at next charecter
	bool match(char expected);	//check if current charecter matches and expectation, comsumes the charecter if match is true
	void add_token(Token_Type t);	//add tokens to tokens array
};


#endif
