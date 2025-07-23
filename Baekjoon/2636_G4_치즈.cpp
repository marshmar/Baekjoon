#include<iostream>
using namespace std;

const int ms = 104;
int m[ms][ms];

bool visited[ms][ms];
bool air[ms][ms];

int H, W, ret;
const int dy[]{ -1, 0, 1, 0 };
const int dx[]{ 0, 1, 0, -1 };

void dfs(int y, int x, const int t)
{
	if (visited[y][x]) return;
	visited[y][x] = 1;
	if (t == 0)
		air[y][x] = 1;
	if (t == 1)
		ret++;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
		if (t == 1 && m[ny][nx] == 0 && air[ny][nx]) m[y][x] = 0;
		if (m[ny][nx] != t) continue;

		dfs(ny, nx, t);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> H >> W;

	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			cin >> m[i][j];
	
	int befRet = 0, cnt = 0;
	while (true)
	{
		fill(&air[0][0], &air[0][0] + ms * ms, 0);
		fill(&visited[0][0], &visited[0][0] + ms * ms, 0);

		dfs(0, 0, 0);
		befRet = ret;
		ret = 0;

		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (m[i][j] == 1 && !visited[i][j]) dfs(i, j, 1);
			}
		}

		if (ret == 0) break;
		cnt++;
	}

	cout << cnt << "\n";
	cout << befRet << "\n";
	return 0;
}