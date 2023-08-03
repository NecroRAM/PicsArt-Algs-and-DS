#include <iostream>
#include <vector>

using mat = std::vector<std::vector<int>>;
const int n = 9;
bool isSafe(mat& grid, int row, int col, int n)
{
	int r = row - row % 3;
	int c = col - col % 3;
	for (int i = 0; i < n; ++i)
	{
		if (grid[row][i] == n or grid[i][col] == n) 
			return false;
	}
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (grid[r + i][c + j] == n)
				return false;
}
bool solve(mat& grid, int row, int col)
{
	if (row == n - 1 and col == n) return true;
	if (col == n) ++row; col = 0;
	if (grid[row][col])
		return solve(grid, row, col + 1); // if current cell is set
	for (int n = 1; n <= n; ++n)
	{
		if (isSafe(grid, row, col, n))
		{
			grid[row][col] = n;
			if (solve(grid, row, col + 1))
				return true;
		}
		grid[row][col] = 0;
	}
	return false;
}