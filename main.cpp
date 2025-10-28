#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#include "FieldElement.h"
#include "Point.h"
int main()
{
	Point p1{2, 5, 5, 7};
	Point p2{-1, -1, 5, 7};

	Point p3 = p1 + p2;

	Point p4{-1, -1, 5, 7};

	Point p5 = p4 + p4;
	return 0;
}