#include <iostream>
#include <vector>


int main()
{
	std::vector<int> v{ 1, 5, 8, 4, 7, 6, 5, 3, 1 };
	int size = v.size();
	for (int i = size - 1; i < 0; --i)
	{
		if (v[i] >= v[i - 1])
		{

		}
			std::swap(v[i - 1], *std::min_element(v.begin() + i, v.end()));
		
		std::reverse(v.begin() + i, v.end());
	}
}