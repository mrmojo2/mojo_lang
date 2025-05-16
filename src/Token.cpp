#include "Token.h"

#include <iostream>

Token::Token(Token_Type type,std::string lexeme, int line):type(type),lexeme(lexeme),line(line){}

/////////////////////////////////////////////////////////////
//	Hashmap of keywords and their token types
////////////////////////////////////////////////////////////	

std::unordered_map<std::string, Token_Type> keywordmap = {
	{"if", TOK_IF},
	{"else", TOK_ELSE},
	{"then", TOK_THEN},
	{"true", TOK_TRUE},
	{"false", TOK_FALSE},
	{"and", TOK_AND},
	{"or", TOK_OR},
	{"while", TOK_WHILE},
	{"do", TOK_DO},
	{"for", TOK_FOR},
	{"func", TOK_FUNC},
	{"null", TOK_NULL},
	{"end", TOK_END},
	{"print", TOK_PRINT},
	{"println", TOK_PRINTLN},
	{"ret", TOK_RET}
};

void Token::print() {
    std::string type_str = "UNKNOWN_TOKEN";

    switch (type) {
        // Single char tokens
        case TOK_COLON:      type_str = "TOK_COLON"; break;
        case TOK_SEMICOLON:  type_str = "TOK_SEMICOLON"; break;
        case TOK_COMMA:      type_str = "TOK_COMMA"; break;
        case TOK_DOT:        type_str = "TOK_DOT"; break;
        case TOK_MOD:        type_str = "TOK_MOD"; break;
        case TOK_QUES:       type_str = "TOK_QUES"; break;
        case TOK_NOT:        type_str = "TOK_NOT"; break;
        case TOK_GT:         type_str = "TOK_GT"; break;
        case TOK_LT:         type_str = "TOK_LT"; break;
        case TOK_LPAREN:     type_str = "TOK_LPAREN"; break;
        case TOK_RPAREN:     type_str = "TOK_RPAREN"; break;
        case TOK_LCURLY:     type_str = "TOK_LCURLY"; break;
        case TOK_RCURLY:     type_str = "TOK_RCURLY"; break;
        case TOK_LSQ:        type_str = "TOK_LSQ"; break;
        case TOK_RSQ:        type_str = "TOK_RSQ"; break;
        case TOK_ASSIGN:     type_str = "TOK_ASSIGN"; break;
        case TOK_PLUS:       type_str = "TOK_PLUS"; break;
        case TOK_MINUS:      type_str = "TOK_MINUS"; break;
        case TOK_STAR:       type_str = "TOK_STAR"; break;
        case TOK_SLASH:      type_str = "TOK_SLASH"; break;

        // Double char tokens
        case TOK_GE:         type_str = "TOK_GE"; break;
        case TOK_LE:         type_str = "TOK_LE"; break;
        case TOK_NE:         type_str = "TOK_NE"; break;
        case TOK_EQ:         type_str = "TOK_EQ"; break;
        case TOK_GTGT:       type_str = "TOK_GTGT"; break;
        case TOK_LTLT:       type_str = "TOK_LTLT"; break;

        // Literals
        case TOK_IDENTIFIER: type_str = "TOK_IDENTIFIER"; break;
        case TOK_INTEGER:    type_str = "TOK_INTEGER"; break;
        case TOK_FLOAT:      type_str = "TOK_FLOAT"; break;
        case TOK_STRING:     type_str = "TOK_STRING"; break;

        // Keywords
        case TOK_IF:         type_str = "TOK_IF"; break;
        case TOK_ELSE:       type_str = "TOK_ELSE"; break;
        case TOK_THEN:       type_str = "TOK_THEN"; break;
        case TOK_TRUE:       type_str = "TOK_TRUE"; break;
        case TOK_FALSE:      type_str = "TOK_FALSE"; break;
        case TOK_AND:        type_str = "TOK_AND"; break;
        case TOK_OR:         type_str = "TOK_OR"; break;
        case TOK_WHILE:      type_str = "TOK_WHILE"; break;
        case TOK_DO:         type_str = "TOK_DO"; break;
        case TOK_FOR:        type_str = "TOK_FOR"; break;
        case TOK_FUNC:       type_str = "TOK_FUNC"; break;
        case TOK_NULL:       type_str = "TOK_NULL"; break;
        case TOK_END:        type_str = "TOK_END"; break;
        case TOK_PRINT:      type_str = "TOK_PRINT"; break;
        case TOK_PRINTLN:    type_str = "TOK_PRINTLN"; break;
        case TOK_RET:        type_str = "TOK_RET"; break;
    }

    std::cout << "( " << type_str << ", " << lexeme << ", " << line << " )" << std::endl;
}

