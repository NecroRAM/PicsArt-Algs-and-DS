class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto index = 0;
       // auto maxEl = 0;
        int curMax = 0;
        for (int i = 0; i < prices.size(); ++i)
        {
            if (prices[index] > prices[i])
                index = i;            
            curMax = max(curMax, prices[i] - prices[index]);
        }
        return curMax;
    }
};