#include "Point.h"

#include <cmath>
#include <stdexcept>

Point::Point(Value x, Value y, int64_t a, int64_t b)
{

	if (x.has_value() && y.has_value() && y.value() * y.value() != x.value() * x.value() * x.value() + a * x.value() + b)
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

Point Point::operator+(Point &other)
{
	if (this->a != other.a || this->b != other.b)
		throw std::invalid_argument("wrong arguments");
	// this가 point of infinity
	if (!this->x.has_value())
		return other;
	// other가 point of infinity
	if (!other.x.has_value())
		return *this;
	if (this->x.has_value() && other.x.has_value() && this->y.has_value() && other.y.has_value() && this->x.value() == other.x.value() && this->y.value() != other.y.value())
		return Point(std::nullopt, std::nullopt, this->a, this->b);
	return Point(std::nullopt, std::nullopt, 0, 0);
}
