#include <iostream>
#include <vector>

int findMin(std::vector<int>& nums)
{
    int start = 0;
    int end = nums.size() - 1;
	if (nums[start] < nums[end])
		return nums[start];
    while (start < end)
        else
            start += (end + start) / 2;
    return nums[start];
	
	// if nums[mid] > nums[mid+1] return mid+1
	// if nums[mid-1] > nums[mid]
	// if nums[mid] > nums[0]
	// 
	
	
	
	//other
	// min = nums[0]
	// end = n - 1
	// start = 0
	// while end >= begin
		// if (nums[mid] > min) begin = mid + 1
		// else if (nums[mid]<mid) end = mid - 1, min = nums[mid[
		// else return mid
}

int main()
{
    std::vector<int> nums{ 2, 1 };
    std::cout << findMin(nums);
}