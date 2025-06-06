#ifndef TYPES_H
#define TYPES_H

//seems unnecessary...could just reuse Ast classes


#include <string>

enum class TypeName {
	number,
	string,
	boolean
};


class Type{
public:
	TypeName type;
	Type(TypeName type);
	virtual ~Type() = default;
	virtual void printvalue() = 0;
};

class NumberType: public Type{
public:
	float value;
	NumberType(float value);
	void printvalue();
};

class StringType : public Type{
public:
	std::string value;
	StringType(std::string value);
	void printvalue();
};

class BoolType : public Type{
public:
	bool value;

	BoolType(bool value);
	void printvalue();
};

std::string get_typename_str(TypeName t);

#endif
