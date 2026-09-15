#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		auto NonDupIndex = unique(nums.begin(), nums.end());
		nums.erase(NonDupIndex, nums.end());

		return nums.size();
	}
};

int main()
{
	Solution sol;
	vector<int> temp{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
	sol.removeDuplicates(temp);
}