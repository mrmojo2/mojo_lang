#include "Interpretor.h"

#include "utils.h"


std::unique_ptr<Type> Interpretor::interpret(Node* node){
	if(Integer* i = dynamic_cast<Integer*>(node)){
		return std::make_unique<NumberType>(i->value);
	}else if(Float* f = dynamic_cast<Float*>(node)){
		return std::make_unique<NumberType>(f->value);
	}else if(GroupExpr* g = dynamic_cast<GroupExpr*>(node)){
		return interpret(g->expr);
	}else if(BinOp* b = dynamic_cast<BinOp*>(node)){
		std::unique_ptr<Type> left_type = interpret(b->left);
		std::unique_ptr<Type> right_type = interpret(b->right);
		Token op = b->op;
//TODO: keep this repeated code in another function
		if(op.type == TOK_PLUS){
			if(left_type->type == TypeName::number && right_type->type == TypeName::number){
				std::unique_ptr<NumberType> left_number = downcast_unique_ptr<NumberType>(left_type); 
				std::unique_ptr<NumberType> right_number = downcast_unique_ptr<NumberType>(right_type); 
				return std::make_unique<NumberType>(left_number->value + right_number->value);
			}else{
				error(std::string("Unsupported operator ")+op.lexeme+std::string("between operands ")+get_typename_str(left_type->type)+std::string("and ")+get_typename_str(right_type->type),op.line);
				//TODO:node ma line no store gareko ta kam nai bhaena ta
			}
		}else if(op.type == TOK_MINUS){
			if(left_type->type == TypeName::number && right_type->type == TypeName::number){
				std::unique_ptr<NumberType> left_number = downcast_unique_ptr<NumberType>(left_type); 
				std::unique_ptr<NumberType> right_number = downcast_unique_ptr<NumberType>(right_type); 
				return std::make_unique<NumberType>(left_number->value - right_number->value);
			}else{
				error(std::string("Unsupported operator ")+op.lexeme+std::string("between operands ")+get_typename_str(left_type->type)+std::string("and ")+get_typename_str(right_type->type),op.line);
			}
		}else if(op.type == TOK_STAR){
			if(left_type->type == TypeName::number && right_type->type == TypeName::number){
				std::unique_ptr<NumberType> left_number = downcast_unique_ptr<NumberType>(left_type); 
				std::unique_ptr<NumberType> right_number = downcast_unique_ptr<NumberType>(right_type); 
				return std::make_unique<NumberType>(left_number->value * right_number->value);
			}else{
				error(std::string("Unsupported operator ")+op.lexeme+std::string("between operands ")+get_typename_str(left_type->type)+std::string("and ")+get_typename_str(right_type->type),op.line);
			}
		}else if(op.type == TOK_SLASH){
			if(left_type->type == TypeName::number && right_type->type == TypeName::number){
				std::unique_ptr<NumberType> left_number = downcast_unique_ptr<NumberType>(left_type); 
				std::unique_ptr<NumberType> right_number = downcast_unique_ptr<NumberType>(right_type); 
				return std::make_unique<NumberType>(left_number->value / right_number->value);
			}else{
				error(std::string("Unsupported operator ")+op.lexeme+std::string("between operands ")+get_typename_str(left_type->type)+std::string("and ")+get_typename_str(right_type->type),op.line);
			}
		}
	}else if(UnOp* u = dynamic_cast<UnOp*>(node)){
		std::unique_ptr<Type> oprnd_type = interpret(u->oprnd);
		Token op = u->op;

		if(op.type == TOK_MINUS)
			if(oprnd_type->type == TypeName::number){
				std::unique_ptr<NumberType> oprnd_number = downcast_unique_ptr<NumberType>(oprnd_type);
				return std::make_unique<NumberType>(-oprnd_number->value);
			}else{
				error(std::string("Unsupported operator ")+op.lexeme+std::string("in operand ")+get_typename_str(oprnd_type->type),op.line);
			}
		else if(op.type == TOK_PLUS)
			if(oprnd_type->type == TypeName::number){
				std::unique_ptr<NumberType> oprnd_number = downcast_unique_ptr<NumberType>(oprnd_type);
				return std::make_unique<NumberType>(oprnd_number->value);
			}else{
				error(std::string("Unsupported operator ")+op.lexeme+std::string("in operand ")+get_typename_str(oprnd_type->type),op.line);
			}
			
	}
}


void Interpretor::error(std::string msg, int line){
	std::cout << Colors::red;
	std::cout << "[Line "<<line<<"] Error: "<<msg<<std::endl;
	std::cout << Colors::white;
	exit(1);
}
