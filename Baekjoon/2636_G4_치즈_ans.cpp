#include<iostream>
#include<vector>

using namespace std;

const int ms = 104;
int m[ms][ms], visited[ms][ms];

const int dy[]{ -1, 0, 1, 0 };
const int dx[]{ 0, 1,0,-1 };

int h, w, cnt, cnt2;
vector<pair<int, int>>v;

void dfs(int y, int x)
{
	visited[y][x] = 1;
	if (m[y][x] == 1)
	{
		v.push_back({ y, x });
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= h || nx < 0 || nx >= w || visited[ny][nx]) continue;
		dfs(ny, nx);
	}
	return;
}

int main()
{
	cin >> h >> w;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> m[i][j];

	while (true)
	{
		fill(&visited[0][0], &visited[0][0] + ms * ms, 0);
		v.clear();
		dfs(0, 0);
		cnt2 = v.size();
		for (pair<int, int> b : v)
		{
			m[b.first][b.second] = 0;
		}
		bool flag = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (m[i][j] != 0) flag = 1;
			}
		}
		cnt++;
		if (!flag) break;
	}

	cout << cnt << "\n" << cnt2 << "\n";
}