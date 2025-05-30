#include "Ast.h"

#include <iostream>


Integer::Integer(int value) : value(value) {}

void Integer::print(){
	std::cout << "Integer ["<<value<<"]";
}


Float::Float(float value) : value(value) {}

void Float::print(){
	std::cout << "Float ["<<value<<"]";
}

BinOp::BinOp(Token op, Expr* left, Expr* right) : op(op),left(left),right(right){}

void BinOp::print(){
	std::cout << "BinOp ["<<op.lexeme<<",";
	left->print();
	std::cout<<",";
	right->print();
	std::cout<<"]";
}

UnOp::UnOp(Token op, Expr* oprnd) : op(op),oprnd(oprnd){}

void UnOp::print(){
	std::cout << "UnOp ["<<op.lexeme<<",";
	oprnd->print();
	std::cout<<"]";
}
