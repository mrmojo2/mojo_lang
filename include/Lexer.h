#ifndef LEXER_H
#define LEXER_H

#include "Token.h"

#include <vector>
#include <string>

class Lexer{
	std::vector<Token> tokens;
public:
	Lexer() = default;
	void tokenize(std::string source);
};


#endif
