#ifndef INTRPRTR_H
#define INTRPRTR_H

#include <memory>
#include <iostream>

#include "Ast.h"
#include "Types.h"

class Interpretor{
public:
	Interpretor() = default;
	
	std::unique_ptr<Type> interpret(Node* node);
	void error(std::string msg, int line);
};

#endif
