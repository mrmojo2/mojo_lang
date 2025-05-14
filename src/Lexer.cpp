#include "Lexer.h"

#include <iostream>

bool is_num(char ch){
	return (ch >= '0' && ch <= '9');
}

Lexer::Lexer(std::string source):source(source){}

void Lexer::tokenize(){
	while(current_pointer < source.length()){
		start_pointer = current_pointer;
		char ch = advance();
		
		if(ch == '\n')		line++;
		else if(ch == '\t')	continue;
		else if(ch == ' ')	continue;
		else if(ch == '#')
			while(advance() != '\n'){}
		else if(ch == '+')	add_token(TOK_PLUS);
		else if(ch == '-')	add_token(TOK_MINUS);
		else if(ch == '*')	add_token(TOK_STAR);
		else if(ch == '(')	add_token(TOK_LPAREN);
		else if(ch == ')')	add_token(TOK_RPAREN);

		//TODO:fill this for all other single char tokens
		
		else if(is_num(ch)){
			while(is_num(lookahead())) advance();
			advance();
			add_token(TOK_INTEGER);
		}else if(ch == '>'){
			if(lookahead() == '='){
				advance();
				add_token(TOK_GE);
			}else{
				add_token(TOK_GT);
			}
		}
	}
}

void Lexer::add_token(Token_Type t){
	std::string lexeme = source.substr(start_pointer,current_pointer - start_pointer);
	tokens.push_back(Token(t,lexeme,line));
}

char Lexer::advance(){
	char cur = source[current_pointer++];
	return cur;
}

char Lexer::peek(){
	return source[current_pointer];	
}

char Lexer::lookahead(){
	return source[current_pointer + 1];	
}

bool Lexer::match(char expected){
	if(source[current_pointer] != expected)
		return false;
	current_pointer++;
	return true;
}
