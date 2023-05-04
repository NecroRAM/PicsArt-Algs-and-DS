 int maxProduct(vector<int>& nums) 
    {
        int max = 1, min = 1, res = nums[0];
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] < 0)
                std::swap(min, max);
                
            max = std::max(nums[i], nums[i] * max);
            min = std::min(nums[i], nums[i] *  min);

            res = std::max(res, max); 
        }
        return res;
    }