#include<iostream>
#include<vector>

//#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> nums, RowTrees;

void Update(vector<int>& tree, int index, int value)
{
    while (index < tree.size())
    {
        tree[index] += value;
        index += (index & -index);
    }
}

int Sum(vector<int>& tree, int index)
{
    int ret = 0;
    while (index > 0)
    {
        ret += tree[index];
        index -= (index & -index);
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    // 초기화
    RowTrees.resize(N + 1);
    nums.resize(N + 1);

    for (int i = 1; i <= N; i++)
    {
        RowTrees[i].resize(N + 1, 0);
        nums[i].resize(N + 1, 0);

        for (int j = 1; j <= N; j++)
        {
            cin >> nums[i][j];
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            Update(RowTrees[i], j, nums[i][j]);
        }
    }

    
    int w = 0, x = 0, y = 0, c = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    while (M--)
    {
        cin >> w;

        if (w == 0)
        {
            cin >> x >> y >> c; //  x: 행, y: 열
            int diff = c - nums[x][y];

            nums[x][y] = c;

            // 가로 tree 업데이트
            Update(RowTrees[x], y, diff);
        }
        else
        {
            cin >> x1 >> y1 >> x2 >> y2;

            int ret = 0;
            for (int k = x1; k <= x2; k++)
            {
                ret += Sum(RowTrees[k], y2) - Sum(RowTrees[k], y1 - 1);
            }

            cout << ret << '\n';
        }
    }
    
    return 0;
}
