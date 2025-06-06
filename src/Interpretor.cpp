#include "Interpretor.h"

#include "utils.h"

void Interpretor::binop_unsupported_err(std::string lexeme,TypeName left_type, TypeName right_type,int line){
	error(std::string("Unsupported operator ")+lexeme+std::string(" between operands ")+get_typename_str(left_type)+std::string(" and ")+get_typename_str(right_type),line);
}
void Interpretor::unop_unsupported_err(std::string lexeme,TypeName oprnd_type,int line){
	error(std::string("Unsupported operator ")+lexeme+std::string(" in operand of type  ")+get_typename_str(oprnd_type),line);
}

Type* Interpretor::interpret(Node* node){
	if(Integer* i = dynamic_cast<Integer*>(node)){
		return new NumberType(i->value);
	}else if(Float* f = dynamic_cast<Float*>(node)){
		return new NumberType(f->value);
	}else if(String* s = dynamic_cast<String*>(node)){
		return new StringType(s->value);
	}else if(Bool* b = dynamic_cast<Bool*>(node)){
		return new BoolType(b->value);
	}else if(GroupExpr* g = dynamic_cast<GroupExpr*>(node)){
		return interpret(g->expr);
	}else if(BinOp* b = dynamic_cast<BinOp*>(node)){
		Type* left_type = interpret(b->left);
		Type* right_type = interpret(b->right);
		Token op = b->op;
//TODO: keep this repeated code in another function
		if(op.type == TOK_PLUS){
			if(left_type->type == TypeName::number && right_type->type == TypeName::number){
				NumberType* left_number = dynamic_cast<NumberType*>(left_type); 
				NumberType* right_number = dynamic_cast<NumberType*>(right_type);
			      	if(!left_number || !right_number) error("Downcast failed",op.line);	//shouldnt ever happen...kept for good practice	
				return new NumberType(left_number->value + right_number->value);
			}else if(left_type->type == TypeName::string && right_type->type == TypeName::string){
				StringType* left_string = dynamic_cast<StringType*>(left_type);
				StringType* right_string = dynamic_cast<StringType*>(right_type);
				if(!left_string || !right_string) error("Downcast failed",op.line);
				return new StringType(left_string->value + right_string->value);
			}else{
				binop_unsupported_err(op.lexeme,left_type->type,right_type->type,op.line);
				//TODO:node ma line no store gareko ta kam nai bhaena ta
			}
		}else if(op.type == TOK_MINUS){
			if(left_type->type == TypeName::number && right_type->type == TypeName::number){
				NumberType* left_number = dynamic_cast<NumberType*>(left_type); 
				NumberType* right_number = dynamic_cast<NumberType*>(right_type); 
			      	if(!left_number || !right_number) error("Downcast failed",op.line);	
				return new NumberType(left_number->value - right_number->value);
			}else{
				binop_unsupported_err(op.lexeme,left_type->type,right_type->type,op.line);
			}
		}else if(op.type == TOK_STAR){
			if(left_type->type == TypeName::number && right_type->type == TypeName::number){
				NumberType* left_number = dynamic_cast<NumberType*>(left_type); 
				NumberType* right_number = dynamic_cast<NumberType*>(right_type); 
			      	if(!left_number || !right_number) error("Downcast failed",op.line);	
				return new NumberType(left_number->value * right_number->value);
			}else{
				binop_unsupported_err(op.lexeme,left_type->type,right_type->type,op.line);
			}
		}else if(op.type == TOK_SLASH){
			if(left_type->type == TypeName::number && right_type->type == TypeName::number){
				NumberType* left_number = dynamic_cast<NumberType*>(left_type); 
				NumberType* right_number = dynamic_cast<NumberType*>(right_type); 
			      	if(!left_number || !right_number) error("Downcast failed",op.line);	
				return new NumberType(left_number->value / right_number->value);
			}else{
				binop_unsupported_err(op.lexeme,left_type->type,right_type->type,op.line);
			}
		}else if(op.type == TOK_GE){
			if(left_type->type == TypeName::number && right_type->type == TypeName::number){
				NumberType* left_value = dynamic_cast<NumberType*>(left_type);
				NumberType* right_value = dynamic_cast<NumberType*>(right_type);
				if(!left_type || !right_type) error("Downcast failed",op.line);
				return new BoolType(left_value->value >= right_value->value);
			}
		
		}else{
			error("Havent thought this through",op.line);
		}
	}else if(UnOp* u = dynamic_cast<UnOp*>(node)){
		Type* oprnd_type = interpret(u->oprnd);
		Token op = u->op;

		if(op.type == TOK_MINUS){
			if(oprnd_type->type == TypeName::number){
				NumberType* oprnd_number = dynamic_cast<NumberType*>(oprnd_type);
			      	if(!oprnd_number) error("Downcast failed",op.line);	
				return new NumberType(-oprnd_number->value);
			}else{
				unop_unsupported_err(op.lexeme,oprnd_type->type,op.line);
			}
		}else if(op.type == TOK_PLUS){
			if(oprnd_type->type == TypeName::number){
				NumberType* oprnd_number = dynamic_cast<NumberType*>(oprnd_type);
			      	if(!oprnd_number) error("Downcast failed",op.line);	
				return new NumberType(oprnd_number->value);
			}else{
				unop_unsupported_err(op.lexeme,oprnd_type->type,op.line);
			}
		}else{	
			error("Havent thought this through",op.line);
		}
			
	}
}


void Interpretor::error(std::string msg, int line){
	std::cout << Colors::red;
	std::cout << "[Line "<<line<<"] Error: "<<msg<<std::endl;
	std::cout << Colors::white;
	exit(1);
}
