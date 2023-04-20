// use 2 pointers

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right)
        {
            if (numbers[left] + numbers[right] == target)
                return vector<int>{ left + 1, right + 1 };
            else if (numbers[left] + numbers[right] < target)
                ++left;
            else if (numbers[left] + numbers[right] > target)
                --right;            
        }
        return {left, right};
    }
};