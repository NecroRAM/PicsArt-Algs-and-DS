#include <iostream>
#include <vector>

//void rotate(std::vector<int>& nums, const int k)
//{
//	int steps = k % nums.size();
//	int stored = 0;
//	while (steps--)
//	{
//		stored = nums[nums.size() - 1];
//		std::copy(nums.begin(), nums.end() - 1, nums.begin() + 1);
//		nums[0] = stored;
//	}
//}

void rotate(std::vector<int>& nums, const int k)
{
	int steps = k % nums.size();

	if (steps)
	{
		// right slice rotation
		int left = nums.size() - steps;
		int right = nums.size() - 1;

		while (left < right)
		{
			std::swap(nums[left], nums[right]);
			++left, --right;
		}

		// left slice rotation
		left = 0;
		right = nums.size() - steps - 1;
		while (left < right)
		{
			std::swap(nums[left], nums[right]);
			++left, --right;
		}

		// whole range rotation
		left = 0;
		right = nums.size() - 1;
		while (left < right)
		{
			std::swap(nums[left], nums[right]);
			++left, --right;
		}
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