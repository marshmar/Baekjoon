#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size());
        int moveCnt = k % nums.size();

        for (size_t i = 0; i < nums.size(); i++)
        {
            size_t index = (i + moveCnt) % nums.size();
            temp[index] = nums[i];
        }

        nums = temp;
        for (auto& e : nums)
        {
            cout << e << " ";
        }
    }
};

int main()
{
    Solution sol;
    vector<int> temp{ -1, -100, 3, 99 };
    sol.rotate(temp, 6);
    return 0;
}