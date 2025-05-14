#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum Token_Type{
///////////////////////////////////////////////
//	Single char tokens
//////////////////////////////////////////////
	TOK_COLON,		// :
	TOK_SEMICOLON,		// ;
	TOK_COMMA,		// ,
	TOK_DOT,		// .
	TOK_MOD,		// %
	TOK_QUES,		// ?
	TOK_NOT,		// ~
	TOK_GT,			// >
	TOK_LT,			// <
	TOK_LPAREN,		// (
	TOK_RPAREN,		// )
	TOK_LCURLY,		// {
	TOK_RCURLY,		// }
	TOK_LSQ,		// [
	TOK_RSQ,		// ]
	TOK_ASSIGN,		// =
	TOK_PLUS,		// +
	TOK_MINUS,		// -
	TOK_STAR,		// *
	TOK_SLASH,		// /
///////////////////////////////////////////////
//	Double char tokens
//////////////////////////////////////////////
	TOK_GE,			// >=
	TOK_LE,			// <=
	TOK_NE,			// ~=
	TOK_EQ,			// ==
	TOK_GTGT,		// >>
	TOK_LTLT,		// <<

////////////////////////////////////////////////////////
//	Literals
////////////////////////////////////////////////////////
	TOK_IDENTIFIER,	
	TOK_INTEGER,
	TOK_FLOAT,
	TOK_STRING
};

class Token{
public:
	int line;
	Token_Type type;
	std::string lexeme;
	
	Token(Token_Type,std::string,int line);
	
	void print();	
};


#endif
