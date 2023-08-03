#include <iostream>
#include <vector>

using mat = std::vector<std::vector<int>>;

bool solveMaze(mat& maze, int i, int j, int n, int m, mat& sol)
{
	if (i == 0 and j == m - 1 and maze[i][j] == 1)
	{
		sol[i][j] = 1;
		return true;
	}
	if (isValid(maze, i, j, n, m))
	{
		if (sol[i][j] == 1) return false;

		sol[i][j] = 1;
		if (solveMaze(... i + 1, j ...) or
			solveMaze(... i, j + 1 ...) or
			solveMaze(... i - 1, j ...) or 
			solveMaze(... i, j - 1...))
			return true
		sol[i][j] = 0;
		return false;
	}
	return false;
}
int main()
{

}