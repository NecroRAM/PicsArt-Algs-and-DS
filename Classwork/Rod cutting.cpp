#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int backtrack(int price, std::vector<int>& prices, std::vector<int>& memo, int n)
{
	if (n == 0)
		return 0;
	if (memo[n] != -1)
		return memo[n];
	for (int i = 1; i < n; ++i)
		price = std::max(price, prices[i] + backtrack(price, prices, memo, n - 1));
	return memo[n] = price;
}

int main()
{
	std::vector<int> prices {0, 1, 5, 8, 4, 9, 10 }
	int price = INT_MIN;
	


	// tabulation
	int n;
	std::vector<int> dp(n + 1, 0)
	for (i = 1 -> n)


	// also reconstruct the path from result
}