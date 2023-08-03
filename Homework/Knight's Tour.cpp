#include <iostream>
#include <vector>

using mat = std::vector<std::vector<int>>;
bool isValidMove(int i, int j, std::vector<std::vector<int>>& board)
{
	return j >= 0 and i >= 0 and i < board.size() and j < board[0].size() and board[i][j] == -1;
}

bool backtrack(int i, int j, mat& board, std::vector<int>& arrI, std::vector<int>& arrJ, int step)
{
	if (step % board.size() <= 0)
		std::cout << step << ' ';
	else
		std::cout << step << '\n';

	if (step == board.size() * board.size() - 1)
		return true;
	int newI, newJ;
	for (int k = 0; k < 8; ++k)
	{
		newI = i + arrI[k];
		newJ = j + arrJ[k];
		if (isValidMove(newI, newJ, board))
		{
			board[newI][newJ] = step;
			if (backtrack(newI, newJ, board, arrI, arrJ, step + 1))
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
	mat board;
	for (int i = 0; i < 8; ++i)
	{
		std::vector<int> v(8, -1);
		board.push_back(v);
	}
	backtrack(0, 0, board, arrI, arrJ, 0);	
}