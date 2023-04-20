#include <iostream>
#include <vector>

int maxProfit(std::vector<int>& prices)
{
	// try same way as max subarray sum
    int profit = 0, buy = 0, size = prices.size() - 1, sell = size;
    for (int i = 0; i <= size; ++i)
    {
        buy = i;
        while (++i < size && prices[i] > prices[buy]) {}
            
        if (buy != i)
        {
            sell = i;
            profit += prices[i] - prices[buy];
        }
    }
    return profit;
}
int main()
{                          //1 2 3 5 4
    std::vector<int> prices{ 1,2,3,4,5 };
    std::cout << maxProfit(prices);
}