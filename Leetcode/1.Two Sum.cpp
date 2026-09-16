/*
* 내 풀이: 정렬 후 투포인터 사용(Onlogn)
* 다른 풀이: map 또는 unorderedmap 사용. map 사용시 동일하게 O(nlogn), unordered_map 사용시 평균 O(n), 최악(ON^2)
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    // 시간복잡도: O(nlogn) - sort
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        vector<pair<int, int>> orderedNums; 
        
        // 배열을 오름차순으로 정렬하고, 원래 인덱스를 저장
        for (int i = 0; i < (int)nums.size(); i++)
        {
            orderedNums.push_back({ nums[i], i });
        }
        sort(orderedNums.begin(), orderedNums.end());

        // 투 포인터를 사용해서 합이 target이 되는 값을 O(N)으로 검색
        int start = 0, end = nums.size() -1;
        while (start < end)
        {
            if (orderedNums[start].first + orderedNums[end].first > target)
            {
                end--;
            }
            else if(orderedNums[start].first + orderedNums[end].first < target)
            {
                start++;
            }
            else
            {
                // 결과 vector에 값이 아닌 인덱스 정보를 저장
                ret.push_back(orderedNums[start].second);
                ret.push_back(orderedNums[end].second);
                break;
            }
        }

        return ret;
    }
};

int main()
{
    Solution sol;
    vector<int> temp{ 3, 3 };
    vector<int> ret = sol.twoSum(temp, 6);
    for (auto& e : ret)
    {
        cout << e << " ";
    }
    return 0;
}