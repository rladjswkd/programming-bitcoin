#ifndef POINT_H
#define POINT_H

#include <stdlib.h>
#include <optional>
#include <cmath>
#include <stdexcept>

template <typename T>
class Point
{
public:
	Point(std::optional<T> x, std::optional<T> y, T a, T b);
	bool operator==(Point &other);
	bool operator!=(Point &other);
	Point operator+(Point &other);

private:
	std::optional<T> x, y;
	T a, b;
};

template <typename T>
Point<T>::Point(std::optional<T> x, std::optional<T> y, T a, T b)
		: x(x), y(y), a(a), b(b)
{
	if (x.has_value() && y.has_value() && y.value() * y.value() != x.value() * x.value() * x.value() + a * x.value() + b)
		throw std::invalid_argument("wrong arguments");
}

template <typename T>
bool Point<T>::operator==(Point<T> &other)
{
	return x.has_value() && y.has_value() && other.x.has_value() && other.y.has_value() && x == other.x && y == other.y && a == other.a && b == other.b;
}

template <typename T>
bool Point<T>::operator!=(Point<T> &other)
{
	return !(*this == other);
}

template <typename T>
Point<T> Point<T>::operator+(Point<T> &other)
{
	if (this->a != other.a || this->b != other.b)
		throw std::invalid_argument("wrong arguments");
	if (!this->x.has_value())
		return other;
	if (!other.x.has_value())
		return *this;
	if (*this == other)
	{
		if (this->y.value() == 0 * this->x.value())
		{
			return Point<T>(std::nullopt, std::nullopt, this->a, this->b);
		}
		T x1 = this->x.value();
		T y1 = this->y.value();
		T x2 = other.x.value();
		T y2 = other.y.value();
		T s = (T(3) * x1 * x1 + a) / (T(2) * y1);
		T x3 = s * s - x1 - x2;
		T y3 = -(s * (x3 - x1) + y1);
		return Point<T>(x3, y3, this->a, this->b);
	}
	if (this->x.has_value() && other.x.has_value() && this->y.has_value() && other.y.has_value() && this->x.value() != other.x.value())
	{
		T x1 = this->x.value();
		T y1 = this->y.value();
		T x2 = other.x.value();
		T y2 = other.y.value();
		T s = (y2 - y1) / (x2 - x1);
		T x3 = s * s - x1 - x2;
		T y3 = -(s * (x3 - x1) + y1);
		return Point<T>(x3, y3, this->a, this->b);
	}
	if (this->x.has_value() && other.x.has_value() && this->y.has_value() && other.y.has_value() && this->y.value() != other.y.value())
		return Point<T>(std::nullopt, std::nullopt, this->a, this->b);
	return Point<T>(std::nullopt, std::nullopt, 0, 0);
}

#endif
