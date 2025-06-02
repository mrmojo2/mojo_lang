#include "Interpretor.h"


float Interpretor::interpret(Node* node){
	if(Integer* i = dynamic_cast<Integer*>(node)){
		return i->value;
	}else if(Float* f = dynamic_cast<Float*>(node)){
		return f->value;
	}else if(GroupExpr* g = dynamic_cast<GroupExpr*>(node)){
		return interpret(g->expr);
	}else if(BinOp* b = dynamic_cast<BinOp*>(node)){
		float leftvalue = interpret(b->left);
		float rightvalue = interpret(b->right);
		Token op = b->op;

		if(op.type == TOK_PLUS)
			return leftvalue + rightvalue;
		else if(op.type == TOK_MINUS)
			return leftvalue - rightvalue;
		else if(op.type == TOK_STAR)
			return leftvalue * rightvalue;
		else if(op.type == TOK_SLASH)
			return leftvalue / rightvalue;
	}else if(UnOp* u = dynamic_cast<UnOp*>(node)){
		float oprndvalue = interpret(u->oprnd);
		Token op = u->op;

		if(op.type == TOK_MINUS)
			return -oprndvalue;
		else if(op.type == TOK_PLUS)
			return oprndvalue;
			
	}
}
