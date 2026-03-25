#include <iostream>
#include "Serializer.hpp"

int main() {
	Data d;
	d.x = 42;
	d.c = 'z';

	uintptr_t raw = Serializer::serialize(&d);
	Data* d2 = Serializer::deserialize(raw);

	std::cout << "Original address: " << &d << "\n";
	std::cout << "Raw value: " << raw << "\n";
	std::cout << "Deserialized address: " << d2 << "\n";
	std::cout << "d2->x = " << d2->x << ", d2->c = " << d2->c << "\n";

	if (d2 == &d)
		std::cout << "Success: pointers match." << std::endl;
	else
		std::cout << "Error: pointers differ." << std::endl;

	return 0;
}
