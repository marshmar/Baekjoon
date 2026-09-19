#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (auto& num : nums)
        {
            ret ^= num;
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    vector<int> inputs{ 1, 4, 4 };
    cout << sol.singleNumber(inputs) << endl;
    return 0;
}