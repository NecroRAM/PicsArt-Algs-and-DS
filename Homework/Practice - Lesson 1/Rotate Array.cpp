#include <iostream>
#include <vector>

// 1,2,3,4,5,6,7
void rotate(std::vector<int>& nums, const int k)
{
	int steps = k % nums.size();
	int stored = 0;
	while (steps--)
	{
		stored = nums[nums.size() - 1];
		std::copy(nums.begin(), nums.end() - 1, nums.begin() + 1);
		nums[0] = stored;
	}
}

int main()
{
	std::vector<int> nums{ 1,2,3,4,5,6,7 };
	int k;
	std::cin >> k;
	for (auto x : nums)
		std::cout << x << ' ';
	std::cout << '\n';

	rotate(nums, k);
	for (auto x : nums)
		std::cout << x << ' ';
}