#include<iostream>
#include<string>
#include<queue>
#include<tuple>

using namespace std;

using pi = pair<int, int>;

int map[104][104];
int visited[104][104];
int n, m;

int dy[4]{ -1, 0, 1, 0 };
int dx[4]{ 0, 1, 0, -1 };

void bfs(int startY, int startX)
{
	visited[startY][startX] = 1;
	queue<pi> q;
	q.push({ startY, startX });

	while (q.size())
	{
		int y, x;
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= n) continue;
			if (nx < 0 || nx >= m) continue;
			if (map[ny][nx] == 0) continue;
			if (visited[ny][nx]) continue;

			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}
}

int main()
{
	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < s.length(); j++)
		{
			map[i][j] = s[j] - '0';
		}
	}

	bfs(0, 0);
	cout << visited[n - 1][m - 1] << endl;
	
	return 0;
}