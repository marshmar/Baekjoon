#include<iostream>
#include<string>
#include<queue>
#include<tuple>
using namespace std;

const int ms = 1004;
int r, c, sy, sx, ret = -1;
char map[ms][ms];
int fvisited[ms][ms], jvisited[ms][ms];

using p_t = pair<int, int>;
queue<p_t> q;

const int dy[]{ -1, 0, 1, 0 };
const int dx[]{ 0, 1, 0, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c;
	cin.ignore();
	
	string s;
	fill(&fvisited[0][0], &fvisited[0][0] + ms * ms, INT_MAX);
	for (int i = 0; i < r; i++)
	{
		cin >> s;
		for (int j = 0; j < s.length(); j++)
		{
			map[i][j] = s[j];
			if (s[j] == 'J')
			{
				sy = i;
				sx = j;
			}
			else if (s[j] == 'F')
			{
				q.push({ i, j });
				fvisited[i][j] = 1;
			}
		}
	}

	while (q.size())
	{
		int y, x;
		tie(y, x) = q.front(); q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
			if (fvisited[ny][nx] != INT_MAX || map[ny][nx] == '#') continue;

			fvisited[ny][nx] = fvisited[y][x] + 1;
			q.push({ ny, nx });
		}
	}

	jvisited[sy][sx] = 1;
	q.push({ sy, sx });

	while (q.size())
	{
		int y, x;
		tie(y, x) = q.front(); q.pop();

		if (y == 0 || y == r - 1 || x == 0 || x == c - 1)
		{
			ret = jvisited[y][x];
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
			if (map[ny][nx] == '#') continue;
			if (jvisited[ny][nx] || fvisited[ny][nx] + 1<= jvisited[ny][nx]) continue;

			jvisited[ny][nx] = jvisited[y][x] + 1;
			q.push({ ny, nx });
		}
	}

	if (ret != -1) cout << ret << "\n";
	else cout << "IMPOSSIBLE " << "\n";

	return 0;
}