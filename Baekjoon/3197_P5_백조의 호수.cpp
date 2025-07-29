/*
* 충분히 풀 수 있었던 문제지만 아쉽게도 못 풀었다.
* 가장 핵심 알고리즘은 bfs를 한단계씩 진행하는 것.(플루드 필)
* 백조에 대한 탐색을 먼저 하고, 만나지 않는다면 얼음을 녹이고,
* 이 루프를 계속 돌게끔 하는 것.
* visited를 초기화하지 않고 유지하는 알고리즘이 중요.
* 
* wq: water queue, wtq: water temp queue, sq: swan queue, stq: swan temp queue
*/
#include<iostream>
#include<string>
#include<queue>
#include<tuple>
#include<vector>
#include<algorithm>
using namespace std;
using p_t = pair<int, int>;

const int ms = 1504;
char map[ms][ms];
int wvisited[ms][ms], svisited[ms][ms];

int r, c, sy, sx, ret;
queue<p_t> wq, sq, wtq, stq;

const int dy[]{ -1, 0, 1, 0 };
const int dx[]{ 0, 1, 0, -1 };

void qclear(queue<p_t>& q)
{
	queue<p_t> empty;
	q = empty; // swap(q, empty)
}

void Melt()
{
	while (wq.size())
	{
		int y, x;
		tie(y, x) = wq.front(); wq.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= r || nx < 0 || nx >= c || wvisited[ny][nx]) continue;
			if (map[ny][nx] == 'X')
			{
				wvisited[ny][nx] = 1;
				wtq.push({ ny, nx });
				map[ny][nx] = '.';
			}
		}
	}
}

bool bfs()
{
	while (sq.size())
	{
		int y, x;
		tie(y, x) = sq.front(); sq.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= r || nx < 0 || nx >= c || svisited[ny][nx]) continue;
			svisited[ny][nx] = 1;
			if (map[ny][nx] == '.') sq.push({ ny, nx });
			else if (map[ny][nx] == 'X') stq.push({ ny, nx });
			else if (map[ny][nx] == 'L') return true;
			
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c;
	string s;
	for (int i = 0; i < r; i++)
	{
		cin >> s;
		for (int j = 0; j < c; j++)
		{
			map[i][j] = s[j];
			if (map[i][j] == 'L')
			{
				sy = i;
				sx = j;
			}
			if (map[i][j] == '.' || map[i][j] == 'L')
			{
				wvisited[i][j] = 1;
				wq.push({ i, j });
			}
		}
	}
	
	sq.push({ sy, sx });
	svisited[sy][sx] = 1;
	while (true)
	{
		if (bfs()) break;
		Melt();
		// 플루드 필
		wq = wtq;
		sq = stq;
		qclear(wtq);
		qclear(stq);
		ret++;
	}

	cout << ret << "\n";
	return 0;
}