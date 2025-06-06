#ifndef INTRPRTR_H
#define INTRPRTR_H

#include <memory>
#include <iostream>

#include "Ast.h"
#include "Types.h"

class Interpretor{
public:
	Interpretor() = default;
	
	Type* interpret(Node* node);
	void error(std::string msg, int line);
	void binop_unsupported_err(std::string lexeme,TypeName left_type, TypeName right_type,int line);
	void unop_unsupported_err(std::string lexeme,TypeName oprnd_type,int line);
};

#endif
