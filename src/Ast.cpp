#include "Ast.h"

#include <iostream>
Node::Node(int line):line(line){}

Expr::Expr(int line):Node(line){}

Integer::Integer(int value,int line) : value(value),Expr(line) {}

void Integer::print(int depth){
	std::cout << std::endl;
	for(int i=0; i<depth; ++i) std::cout << "  ";
	std::cout << "Integer ["<<value<<"]";
}

void Integer::free(){}


Float::Float(float value,int line) : value(value),Expr(line) {}

void Float::print(int depth){
	std::cout << std::endl;
	for(int i=0; i<depth; ++i) std::cout << "  ";
	std::cout << "Float ["<<value<<"]";
}

void Float::free(){}

BinOp::BinOp(Token op, Expr* left, Expr* right,int line) : op(op),left(left),right(right),Expr(line){}

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

void BinOp::free(){
	left->free();
	right->free();
	delete left;
	delete right;
}

UnOp::UnOp(Token op, Expr* oprnd,int line) : op(op),oprnd(oprnd),Expr(line){}

void UnOp::print(int depth){
	std::cout << std::endl;
	for(int i=0; i<depth; ++i) std::cout << "  ";
	std::cout << "UnOp ["<<op.lexeme<<",";
	oprnd->print(depth+1);
	std::cout << std::endl;
	for(int i=0; i<depth; ++i) std::cout << "  ";
	std::cout<<"]";
}

void UnOp::free(){
	oprnd->free();
	delete oprnd;
}

GroupExpr::GroupExpr(Expr* expr,int line) : expr(expr),Expr(line){}

void GroupExpr::print(int depth){
	std::cout << std::endl;
	for(int i=0; i<depth; ++i) std::cout << "  ";
	std::cout << "GroupedExpr[";
	expr->print(depth+1);
	std::cout << std::endl;
	for(int i=0; i<depth; ++i) std::cout << "  ";
	std::cout <<"]";
}

void GroupExpr::free(){
	expr->free();
	delete expr;
}

Bool::Bool(bool value, int line) : value(value),Expr(line){}

void Bool::print(int depth){
	std::cout << std::endl;
	for(int i=0; i<depth; ++i) std::cout << "  ";
	std::cout << "Bool["<<value<<"]";
}

void Bool::free(){}

String::String(std::string value, int line) : value(value),Expr(line){}

void String::print(int depth){
	std::cout << std::endl;
	for(int i=0; i<depth; ++i) std::cout << "  ";
	std::cout << "String["<<value<<"]";
}
 void String::free(){}


