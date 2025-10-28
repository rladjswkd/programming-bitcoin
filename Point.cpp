#include "Point.h"

#include <cmath>
#include <stdexcept>

Point::Point(Value x, Value y, double a, double b)
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
	return x.has_value() && y.has_value() && other.x.has_value() && other.y.has_value() && x == other.x && y == other.y && a == other.a && b == other.b;
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
	if (*this == other)
	{
		if (this->y.value() == 0 * this->x.value())
		{
			// page 39 - vertial and tangent to the curve
			return Point(std::nullopt, std::nullopt, this->a, this->b);
		}
		double x1 = this->x.value();
		double y1 = this->y.value();
		double x2 = other.x.value();
		double y2 = other.y.value();
		double s = (3 * x1 * x1 + a) / (2 * y1);
		double x3 = s * s - x1 - x2;
		double y3 = -(s * (x3 - x1) + y1);
		return Point(x3, y3, this->a, this->b);
	}
	if (this->x.has_value() && other.x.has_value() && this->y.has_value() && other.y.has_value() && this->x.value() != other.x.value())
	{
		double x1 = this->x.value();
		double y1 = this->y.value();
		double x2 = other.x.value();
		double y2 = other.y.value();
		double s = (y2 - y1) / (x2 - x1);
		double x3 = s * s - x1 - x2;
		double y3 = -(s * (x3 - x1) + y1);
		return Point(x3, y3, this->a, this->b);
	}
	if (this->x.has_value() && other.x.has_value() && this->y.has_value() && other.y.has_value() && this->y.value() != other.y.value())
		return Point(std::nullopt, std::nullopt, this->a, this->b);
	return Point(std::nullopt, std::nullopt, 0, 0);
}
