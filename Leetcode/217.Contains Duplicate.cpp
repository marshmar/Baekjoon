#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numCheck;
        for (auto& num : nums)
        {
            if (numCheck.find(num) != numCheck.end())
            {
                return true;
            }
            else
            {
                numCheck.insert(num);
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> inputs{ 1, 2, 3, 1};
    cout << sol.containsDuplicate(inputs) << endl;
    return 0;
}