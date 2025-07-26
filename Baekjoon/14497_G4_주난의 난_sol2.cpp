/*
* 강의를 보고 queue를 2개 사용할 수 있다는 내용을 듣고 만든 코드
* 핵심 알고리즘은 0은 계속 탐색하고, 1일때는 다른 queue에 저장해두었다가 다음 탐색에서 사용할 수 있도록 함.
*/
#include<iostream>
#include<queue>
#include<tuple>
#include<string>

using namespace std;

const int ms = 304;
int n, m, sy, sx, dey, dex;
char map[ms][ms];
int visited[ms][ms];

const int dy[]{ -1, 0, 1, 0 };
const int dx[]{ 0, 1, 0, -1 };

using p_t = pair<int, int>;

void bfs(int sy, int sx)
{
	queue<p_t> zq, oq;
	zq.push({ sy, sx });
	visited[sy][sx] = 1;

	while (true)
	{
		while (zq.size())
		{
			int y, x;
			tie(y, x) = zq.front();
			zq.pop();

			if (y == dey - 1 && x == dex - 1)
			{
				cout << visited[y][x];
				exit(0);
			}

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
				if (visited[ny][nx]) continue;
				if (map[ny][nx] == '1')
				{
					oq.push({ ny, nx });
					visited[ny][nx] = visited[y][x] + 1;
					map[ny][nx] = '0';
					continue;
				}
				
				visited[ny][nx] = visited[y][x];
				zq.push({ ny, nx });
			}
		}

		while (oq.size())
		{
			zq.push(oq.front());
			oq.pop();
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	cin >> sy >> sx >> dey >> dex;

	cin.ignore();
	string s;
	for (int i = 0; i < n; i++)
	{
		getline(cin, s);
		for (int j = 0; j < m; j++)
		{
			map[i][j] = s[j];
		}
	}

	bfs(sy - 1, sx - 1);
	return 0;
}
