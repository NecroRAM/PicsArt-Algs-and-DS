#include <iostream>
#include <vector>

int maxProfit(std::vector<int>& prices) 
{
    int index = 0;
    int curMax = 0;
    for (int i = 0; i < prices.size(); ++i)
    {
        if (prices[index] > prices[i])
            index = i;
        curMax = std::max(curMax, prices[i] - prices[index]);
    }
    return curMax;
}

int main()
{
    std::vector<int> prices{ 20, 2, 6, 8, 14, 32, 8, 43, 2 };
    std::cout << maxProfit(prices);
}