#ifndef POINT_H
#define POINT_H

#include <stdlib.h>
#include <optional>

using Value = std::optional<double>;

class Point
{
public:
	Point(Value x, Value y, double a, double b);
	bool operator==(Point &other);
	bool operator!=(Point &other);
	Point operator+(Point &other); // Exercise 3, 5, 7

private:
	Value x, y;
	double a, b;
};

#endif