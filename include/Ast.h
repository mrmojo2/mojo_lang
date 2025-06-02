#ifndef AST_H
#define AST_H

#include "Token.h"

class Node {
public:
	virtual void print(int depth) = 0;
	virtual void free() = 0;
	int line;

	Node(int line);
};

class Expr : public Node{
public:
	Expr(int line);
	virtual ~Expr() = default;
};

class Integer : public Expr {
public:
	int value;

	Integer(int value, int line);
	void print(int);
	void free();
};

class Float : public Expr {
public:
	float value;

	Float(float value, int line);
	void print(int);
	void free();
};

class BinOp : public Expr {
public:
	Token op;
	Expr* left, *right;

	BinOp(Token op, Expr* left, Expr* right,int line);
	void print(int);
	void free();
};

class UnOp : public Expr {
public:
	Token op;
	Expr* oprnd;

	UnOp(Token op, Expr* oprnd,int line);
	void print(int);
	void free();
};

class GroupExpr : public Expr {
public:
	Expr* expr;

	GroupExpr(Expr* expr,int line);
	void print(int);
	void free();
};



#endif
