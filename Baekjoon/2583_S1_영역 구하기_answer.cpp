#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int M, N, K;
const int ms = 101;
int map[ms][ms];
bool visited[ms][ms];

const int dy[]{ -1, 0, 1, 0 };
const int dx[]{ 0, 1, 0, -1 };

vector<int> ret;

int dfs(int y, int x)
{
	visited[y][x] = true;
	int ret = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= M || nx < 0 || nx >= N || visited[ny][nx]) continue;
		if (map[ny][nx] == 0) continue;

		ret += dfs(ny, nx);
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> M >> N >> K;

	fill(&map[0][0], &map[0][0] + ms * ms, 1);

	int px1, py1, px2, py2;
	for (int i = 0; i < K; i++)
	{
		cin >> px1 >> py1 >> px2 >> py2;

		for (int j = py2 - 1; j >= py1; j--)
		{
			for (int k = px2 - 1; k >= px1; k--)
			{
				map[j][k] = 0;
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] || map[i][j] == 0) continue;
			ret.push_back(dfs(i, j));
		}
	}

	sort(ret.begin(), ret.end());

	cout << ret.size() << "\n";
	for (auto& e : ret)
		cout << e << " ";
	return 0;
}