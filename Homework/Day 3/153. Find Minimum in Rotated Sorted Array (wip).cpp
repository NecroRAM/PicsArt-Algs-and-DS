#include <iostream>
#include <vector>

int findMin(std::vector<int>& nums)
{
    int start = 0;
    int end = nums.size() - 1;
    while (start < end)
        if (nums[start] < nums[end])
            return nums[start];
        else
            start += (end + start) / 2;
    return nums[start];
}

int main()
{
    std::vector<int> nums{ 2, 1 };
    std::cout << findMin(nums);
}