#include "Lexer.h"
#include "Token.h"
#include "utils.h"
#include <iostream>

bool is_num(char ch){
	return (ch >= '0' && ch <= '9');
}

bool is_alpha(char ch){
	return ((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <= 'Z'));
}

bool is_alnum(char ch){
	return (is_num(ch) || is_alpha(ch));
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
			while(peek() != '\n')
				advance();
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
		
		else if(ch == '>'){
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
		}else if(is_num(ch)){
			bool float_flag = false;
			while(1){
				char p = peek();
				if(p == '.') float_flag = true;
				else if(!is_num(p)) break;
				advance();
			}
			add_token(float_flag ? TOK_FLOAT:TOK_INTEGER);
		}else if(ch == '\'' || ch == '\"'){
			while(!match(ch)){
				advance();
				if(current_pointer >= source.length())
					error("Unterminated string",line);
			}
			//TODO: Check if the string is unterminated

			add_token(TOK_STRING);
		}else if(is_alpha(ch) || ch == '_'){
			while(is_alnum(peek()) || peek() == '_'){
				advance();
			}
			
			//check if indentifier is a keyword
			std::string id = source.substr(start_pointer,current_pointer - start_pointer );
			auto it = keywordmap.find(id);
			if(it == keywordmap.end())
				add_token(TOK_IDENTIFIER);
			else
				add_token(it->second);
				
		}else
			error(std::string("Unexpected token ")+ ch,line);
	}
}

void Lexer::add_token(Token_Type t){
	std::string lexeme = source.substr(start_pointer,current_pointer - start_pointer);
	tokens.push_back(Token(t,lexeme,line));
}

char Lexer::advance(){
	if(current_pointer >= source.length()) return '\0';
	return source[current_pointer++];
}

char Lexer::peek(){
	return source[current_pointer];	
}

char Lexer::lookahead(){
	if(current_pointer >= source.length()) return '\0';
	return source[current_pointer + 1];
}

bool Lexer::match(char expected){
	if(current_pointer >= source.length()) return false;
	if(source[current_pointer] != expected)
		return false;
	current_pointer++;
	return true;
}

void Lexer::error(std::string msg, int line){
	std::cout << Colors::red;
	std::cout << "[Line "<<line<<"] Lexer Error: "<<msg<<std::endl;
	std::cout << Colors::white;
	exit(1);
}
