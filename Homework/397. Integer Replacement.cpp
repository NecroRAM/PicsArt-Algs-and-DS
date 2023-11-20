#include <iostream>
#include <unordered_map>

int minOp(int count, int n, std::unordered_map<int, int>& memo)
{
	if (n % 2 == 0)
	{
		++memo[n];
		n /= 2;
	}
	else if ((n + 1) % 2
}

int main()
{
	int n;
	std::cin >> n;
	std::cout << minOp(n);
}