#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<tuple>
using namespace std;
using p_t = pair<int, int>;

const int ms = 104;
int n, k, l, dir = 1, t;
int m[ms][ms];

queue<p_t> c;
deque<p_t> snake;
const int dy[]{ -1, 0, 1, 0 };
const int dx[]{ 0, 1, 0, -1 };

void print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << m[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k; 

	int ky = 0, kx = 0;
	for (int i = 0; i < k; i++)
	{
		cin >> ky >> kx;
		m[ky - 1][kx - 1] = 1;
	}

	cin >> l;

	int time;
	char d;
	for (int i = 0; i < l; i++)
	{
		cin >> time >> d;
		c.push({ time, d });
	}
	
	snake.push_back({ 0, 0 });
	m[0][0] = 2;
	int ny = 0, nx = 0, y = 0, x = 0;
	while (true)
	{
		t++;

		// 이동
		tie(y, x) = snake.back();
		ny = y + dy[dir];
		nx = x + dx[dir];

		if (ny < 0 || ny >= n || nx < 0 || nx >= n) break;
		if (m[ny][nx] == 2) break;
		snake.push_back({ ny, nx });
		if (m[ny][nx] != 1)
		{
			m[snake.front().first][snake.front().second] = 0;
			snake.pop_front();
		}
		m[ny][nx] = 2;

		// 뱀의 방향 변환
		if (c.size() && t == c.front().first)
		{
			if (c.front().second == (int)('L'))
				dir = dir - 1 < 0 ? 3 : dir - 1;
			else
				dir = dir + 1 > 3 ? 0 : dir + 1;
			c.pop();
		}
	}

	cout << t << "\n";
	return 0;
}