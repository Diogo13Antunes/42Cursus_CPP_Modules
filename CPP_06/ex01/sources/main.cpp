#include <Data.hpp>
#include <iostream>

uintptr_t	serialize(Data *ptr);
Data 		*deserialize(uintptr_t raw);

int main()
{
	uintptr_t	intptr;
	Data		*dataPointer = new Data();

	std::cout << "-----------------------------" << std::endl;
	dataPointer->setNbr(13);
	std::cout << "Data Pointer before Deserialize \nValue = " << dataPointer->getNbr() << "\nAddress = " << &dataPointer << std::endl;
	std::cout << "-----------------------------\n" << std::endl;

	std::cout << "-----------------------------" << std::endl;
	intptr = serialize(dataPointer);
	std::cout << "Int Pointer after Serialize \nValue = " << intptr << std::endl;
	std::cout << "-----------------------------\n" << std::endl;
	
	std::cout << "-----------------------------" << std::endl;
	dataPointer = deserialize(intptr);
	std::cout << "Data Pointer after Deserialize \nValue = " << dataPointer->getNbr() << "\nAddress = " << &dataPointer << std::endl;
	std::cout << "-----------------------------" << std::endl;

	delete dataPointer;
	std::getwchar();
	return (0);
}
