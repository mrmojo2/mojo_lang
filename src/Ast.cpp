#include "Ast.h"

#include <iostream>


Integer::Integer(int value) : value(value) {}

void Integer::print(int depth){
	std::cout << std::endl;
	for(int i=0; i<depth; ++i) std::cout << "  ";
	std::cout << "Integer ["<<value<<"]";
}


Float::Float(float value) : value(value) {}

void Float::print(int depth){
	std::cout << std::endl;
	for(int i=0; i<depth; ++i) std::cout << "  ";
	std::cout << "Float ["<<value<<"]";
}

BinOp::BinOp(Token op, Expr* left, Expr* right) : op(op),left(left),right(right){}

void BinOp::print(int depth){
	std::cout << std::endl;
	for(int i=0; i<depth; ++i) std::cout << "  ";
	std::cout << "BinOp ["<<op.lexeme<<",";
	left->print(depth+1);
	std::cout<<",";
	right->print(depth+1);
	std::cout << std::endl;
	for(int i=0; i<depth; ++i) std::cout << "  ";
	std::cout<<"]";
}

UnOp::UnOp(Token op, Expr* oprnd) : op(op),oprnd(oprnd){}

void UnOp::print(int depth){
	std::cout << std::endl;
	for(int i=0; i<depth; ++i) std::cout << "  ";
	std::cout << "UnOp ["<<op.lexeme<<",";
	oprnd->print(depth+1);
	std::cout << std::endl;
	for(int i=0; i<depth; ++i) std::cout << "  ";
	std::cout<<"]";
}

GroupExpr::GroupExpr(Expr* expr) : expr(expr){}

void GroupExpr::print(int depth){
	std::cout << std::endl;
	std::cout << "GroupedExpr[";
	expr->print(depth+1);
	std::cout << std::endl;
	for(int i=0; i<depth; ++i) std::cout << "  ";
	std::cout <<"]";
}
