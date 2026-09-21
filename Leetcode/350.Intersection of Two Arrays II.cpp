#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) { 
        vector<int> ret;
        map<int, int> m;

        for (auto& e : nums1)
        {
            m[e]++;
        }

        for(auto& e : nums2)
        {
            if (m[e])
            {
                ret.push_back(e);
                m[e]--;
            }
		}
        return ret;
    }

};



int main()
{
    Solution sol;
	vector<int> temp1{ 4, 9, 5 };
    vector<int> temp2{ 9, 4, 9, 8, 4 };
    vector<int> ret = sol.intersect(temp1, temp2);

    for(auto& e : ret)
    {
        cout << e << " ";
	}
    return 0;
}