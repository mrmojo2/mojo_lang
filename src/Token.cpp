#include "Token.h"

#include <iostream>

Token::Token(Token_Type type,std::string lexeme, int line):type(type),lexeme(lexeme),line(line){}

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
    }

    std::cout << "( " << type_str << ", " << lexeme << " )" << std::endl;
}

