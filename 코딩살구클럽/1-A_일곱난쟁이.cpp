#include<iostream>
#include<vector>
#include<algorithm>
//#include <bits/stdc++.h>
using namespace std;

vector<int> Heights(9);
const int CombSize = 7;

bool Check(vector<int>& nums)
{
    int ret = 0;
    for (auto& e : nums)
    {
        ret += e;
    }

    return ret == 100;
}

void Combination(vector<int>& nums, int index)
{
    if (nums.size() == CombSize)
    {
        if (Check(nums))
        {
            for (auto& e : nums)
            {
                cout << e << endl;
            }
            exit(0);
        }
        else
        {
            return;
        }
    }

    for (int i = index + 1; i < 9; i++)
    {
        nums.push_back(Heights[i]);
        Combination(nums, i);
        nums.pop_back();
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 9; i++)
    {
        cin >> Heights[i];
    }

    sort(Heights.begin(), Heights.end());

    vector<int> temp;
    Combination(temp, -1);
    return 0;
}
