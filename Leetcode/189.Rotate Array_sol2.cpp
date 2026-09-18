#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size());
        k = k % nums.size();
        
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());
    }
};

int main()
{
    Solution sol;
    vector<int> temp{ -1, -100, 3, 99 };
    sol.rotate(temp, 2);
    return 0;
}