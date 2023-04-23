#include <iostream>
#include <vector>
#include <iomanip>

using matrix = std::vector<std::vector<int>>;

int digNum(int n)
{
	int res = 0;
	while (n)
	{
		n /= 10;
		++res;
	}
	return res;
}

int main()
{
	int size;
	std::cin >> size;
	int fillSize = digNum(size * size);
	matrix mat;
	int el = 1;

	for (int i = 0; i < size; ++i)
	{
		std::vector<int> v;
	
		for (int j = 0; j < size; ++j)
			v.push_back(el++);
		
		mat.push_back(v);
	}

	std::cout << '\n';
	for (auto& vec : mat)
	{
		for (auto el : vec)
			std::cout << std::setw(fillSize) << std::setfill('0') << el << ' ';
		std::cout << '\n';
	}	

	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			std::swap(mat[i][j], mat[j][i]);

	for (int i = 0; i < size; ++i) 
		std::reverse(mat[i].begin(), mat[i].end());

	std::cout << '\n';
	for (auto& vec : mat)
	{
		for (auto el : vec)
			std::cout << std::setw(fillSize) << el << ' ';
		std::cout << '\n';
	}
}