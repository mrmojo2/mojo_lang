#include "Token.h"

#include <iostream>

Token::Token(Token_Type type,std::string lexeme):type(type),lexeme(lexeme){}

void Token::print(){
	std::cout<<type<<","<<lexeme<<std::endl;
}
