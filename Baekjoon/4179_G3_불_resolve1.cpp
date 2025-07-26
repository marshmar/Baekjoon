#include<iostream>
#include<queue>
#include<climits>
#include<tuple>
const int ms = 1004;
int r, c, sy, sx, y, x, ret;
char m[ms][ms];
int fvisited[ms][ms], jvisited[ms][ms];
const int dy[]{ -1, 0, 1, 0 };
const int dx[]{ 0, 1, 0, -1 };
using namespace std;
using p_t = pair<int, int>;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	queue<p_t> q;
	fill(&fvisited[0][0], &fvisited[0][0] + ms * ms, INT_MAX);

	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> m[i][j];

			if (m[i][j] == 'J')
			{
				sy = i;
				sx = j;
			}

			if (m[i][j] == 'F')
			{
				q.push({ i, j });
				fvisited[i][j] = 1;
			}
		}
	}
	
	while (q.size())
	{
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
			if (fvisited[ny][nx] != INT_MAX || m[ny][nx] == '#') continue;
			fvisited[ny][nx] = fvisited[y][x] + 1;
			q.push({ ny, nx });
		}
	}

	jvisited[sy][sx] = 1;
	q.push({ sy, sx });

	while (q.size())
	{
		tie(y, x) = q.front();
		q.pop();

		if (y == 0 || x == 0 || y == r - 1 || x == c - 1)
		{
			ret = jvisited[y][x];
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
			if (jvisited[ny][nx] || m[ny][nx] == '#') continue;
			if (fvisited[ny][nx] <= jvisited[y][x] + 1) continue;
			jvisited[ny][nx] = jvisited[y][x] + 1;
			q.push({ ny, nx });
		}
	}


	if (ret != 0) cout << ret << "\n";
	else cout << "IMPOSSIBLE " << "\n";
}