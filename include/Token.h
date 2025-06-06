#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <unordered_map>

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
	TOK_STRING,
/////////////////////////////////////////////////////
//	Keywords
//////////////////////////////////////////////////////
	TOK_IF,
	TOK_ELSE,
	TOK_THEN,
	TOK_TRUE,
	TOK_FALSE,
	TOK_AND,
	TOK_OR,
	TOK_WHILE,
	TOK_DO,
	TOK_FOR,
	TOK_FUNC,
	TOK_NULL,
	TOK_END,
	TOK_PRINT,
	TOK_PRINTLN,
	TOK_RET
};



/////////////////////////////////////////////////////////////
//	Hashmap of keywords and their token types
////////////////////////////////////////////////////////////	

extern std::unordered_map<std::string, Token_Type> keywordmap;

class Token{
public:
	int line;
	Token_Type type;
	std::string lexeme;
	
	Token(Token_Type,std::string,int line);
	Token(const Token &tok);
	
	void print();
};


#endif
