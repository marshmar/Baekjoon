#include <iostream>
#include <vector>

using namespace std;

const int ms = 54;
int m[54][54], n, l, r, sum, ret;
bool visited[ms][ms];

const int dy[] = { -1,0,1,0 };
const int dx[] = { 0,1,0,-1 };
vector<pair<int, int>>v;


void dfs(int y, int x)
{
    for (int i = 0; i < 4; i++) 
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[ny][nx])continue;
        if (abs(m[ny][nx] - m[y][x]) >= l && abs(m[ny][nx] - m[y][x]) <= r) 
        {
            visited[ny][nx] = 1;
            v.push_back({ ny,nx });
            sum += m[ny][nx];
            dfs(ny, nx);
        }
    }
}

int main() 
{
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> m[i][j];
        }
    }

    while (true) 
    {
        bool flag = 0;
        fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (!visited[i][j]) 
                {
                    v.clear();
                    visited[i][j] = 1;
                    v.push_back({ i,j });
                    sum = m[i][j];
                    dfs(i, j);
                    if (v.size() == 1) continue;
                    for (pair<int, int> b : v) 
                    {
                        m[b.first][b.second] = sum / v.size();
                        flag = 1;
                    }
                }
            }
        }
        if (!flag) break;
        ret++;
    }
    cout << ret << "\n";
    return 0;
}