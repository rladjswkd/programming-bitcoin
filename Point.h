#include <stdlib.h>

class Point
{
public:
	Point(int64_t x, int64_t y, int64_t a, int64_t b);
	bool operator==(Point &other);
	bool operator!=(Point &other);

private:
	int64_t x, y, a, b;
};