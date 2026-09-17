#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maximumProfit = 0;
        int curDay = 1, holdingStockPrice = prices[0], profit = 0;

        while (curDay < prices.size())
        {
            // 오늘 가격이 떨어졌다면, 주식을 가지고 있으면 손해니 상한가로 팔고, 
            // 주식 보유 여부에 상관없이 산다고 가정
            if (prices[curDay] - prices[curDay-1] < 0)
            {
                if (profit > 0)
                {
                    maximumProfit += profit;
                    profit = 0;
                }
                holdingStockPrice = prices[curDay];
            }
            // 오늘 가격이 올랐을 때 이전 최대 이익보다 이익이 더 세다면 이익을 갱신
            // 가격이 올랐다면 팔지 않아도 됨
            else if (prices[curDay] - prices[curDay - 1] > 0)
            {
                if (profit < prices[curDay] - holdingStockPrice)
                {
                    profit = prices[curDay] - holdingStockPrice;
                }
            }
            curDay++;
        }

        if (profit > 0)
        {
            maximumProfit += profit;
        }
        return maximumProfit;
    }
};

int main()
{
    Solution sol;
    vector<int> temp{ 7, 6, 4, 3, 1 };

    cout << sol.maxProfit(temp) << endl;
    return 0;
}