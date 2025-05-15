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
		else if(ch == '/')	add_token(TOK_SLASH);
		else if(ch == ':')	add_token(TOK_COLON);
		else if(ch == ';')	add_token(TOK_SEMICOLON);
		else if(ch == ',')	add_token(TOK_COMMA);
		else if(ch == '.')	add_token(TOK_DOT);
		else if(ch == '%')	add_token(TOK_MOD);
		else if(ch == '?')	add_token(TOK_QUES);
		else if(ch == '(')	add_token(TOK_LPAREN);
		else if(ch == ')')	add_token(TOK_RPAREN);
		else if(ch == '[')	add_token(TOK_LSQ);
		else if(ch == ']')	add_token(TOK_RSQ);
		else if(ch == '{')	add_token(TOK_LCURLY);
		else if(ch == '}')	add_token(TOK_RCURLY);

		//TODO:fill this for all other single char tokens
		
		else if(is_num(ch)){
			while(is_num(peek())){ advance();}
			add_token(TOK_INTEGER);
		}else if(ch == '>'){
			if(match('=')) 		add_token(TOK_GE);
			else if(match('>'))	add_token(TOK_GTGT);
			else			add_token(TOK_GT);
			
		}else if(ch == '<'){
			if(match('='))		add_token(TOK_LE);
			else if(match('<'))	add_token(TOK_LTLT);
			else			add_token(TOK_LT);
		}else if(ch == '='){
			if(match('='))		add_token(TOK_EQ);
			else 			add_token(TOK_ASSIGN);
		}else if(ch == '~'){
			if(match('='))		add_token(TOK_NE);
			else			add_token(TOK_NOT);
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
	if(current_pointer + 1 < source.length())
		return source[current_pointer + 1];
	return '\0';	
}

bool Lexer::match(char expected){
	if(source[current_pointer] != expected)
		return false;
	current_pointer++;
	return true;
}
