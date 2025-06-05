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
std::unique_ptr<Derived> downcast_unique_ptr(std::unique_ptr<Base>& base){
	auto* raw_ptr = dynamic_cast<Derived*>(base.get());
	if(raw_ptr){
		base.release();					//give up ownnership by base to prevent two unique_ptr owning same object....i dont think this shit will work
		return std::unique_ptr<Derived>(raw_ptr);
	}else
		return nullptr;
}

#endif
