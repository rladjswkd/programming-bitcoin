#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#include "FieldElement.h"
#include "Point.h"

int main()
{
	Point<double> p1{2.0, 5.0, 5.0, 7.0};
	Point<double> p2{-1, -1, 5, 7};

	Point<double> p3 = p1 + p2;

	Point<double> p4{-1, -1, 5, 7};

	Point<double> p5 = p4 + p4;

	FieldElement x{192, 223};
	FieldElement y{105, 223};
	FieldElement a{0, 223};
	FieldElement b{7, 223};

	Point<FieldElement> p6{x, y, a, b};

	return 0;
}