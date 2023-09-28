#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
	Data	*stuff;

	stuff = new Data;
	stuff->data = "Hello, world!";
	std::cout << "stuff->data: " << stuff->data << std::endl;

	uintptr_t	*serialized = Serializer::serialize(stuff);
	std::cout << "serialized: " << serialized << std::endl;

	stuff = Serializer::deserialize(serialized);
	std::cout << "deserialized: " << stuff->data << std::endl;

	delete stuff;
	return (0);
}
