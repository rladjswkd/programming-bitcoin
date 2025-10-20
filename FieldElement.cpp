#include <stdexcept>
#include "FieldElement.h"

FieldElement::FieldElement(int64_t num, int64_t prime)
{
	if (num >= prime || num < 0)
		throw std::invalid_argument("Num must be in range 0 to prime - 1");
	this->num = num;
	this->prime = prime;
}

std::string FieldElement::represent()
{
	return "FieldElement_" + std::to_string(prime) + "(" + std::to_string(num) + ")";
}

bool FieldElement::operator==(FieldElement &other)
{
	return (this->num == other.num) && (this->prime == other.prime);
}

bool FieldElement::operator!=(FieldElement &other)
{
	return !(*this == other);
}

FieldElement FieldElement::operator+(FieldElement &other)
{
	if (this->prime != other.prime)
		throw std::invalid_argument("Cannot add two numbers in different Fields");

	int64_t res = (this->num + other.num) % this->prime;
	if (res < 0) // python과 c++의 음수 나머지 처리 차이
		res += this->prime;
	return FieldElement(res, this->prime);
}

FieldElement FieldElement::operator-(FieldElement &other)
{
	if (this->prime != other.prime)
		throw std::invalid_argument("Cannot subtract two numbers in different Fields");

	int64_t res = (this->num - other.num) % this->prime;
	if (res < 0) // python과 c++의 음수 나머지 처리
		res += this->prime;
	return FieldElement(res, this->prime);
}
