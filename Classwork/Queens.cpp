#include <iostream>
#include <vector>

using mat = std::vector<std::vector<int>>;
bool isValid(mat& board, int row, int col)
{
	for (int r = 0; r < row; ++r) // col check
	{
		if (board[row][col] == 1) return false;

	}
	int i = row - 1, j = col - 1;

	while (i >= 0 and j >= 0) // left top
		if (board[i][j] == 1) return false;
	i = row - 1; j = col + 1;
	while (i >= 0 and j < board.size()) // right top
		if (board[i--][j++] == 1) return false;
	return true;
}
void backtrack(mat& board, int row, int& count)
{
	if (row == n)
	{
		++count;
		print(board);
		return;
	}
	for (int col = 0; col < n; ++col)
	{
		if (isValid(board, row, col))
		{
			board[row][col] = 1;
			backtrack(board, row + 1, col);
			board[row][col] = 0;
		}
	}

}
int main()
{

}