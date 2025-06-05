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
};

class NumberType: public Type{
public:
	float value;
	NumberType(float value);
};

class StringType : public Type{
public:
	std::string value;
	StringType(std::string value);
};

class BoolType : public Type{
public:
	bool value;

	BoolType(bool value);
};

std::string get_typename_str(TypeName t);

#endif
