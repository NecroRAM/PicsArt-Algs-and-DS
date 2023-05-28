class Solution {
public:
    auto maxSubArray(std::vector<int>& nums)
    {
        int sum = 0, maxSum = INT_MIN, i = 0;

        while (i < nums.size())
        {
            if (sum < 0)
                sum = 0;
            sum += nums[i++];
            maxSum = std::max(sum, maxSum);            
        }        

        return maxSum;
    }
};