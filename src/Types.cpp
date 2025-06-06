#include "Types.h"
#include <iostream>

Type::Type(TypeName type) : type(type){}
NumberType::NumberType(float value) : Type(TypeName::number),value(value){}
StringType::StringType(std::string value) : Type(TypeName::string),value(value) {}
BoolType::BoolType(bool value) :Type(TypeName::boolean),value(value){}



void NumberType::printvalue(){
	std::cout << value ;
}

void StringType::printvalue(){
	std::cout << value ;
}

void BoolType::printvalue(){
	if(value) std::cout << "true";
	else std::cout << "false";
}
std::string get_typename_str(TypeName t){
	std::string result;

	switch(t){
		case TypeName::number:
			result = "number";
			break;
		case TypeName::string:
			result = "string";
			break;
		case TypeName::boolean:
			result = "boolean";
			break;
	}
	return result;
}

