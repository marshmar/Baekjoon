#include<iostream>
#include<string>
#include<queue>
#include<tuple>

using namespace std;

const int si = 104;

int map[si][si];
int visited[si][si];

int N, M;

const int dy[]{ -1, 0, 1, 0 };
const int dx[]{ 0, 1, 0, -1 };

using p_t = pair<int, int>;

void bfs(int startY, int startX)
{
	visited[startY][startX] = 1;
	queue <p_t> q;
	q.push(make_pair(startY, startX));

	while (q.size())
	{
		int y = 0, x = 0;
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (visited[ny][nx]) continue;
			if (map[ny][nx] == 0) continue;

			visited[ny][nx] = visited[y][x] + 1;
			q.push(make_pair(ny, nx));
		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			map[i][j] = (s[j] - '0');
		}

	}

	bfs(0, 0);
	cout << visited[N - 1][M - 1] << "\n";
	return 0;
}