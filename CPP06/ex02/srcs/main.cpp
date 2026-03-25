#include <iostream>
#include "../include/Base.hpp"

// Prototypes for the functions implemented in identify.cpp
Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main() {
	for (int i = 0; i < 5; ++i) {
		Base* obj = generate();
		std::cout << "identify(Base*): "; identify(obj);
		std::cout << "identify(Base&): "; identify(*obj);
		delete obj;
		std::cout << "---\n";
	}
	return 0;
}
