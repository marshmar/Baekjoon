/*
* 핵심 알고리즘은 확산 + 바람을 구현하는 것
* 확산은 배열이 2개가 필요하다는 것. why? 미세먼지 확산 시작점이 서로 겹쳐있을 때 처리 필요
* 바람을 구현하는 것은 나는 직접 회전시키도록 구현했지만, 강의에서는 하나의 벡터에 바람을 표현해야할 지점들을 p_t로 저장하고
* 벡터를 순회하면서 원소들을 당기도록 구현함
*/
#include<iostream>
#include<queue>
#include<tuple>
#include<vector>
#include<cstring>
using namespace std;
using p_t = pair<int, int>;

const int ms = 50;
int r, c, t, ret;

int om[ms + 4][ms + 4], m[ms + 4][ms + 4];
bool visited[ms + 4][ms + 4];

const int dy[]{ -1, 0, 1, 0 };
const int dx[]{ 0, 1, 0, -1 };

vector<p_t> apos;

void expand(queue<p_t>& q)
{
	int y = 0, x = 0, cnt = 0;
	while (q.size())
	{
		tie(y, x) = q.front(); 
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
			if (m[ny][nx] == -1) continue;

			m[ny][nx] += (om[y][x] / 5);
			cnt++;
		}

		m[y][x] -= (om[y][x] / 5) * cnt;
		cnt = 0;
	}
	
}

void air()
{
	// 윗부분
	for (int i = apos[0].first-1; i > 0; i--)
	{
		m[i][0] = m[i - 1][0];
	}

	for (int i = 0; i < c - 1; i++)
	{
		m[0][i] = m[0][i + 1];
	}

	for (int i = 0; i < apos[0].first; i++)
	{
		m[i][c - 1] = m[i + 1][c - 1];
	}

	for (int i = c - 1; i > 0; i--)
	{
		if (i > 1)
			m[apos[0].first][i] = m[apos[0].first][i - 1];
		else
			m[apos[0].first][i] = 0;
	}

	// 아랫부분
	for (int i = apos[1].first + 1; i < r - 1; i++)
	{
		m[i][0] = m[i + 1][0];
	}

	for (int i = 0; i < c - 1; i++)
	{
		m[r - 1][i] = m[r - 1][i + 1];
	}

	for (int i = r - 1; i > apos[1].first; i--)
	{
		m[i][c - 1] = m[i - 1][c - 1];
	}

	for (int i = c - 1; i > 0; i--)
	{
		if (i > 1)
			m[apos[1].first][i] = m[apos[1].first][i - 1];
		else
			m[apos[1].first][i] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c >> t;

	queue<p_t> q;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> om[i][j];
			if (om[i][j] == -1)
			{
				apos.push_back({ i, j });
			}
			m[i][j] = om[i][j];
		}
	}

	while (t-- > 0)
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (m[i][j] > 0)
				{
					q.push({ i, j });
					visited[i][j] = 1;
				}
			}
		}

		expand(q);
		air();
		memcpy(om, m, sizeof(om));
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (m[i][j] > 0)
				ret += m[i][j];
		}
	}

	cout << ret << "\n";
	return 0;
}