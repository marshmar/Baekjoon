#include<iostream>
//#include<algorithm>

using namespace std;

int N;

const int ms = 64;
int map[ms][ms];

const int dy[]{ -1, 0, 1, 0 };
const int dx[]{ 0, 1, 0, -1 };
bool visited[ms][ms];

int dfs(int y, int x, const int sy, const int sx, const int s, const int t)
{
	visited[y][x] = 1;

	int ret = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < sy || ny >= sy + s || nx < sx || nx >= sx+ s) continue;
		if (visited[ny][nx]) continue;
		if (map[ny][nx] != t) continue;

		ret += dfs(ny, nx, sy, sx, s, t);
	}

	
	return ret;
}

void solve(int sy, int sx, int s)
{
	if (s == 1)
	{
		printf("%d", map[sy][sx]);
		return;
	}

	fill(&visited[0][0], &visited[0][0] + ms * ms, 0);
	int ret = dfs(sy, sx, sy, sx, s, map[sy][sx]);
	if (ret == s * s)
	{
		printf("%d", map[sy][sx]);
		return;
	}
	else
	{
		s /= 2;
		printf("(");
		solve(sy, sx, s);
		solve(sy, sx + s, s);
		solve(sy + s, sx, s);
		solve(sy + s, sx + s, s);
		printf(")");
	}
}


int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	solve(0, 0, N);
	return 0;
}