/*
* 처음에는 육지의 Connected Component를 구하고, 이 중 2개를 조합으로 선택하여
* 목적지에 도달할 때 까지 모든 경우의 수를 구하여 bfs를 돌렸으나, 시간초과가 발생했고
* 이렇게 할 필요 없이 그냥 각 육지 지점에서 bfs를 돌리면 그 자체값이 모든 지점에 대해
* 최단 거리를 구할 수 있기 때문에, 모든 육지에 대해 bfs를 돌리고
* max값을 찾으면 정답을 구할 수 있다.
* 실수: ret에 -1을 해주어야 하는데 ret을 INT_MIN으로 설정해서 오버플로가 발생함.
*/
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;

int n, m, ret;

const int ms = 51;
char map[ms][ms];
int visited[ms][ms];

using p_t = pair<int, int>;
vector<vector<p_t>> lcc, c;

const int dy[]{ -1, 0, 1, 0 };
const int dx[]{ 0, 1, 0, -1 };

int bfs(int y, int x)
{
	int mx = 0;
	visited[y][x] = 1;
	queue<p_t> q;
	q.push({ y, x });
	
	while (q.size())
	{
		int ty, tx;
		tie(ty, tx) = q.front();
		q.pop();


		for (int i = 0; i < 4; i++)
		{
			int ny = ty + dy[i];
			int nx = tx + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (visited[ny][nx]) continue;
			if (map[ny][nx] == 'W') continue;

			visited[ny][nx] = visited[ty][tx] + 1;
			mx = max(mx, visited[ny][nx]);
			q.push({ ny, nx });

		}
	}
	return mx;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++)
		{
			map[i][j] = s[j];
		}
	}

	ret = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 'L')
			{
				fill(&visited[0][0], &visited[0][0] + ms * ms, 0);
				ret = max(ret, bfs(i, j)-1);
			}

		}
	}

	cout << ret << "\n";
	return 0;
}