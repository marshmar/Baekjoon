#include<iostream>
#include<vector>
//#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> RowTree, ColTree, nums;
int N, M;       // N: 표의 크기 M: 수행해야 하는 연산 수

void update(vector<int>& tree, int index, int value)
{
    while (index < tree.size())
    {
        tree[index] += value;
        index += (index & -index);
    }
}

int sum(vector<int>& tree, int index)
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
   
    RowTree.resize(N + 1);
    ColTree.resize(N + 1);
    nums.resize(N + 1);

    for (int i = 1; i <= N; i++)
    {
        RowTree[i].resize(N + 1);
        ColTree[i].resize(N + 1);
        nums[i].resize(N + 1);
        for (int j = 1; j <= N; j++)
        {
            cin >> nums[i][j];
        }
    }
    
    // 초기 펜윅트리 구하기
    for (int i = 1; i <= N; i++)
    {
            
    }

    int w, x, y, c, x1, y1, x2, y2;
    while (M--)
    {
        cin >> w;
        if (w == 0)
        {
            cin >> x >> y >> c;
            // 가로 업데이트
            update(RowTree[x], x, c - nums[x][y]);
            // 세로 업데이트
            update(ColTree[x], y, c - nums[x][y]);
            // 숫자 갱신
            nums[y][x] = c;
        }
        else
        {
            cin >> x1 >> y1 >> x2 >> y2;
            int RowSum = sum(RowTree[x2], x2) - sum(RowTree[x1 - 1], x1 - 1);
            int ColSum = sum(ColTree[y2], y2) - sum(ColTree[x2 - 1], x2 - 1);

            cout << RowSum + ColSum << endl;
        }
    }
    
    return 0;
}
