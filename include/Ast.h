#ifndef AST_H
#define AST_H

#include "Token.h"

class Expr{
public:
	Expr() = default;
	virtual void print() = 0;
	virtual ~Expr() = default;
};

class Integer : public Expr {
public:
	int value;

	Integer(int);
	void print();
};

class Float : public Expr {
public:
	float value;

	Float(float);
	void print();
};

class BinOp : public Expr {
public:
	Token op;
	Expr* left, *right;

	BinOp(Token op, Expr* left, Expr* right);
	void print();
};

class UnOp : public Expr {
public:
	Token op;
	Expr* oprnd;

	UnOp(Token op, Expr* oprnd);
	void print();
};



#endif
