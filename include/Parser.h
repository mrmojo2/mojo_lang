#ifndef PARSER_H
#define PARSER_H

#include "Token.h"
#include "Ast.h"

#include <vector>


/////////////////////////////////////////////////////////////////
//		Context Free Grammer: 
//
//
// <expr>   ::= <term> (('+'|'-')<term>)*
// <term>   ::= <factor>(('*'|'/'<factor>)*
// <factor> ::= <unary>
// <unary>  ::= ('+'|'-'|'~')<unary> | <primary>
// <primary>::= <integer>  | <float> | '('<expr>')'
//
// /////////////////////////////////////////////////////////////

class Parser{
public:
	std::vector<Token> tokens;
	int current = 0;
	Expr* ast;

	Parser(std::vector<Token> );
	//TODO: free allocated memory of ast in deconstructor
	~Parser();

	Expr* parse();
	Expr* expr();
	Expr* term();
	Expr* factor();
	Expr* unary();
	Expr* primary();

	Token advance();	//consume current token
	Token previous_token();
	Token peek();    		//peek current token
	Token is_next(Token expected);	//check if next token matches expected
	bool match(Token_Type expected); 		//check if current token matches expected and if it does consume
	Token expect(Token expected);
};

#endif
