#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum Token_Type{
	TOK_IDENTIFIER,
	TOK_INTEGER,
	TOK_SEMICOLON,
	TOK_LPAREN,
	TOK_RPAREN,
	TOK_LBRACE,
	TOK_RBRACE,
	TOK_EQ,
	TOK_PLUS,
	TOK_MINUS,
	TOK_MUL,
	TOK_DIV
};

class Token{
	Token_Type type;
	std::string lexeme;
public:
	Token(Token_Type,std::string);
	
	void print();	
};


#endif
