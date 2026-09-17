/*
* Clauade 제공 솔루션
* 저점 -> 고점으로 가는 이익구간을 추적할 필요 없이
* 이익을 볼 때마다(전날대비 오른날마다) 다 더해주면 최대의 이익을 구할 수 있다.
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (size_t i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
                profit += prices[i] - prices[i - 1];
        }
        return profit;
    }
};

int main()
{
    Solution sol;
    vector<int> temp{ 7, 6, 4, 3, 1 };

    cout << sol.maxProfit(temp) << endl;
    return 0;
}