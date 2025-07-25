/*
	알고리즘은 생각했으나 마지막에 1000 * 1000 부분에서 시간초과가 발생해 결국엔 답을 본 문제
	핵심 알고리즘은 bfs와 2개의 visited 배열(즉 불의 최단거리와 지훈이의 최단거리를 비교하는 문제)
	먼저 불을 bfs를 통해 확산시켜 visited를 누적시키고
	지훈이를 bfs 시키면서 불의 visited보다 낮으면 이동할 수 있도록 하면서 visited를 누적.
	그리고 지훈이가 벽에 닿으면 그 지점의 visited를  확인
	bfs가 모두 종료되었음에도 ret = 0이면 탈출이 불가능한 거기 때문에 IMPOSSIBLE 출력

	초기에 fvisited를 INF로 초기화하는 이유 -> 0으로 초기화 하면 불이 하나도 없을 경우 이동할 수 없음
*/
#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

const int INF = 987654321;
const int ms = 1004;
char m[ms][ms];
int r, c, sy, sx, y, x, ret;

const int dy[]{ -1, 0, 1, 0 };
const int dx[]{ 0, 1, 0, -1 };

int fvisited[ms][ms], jvisited[ms][ms];

using p_t = pair<int, int>;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	queue<p_t> q;
	cin >> r >> c;
	fill(&fvisited[0][0], &fvisited[0][0] + ms * ms, INF);
	
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> m[i][j];
			if (m[i][j] == 'F')
			{
				fvisited[i][j] = 1;
				q.push({ i, j });
			}
			else if (m[i][j] == 'J')
			{
				sy = i;
				sx = j;
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
			if (fvisited[ny][nx] != INF || m[ny][nx] == '#') continue;
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
		if (y == r - 1 || x == c - 1 || y == 0 || x == 0)
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

	return 0;
}