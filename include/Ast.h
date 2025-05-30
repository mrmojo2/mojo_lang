#ifndef AST_H
#define AST_H

#include "Token.h"

class Expr{
public:
	Expr() = default;
	virtual void print(int depth) = 0;
	virtual void free() = 0;
	virtual ~Expr() = default;
};

class Integer : public Expr {
public:
	int value;

	Integer(int);
	void print(int);
	void free();
};

class Float : public Expr {
public:
	float value;

	Float(float);
	void print(int);
	void free();
};

class BinOp : public Expr {
public:
	Token op;
	Expr* left, *right;

	BinOp(Token op, Expr* left, Expr* right);
	void print(int);
	void free();
};

class UnOp : public Expr {
public:
	Token op;
	Expr* oprnd;

	UnOp(Token op, Expr* oprnd);
	void print(int);
	void free();
};

class GroupExpr : public Expr {
public:
	Expr* expr;

	GroupExpr(Expr* expr);
	void print(int);
	void free();
};



#endif
