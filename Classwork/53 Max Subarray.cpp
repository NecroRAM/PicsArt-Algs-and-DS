#include <iostream>
#include <vector>

auto findMaxCrossingSubaray(std::vector<int>& nums, int low, int mid, int high)
{
	int leftSum = INT_MIN;
	int maxLeft = 0;
	int sum = 0;
	for (int i = mid; i >= low; --i)
	{
		sum = sum + nums[i];
		if (sum > leftSum)
		{
			leftSum = sum;
			maxLeft = i;
		}
	}

	int rightSum = INT_MIN;
	sum = 0;
	int maxRight = 0;
	for (int i = mid + 1; i <= high; ++i)
	{
		sum = sum + nums[i];
		if (sum > rightSum)
		{
			rightSum = sum;
			maxRight = i;
		}
	}

	return std::make_tuple(maxLeft, maxRight, leftSum + rightSum);
}

auto maxSubArray(std::vector<int>& nums, int low, int high)
{
	if (low == high)
		return std::make_tuple(low, high, nums[low]);

	int mid = low + (high - low) / 2;

	auto left = maxSubArray(nums, low, mid);
	auto right = maxSubArray(nums, mid + 1, high);
	auto cross = findMaxCrossingSubaray(nums, low, mid, high);

	if (std::get<2>(left) >= std::get<2>(right) && std::get<2>(left) >= std::get<2>(cross))
		return left;
	else if (std::get<2>(right) >= std::get<2>(left) && std::get<2>(right) >= std::get<2>(cross))
		return right;
	else
		return cross;
}

auto maxSubArrayWrapper(std::vector<int>& nums)
{
	return maxSubArray(nums, 0, nums.size() - 1);
}

// O(n) alg
//int maxSubArray(std::vector<int>& nums)
//{
//	int sum = 0, maxSum = INT_MIN, i = 0;
//	while (i < nums.size())
//	{
//		if (sum < 0)
//			sum = 0;
//		sum += nums[i++];
//		maxSum = std::max(sum, maxSum);
//	}
//	return maxSum;
//}

int main()
{
	//std::vector<int> nums{ -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	//std::vector<int> nums{ 1 };
	std::vector<int> nums{ 5, 4, -1, 7, 8 };

	auto [low, high, sum] = maxSubArrayWrapper(nums);

	std::cout << low << ' ' << high << ' ' << sum << '\n';
}