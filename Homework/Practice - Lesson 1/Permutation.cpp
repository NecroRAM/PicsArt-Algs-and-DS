#include <iostream>
#include <vector>

int main()
{
	//std::vector<int> v{ 1, 5, 8, 4, 7, 6, 5, 3, 1 };
	std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 10, 9 };

	int indexLeft = -1;

	for (int i = 0; i < v.size() - 1; ++i)
		if (v[i] < v[i + 1])
			indexLeft = i;

	if (indexLeft == -1)
		std::reverse(v.begin(), v.end()); 
	else
	{
		int indexRight = indexLeft + 1;

		for (int i = indexRight; i < v.size(); ++i)
			if (v[i] > v[indexLeft])
				indexRight = i;

		std::swap(v[indexLeft], v[indexRight]);
		std::reverse(v.begin() + indexLeft + 1, v.end());
	}

	for (auto x : v)
		std::cout << x << ' ';
}