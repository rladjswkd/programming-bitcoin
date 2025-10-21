#ifndef FIELD_ELEMENT_H
#define FIELD_ELEMENT_H

#include <string>

class FieldElement
{
public:
	FieldElement(int64_t num, int64_t prime);
	std::string represent();
	bool operator==(FieldElement &other);
	bool operator!=(FieldElement &other); // Exercise 1
	FieldElement operator+(FieldElement &other);
	FieldElement operator-(FieldElement &other); // Exercise 2
	FieldElement operator*(FieldElement &other); // Exercise 6
	FieldElement pow(int64_t exp);							 // big integer로 대체 필요
	FieldElement operator/(FieldElement &other); // Exercise 9

private:
	int64_t num;
	int64_t prime;

	FieldElement();
};
#endif