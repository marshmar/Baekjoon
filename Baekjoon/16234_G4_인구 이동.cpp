#include<iostream>
#include<tuple>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int n, l, r, ret;

const int ms = 54;
int m[ms][ms];
bool visited[ms][ms];

const int dy[]{ -1, 0, 1, 0 };
const int dx[]{ 0, 1, 0, -1 };

using p_t = pair<int, int>;
vector<pair<vector<p_t>, int>> u;
bool flag;

void bfs(int y, int x)
{
	int sum = m[y][x];
	vector<p_t> tu;
	queue<p_t> q;

	q.push({ y, x });
	tu.push_back({ y, x });
	visited[y][x] = 1;

	while (q.size())
	{
		int ty, tx;
		tie(ty, tx) = q.front(); q.pop();


		for (int i = 0; i < 4; i++)
		{
			int ny = ty + dy[i];
			int nx = tx + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if (visited[ny][nx]) continue;

			int diff = abs(m[ny][nx] - m[ty][tx]);

			if (diff >= l && diff <= r)
			{
				visited[ny][nx] = 1;
				sum += m[ny][nx];
				q.push({ ny, nx });
				tu.push_back({ ny, nx });

			}
		}
	}

	if (tu.size() > 1)
	{
		flag = true;
		int avg = sum / tu.size();
		u.push_back({ tu, avg});
	}

}

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
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> m[i][j];
		}
	}

	flag = true;
	while (flag)
	{
		flag = false;
		memset(visited, 0, sizeof(visited));
		u.clear();

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!visited[i][j])
				{
					bfs(i, j);
				}
			}
		}

		if (flag)
		{
			for (auto& cs : u)
			{
				for (auto& c : cs.first)
				{
					int y, x;
					tie(y, x) = c;
					m[y][x] = cs.second;
				}
			}
			ret++;
		}
	}

	cout << ret << "\n";
	return 0;
}