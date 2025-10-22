#include "Point.h"

#include <cmath>
#include <stdexcept>

Point::Point(int64_t x, int64_t y, int64_t a, int64_t b)
{
	if (y * y != x * x * x + a * x + b)
		throw std::invalid_argument("wrong arguments");
	this->x = x;
	this->y = y;
	this->a = a;
	this->b = b;
}

bool Point::operator==(Point &other)
{
	return x == other.x && y == other.y && a == other.a && b == other.b;
}

bool Point::operator!=(Point &other)
{
	return !(*this == other);
}
