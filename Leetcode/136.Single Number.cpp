#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> numsToCheck;   
        int ret = 0;
        for (auto& e : nums)
        {
            numsToCheck[e]++;
        }

        for (auto& num : numsToCheck)
        {
            if (num.second == 1)
            {
                ret = num.first;
            }
        }

        return ret;
    }
};

int main()
{
    Solution sol;
    vector<int> inputs{4,1,2,1,2};
    cout << sol.singleNumber(inputs) << endl;
	return 0;
}