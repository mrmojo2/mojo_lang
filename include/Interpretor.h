#ifndef INTRPRTR_H
#define INTRPRTR_H

#include "Ast.h"

class Interpretor{
public:
	Interpretor() = default;

	float interpret(Node* node);
};

#endif
