#include<iostream>
using namespace std;

int M, N, K, T;
const int mSize = 50;

int map[mSize][mSize];
bool visited[mSize][mSize];

const int dy[]{ -1, 0, 1, 0 };
const int dx[]{ 0, 1, 0, -1 };

void dfs(int y, int x)
{
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx]) continue;
		if (map[ny][nx] == 0) continue;

		dfs(ny, nx);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> M >> N >> K;
		int y, x, ret = 0;

		fill(&map[0][0], &map[mSize - 1][mSize], 0);
		fill(&visited[0][0], &visited[mSize - 1][mSize], 0);

		for (int j = 0; j < K; j++)
		{
			cin >> x >> y;
			map[y][x] = 1;
		}

		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (!visited[j][k] && map[j][k] == 1)
				{
					dfs(j, k);
					ret++;
				}
			}
		}

		cout << ret << "\n";
	}
	return 0;
}