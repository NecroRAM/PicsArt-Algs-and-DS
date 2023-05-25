#include <iostream>
#include <vector>

int findMin(std::vector<int>& nums)
    {
        int start = 0, end = nums.size()-1, mid = 0;
        
        while (start < end) 
        {
            mid = start + (end - start) / 2;
            if (nums[mid] < nums[end]) 
                end = mid;
            else
                start = mid + 1;
        }
        return nums[start];
    }

int main()
{
    std::vector<int> nums{ 2, 1 };
    std::cout << findMin(nums);
}