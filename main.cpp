#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#include "FieldElement.h"

int main()
{
	{
		FieldElement a = FieldElement(7, 13);
		FieldElement b = FieldElement(6, 13);

		std::cout << (a == b) << std::endl;
		std::cout << (a == a) << std::endl;
		std::cout << (-13 % 12) << std::endl;
	}

	{
		std::cout << (95 * 45 * 31) % 97 << std::endl;
		std::cout << (17 * 13 * 19 * 44) % 97 << std::endl;
		std::cout << (static_cast<uint64_t>(std::pow(12, 7)) * static_cast<uint64_t>(77, 49)) % 97 << std::endl;
	}

	{
		std::vector<int> v{1, 3, 7, 13, 18};
		std::vector<std::vector<int>> results{5};
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = 0; j < 19; j++)
				results[i].push_back((v[i] * j) % 19);
			std::sort(results[i].begin(), results[i].end());
			for (int j = 0; j < 19; j++)
				std::cout << results[i][j] << " ";
			std::cout << std::endl;
		}
	}

	return 0;
}