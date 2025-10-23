#ifndef POINT_H
#define POINT_H

#include <stdlib.h>
#include <optional>

using Value = std::optional<int64_t>;

class Point
{
public:
	Point(Value x, Value y, int64_t a, int64_t b);
	bool operator==(Point &other);
	bool operator!=(Point &other);
	Point operator+(Point &other); // Exercise 3

private:
	Value x, y;
	int64_t a, b;
};

#endif