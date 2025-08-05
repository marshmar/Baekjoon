/*
* 백준 2234_G3_성곽 문제
* 핵심 알고리즘은 dfs 알고리즘과 비트마스킹을 이용하여 벽을 탐지하는 로직 
* 공간마다 번호를 매겨서 다른 공간인지 판단하고 다른 공간이면 벽을 허물어 넓이를 더해준다음 최대 넓이를 찾는 로직
*/
#include<iostream>
#include<climits>
#include<tuple>
#include<vector>
using namespace std;
using p_t = pair<int, int>;
using t_t = tuple<int, int, int>;

const int ms = 51;
int n, m, cnt, a, rcnt, ma = INT_MIN, rma = INT_MIN;
t_t map[ms][ms];
bool visited[ms][ms];

const int dy[]{0, -1, 0, 1};
const int dx[]{-1, 0, 1, 0};

int dfs(int y, int x, vector<p_t>& cc)
{
	int tcnt = 1;
	cc.push_back({ y, x });
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (visited[ny][nx]) continue;
		if (get<0>(map[y][x]) & (1 << i)) continue;

		visited[ny][nx] = 1;	
		tcnt += dfs(ny, nx, cc);
	}

	return tcnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n;

	int temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> temp;
			map[i][j] = { temp, 0, 0 };
		}
	}


	int y, x, ta;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			vector<p_t> temp;
			if (!visited[i][j])
			{
				visited[i][j] = 1;
				rcnt++;
				ta = dfs(i, j, temp);
				ma = max(ma, ta);
				for (auto& e : temp)
				{
					tie(y, x) = e;
					get<1>(map[y][x]) = cnt;
					get<2>(map[y][x]) = ta;
				}
				cnt++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (j+1 < m && get<1>(map[i][j]) != get<1>(map[i][j + 1]))
			{
				rma = max(rma, get<2>(map[i][j]) + get<2>(map[i][j + 1]));
			}

			if (i+1 < n && get<1>(map[i][j]) != get<1>(map[i+1][j]))
			{
				rma = max(rma, get<2>(map[i][j]) + get<2>(map[i+1][j]));
			}
		}
	}

	cout << rcnt << "\n";
	cout << ma << "\n";
	cout << rma << "\n";
	return 0;
}

void print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << get<2>(map[i][j]) << " ";
		}
		cout << "\n";
	}
}