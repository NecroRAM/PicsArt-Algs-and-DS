class Solution {
private:
    std::unordered_map<int, std::vector<int>> map;

public:

    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i)
            map[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        return map[target][rand() % map[target].size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */