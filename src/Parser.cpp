#include "Parser.h"
#include "utils.h"
#include <iostream>

Parser::Parser(std::vector<Token> tokens):tokens(tokens){}

Parser::~Parser(){
	ast->free();
	delete ast;	
}


Token Parser::advance(){
	if(current < tokens.size()){
		Token curr = tokens[current];
		current++;
		return curr;
	}
	return Token(TOK_NULL,"null",0);
}

Token Parser::peek(){
	return tokens[current];
}

bool Parser::match(Token_Type t){
	if(current >= tokens.size()){
		return false;
	}
	Token curr = tokens[current];
	if(curr.type== t){
		current++;
		return true;
	}
	return false;
}

Token Parser::previous_token(){
	if(current > 0)
		return tokens[current-1];
	return Token(TOK_NULL,"null",0);
}

Expr* Parser::parse(){
	ast = expr();
	return ast;
}

// <expr> ::= <term>(('+'|'-')<term>)*
Expr* Parser::expr(){
	Expr* e = term();
	while(match(TOK_PLUS) || match(TOK_MINUS)){
		Token op = previous_token();
		Expr* right = term();
		e = new BinOp(op,e,right,previous_token().line);
	}
	return e;
}

// <term>   ::= <factor>(('*'|'/'<factor>)*
Expr* Parser::term(){
	Expr* e = factor();
	while(match(TOK_SLASH) || match(TOK_STAR)){
		Token op = previous_token();
		Expr* right = factor();
		e = new BinOp(op,e,right,previous_token().line);
	}
	return e;
}

//<factor> ::= <unary>
Expr* Parser::factor(){
	return unary();
}

// <unary>  ::= ('+'|'-'|'~')<unary> | <primary>
Expr* Parser::unary(){
	if(match(TOK_PLUS) || match(TOK_MINUS) || match(TOK_NOT) ){
		Token op = previous_token();
		Expr* operand = unary();
		return new UnOp(op,operand,previous_token().line);
	}
	return primary();
}


// <primary>::= <integer>  | <float> | <bool> | <string> |'('<expr>')'
Expr* Parser::primary(){
	if(match(TOK_INTEGER)){
		int value = std::stoi(previous_token().lexeme);
		return new Integer(value,previous_token().line);
	}else if(match(TOK_FLOAT)){
		float value = std::stof(previous_token().lexeme);
		return  new Float(value,previous_token().line);
	}else if(match(TOK_TRUE)){
		return new Bool(true,previous_token().line);
	}else if(match(TOK_FALSE)){
		return new Bool(false,previous_token().line);
	}else if(match(TOK_STRING)){
		std::string original = previous_token().lexeme;
		std::string s = original.substr(1,original.length()-2);
		return new String(s,previous_token().line);
	}else if(match(TOK_LPAREN)){
		Expr* e = expr();
		if(!match(TOK_RPAREN)){
			//throw std::runtime_error("Expected )");
			error("Expected )",previous_token().line);
		}else{
			return new GroupExpr(e,previous_token().line);
		}
	}

}

void Parser::error(std::string msg, int line){
	std::cout << Colors::red;
	std::cout << "[Line "<<line<<"] Error: "<<msg<<std::endl;
	std::cout << Colors::white;
	exit(1);
}



