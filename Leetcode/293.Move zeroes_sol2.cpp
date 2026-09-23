#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        stable_partition(nums.begin(), nums.end(), [](int x) { return x != 0; });
    }
};

int main()
{
    Solution sol;
    vector<int> ret{ 0,1,0,3,12 };
    sol.moveZeroes(ret);
    for (auto& e : ret)
    {
        cout << e << " ";
    }
}