#include <iostream>
#include <vector>
#include <iomanip>

using mat = std::vector<std::vector<int>>;

bool isValidMove(int i, int j, std::vector<std::vector<int>>& board)
{
	return j >= 0 and i >= 0 and i < board.size() and j < board[0].size() and board[i][j] == -1;
}

void print(mat& board)
{
	int count = 0;
	for (auto& row : board)
		for (auto col : row)
		{
			std::cout << std::setw(2) << std::setfill('0') << col;
			if (count++ < 7 or count % 8 > 0)
				std::cout << ' ';
			else
				std::cout << '\n';
		}
}

bool tour(int i, int j, mat& board, std::vector<int>& arrI, std::vector<int>& arrJ, int step)
{

	if (step == board.size() * board.size() - 1)
	{
		print(board);
		return true;
	}

	int newI, newJ;
	for (int k = 0; k < 8; ++k) // number of possible knight moves?
	{
		newI = i + arrI[k];
		newJ = j + arrJ[k];
		if (isValidMove(newI, newJ, board))
		{
			board[newI][newJ] = step;
			if (tour(newI, newJ, board, arrI, arrJ, step + 1))
				return true;
			else
				board[newI][newJ] = -1;
		}
	}
	return false;
}

int main()
{
	std::vector<int> arrI = { -2, -2, -1, -1, 1, 1, 2, 2 };
	std::vector<int> arrJ = { -1, 1, -2, 2, -2, 2, -1, 1 };
	mat board(8, std::vector<int>(8, -1));
	tour(0, 0, board, arrI, arrJ, 0);	
}