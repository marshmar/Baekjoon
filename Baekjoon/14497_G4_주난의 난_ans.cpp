#include<iostream>
#include<queue>
#include<string>
using namespace std;

const int ms = 304;
int n, m, sy, sx, dey, dex;
int visited[ms][ms];
char map[ms][ms];

const int dy[]{ -1, 0, 1, 0 };
const int dx[]{ 0, 1, 0, -1 };

queue<int> q;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	cin >> sy >> sx >> dey >> dex;

	sy--; sx--; dey--; dex--;
	cin.ignore();

	string s;
	for (int i = 0; i < n; i++)
	{
		getline(cin, s);
		for (int j = 0; j < m; j++)
			map[i][j] = s[j];
	}

	q.push(1000 * sy + sx);
	visited[sy][sx] = 1;
	int cnt = 0;
	while (map[dey][dex] != '0')
	{
		cnt++;
		queue<int> temp;
		while (q.size())
		{
			int y = q.front() / 1000;
			int x = q.front() % 1000;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
				visited[ny][nx] = cnt;
				if (map[ny][nx] != '0')
				{
					map[ny][nx] = '0';
					temp.push(1000 * ny + nx);
				}
				else
					q.push(1000 * ny + nx);
			}
		}
		q = temp;
	}

	cout << visited[dey][dex] << "\n";
	return 0;
}