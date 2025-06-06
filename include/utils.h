#ifndef UTILS_H
#define UTILS_H

#include <memory>

class Colors {
public:
	static constexpr const char* white  = "\033[0m";
	static constexpr const char* blue   = "\033[34m";
	static constexpr const char* cyan   = "\033[36m";
	static constexpr const char* green  = "\033[32m";
	static constexpr const char* yellow = "\033[33m";
	static constexpr const char* red    = "\033[31m";
};

template <typename Derived, typename Base>
Derived* downcast_ptr(Base* base){
	auto* raw_ptr = dynamic_cast<Derived*>(base);
	if(raw_ptr)	return raw_ptr;
	else return nullptr;
}



#endif
