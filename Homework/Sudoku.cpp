#include <iostream>
#include <vector>

const int n = 9;
using mat = std::vector<std::vector<int>>;

bool isValid(mat& grid, int row, int col, int num)
{
	for (int i = 0; i < n; ++i)
		if (grid[row][i] == num or grid[i][col] == num)
			return false;
	int subRow = row - row % 3;
	int subCol = col - col % 3;

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (grid[subRow + i][subCol + j] == num)
				return false;
	return true;
}

bool backtrack(mat& grid, int row, int col)
{
	if (row == n - 1 and col == n)
		return true;
	if (col == n)
	{
		++row;
		col = 0;
	}
	if (grid[row][col]) // if the current cell is set
		return backtrack(grid, row, col + 1);

	for (int num = 1; num <= n; ++num)
	{
		if (isValid(grid, row, col, num))
		{
			grid[row][col] = num;
			if (backtrack(grid, row, col + 1))
				return true;
			grid[row][col] = 0;
		}
	}
	return false;
}

int main()
{
	mat grid(9, std::vector<int>(9, 0));
	grid[2][7] = 2;
	std::cout << backtrack(grid, 0, 0) << '\n';

	for (auto& row : grid)
	{
		std::cout << '\n';
		for (auto col : row)
			std::cout << col << ' ';
	}
	std::cout << '\n';
}