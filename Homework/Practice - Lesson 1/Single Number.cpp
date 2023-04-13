#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v{ 5, 2, 6, 7, 6, 5, 2 };

	int x = v[0];
	for (int i = 1; i < v.size(); ++i)
		x ^= v[i];

	std::cout << x;
}