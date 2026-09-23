#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0;
        while (right < nums.size())
        {
            if (nums[right] != 0)
            {
                std::swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};

int main()
{
    Solution sol;
    vector<int> ret{1, 0, 1 };
    sol.moveZeroes(ret);
    for (auto& e : ret)
    {
        cout << e << " ";
    }
}