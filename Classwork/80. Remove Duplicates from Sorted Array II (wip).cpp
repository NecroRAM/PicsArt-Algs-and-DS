class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int count = 0;
        for (int i = 1; i < nums.size(); ++i)
            if (nums[i] > nums[i - 1])
                ++count;
            else 
				nums[i - count] = nums[i];
    }
};


// VS attempt

// #include <iostream>
// #include <vector>

// int removeDuplicates(std::vector<int>& nums)
// {
    // int count = 0;
    // if (nums.size() == 1)
        // return 1;
    // for (int i = 1; i < nums.size(); ++i)
    // {
        // while (i < nums.size() && nums[i] == nums[i - 1])
        // {
            // ++count;
            // ++i;
        // }
        // nums[i - count + 1] = nums[i];
        // i = i - count + 1;
        // count = 0;
    // }
    // return count;
// }

// int main()
 // {
    // std::vector<int> nums{ 1,1,1,2,2,3 };
    // std::cout << removeDuplicates(nums);
    // std::cout << '\n';

    // for (auto x : nums)
        // std::cout << x << ' ';
// }