#include <iostream>
#include "FieldElement.h"

int main()
{
	FieldElement a = FieldElement(7, 13);
	FieldElement b = FieldElement(6, 13);

	std::cout << (a == b) << std::endl;
	std::cout << (a == a) << std::endl;
	std::cout << (-13 % 12) << std::endl;
	return 0;
}