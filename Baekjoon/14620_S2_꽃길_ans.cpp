#include<iostream>
#include<climits>
using namespace std;

int n, ret = INT_MAX;

const int ms = 11;

int m[ms][ms];
bool visited[ms][ms];

const int dy[]{ -1, 0, 1, 0 };
const int dx[]{ 0, 1, 0, -1 };

bool check(int y, int x)
{
	if (visited[y][x]) return 0;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx])
			return 0;
	}
	return 1;
}

int setFlower(int y, int x)
{
	visited[y][x] = 1;
	int s = m[y][x];
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		visited[ny][nx] = 1;
		s += m[ny][nx];
	}
	return s;
}

void removeFlower(int y, int x)
{
	visited[y][x] = 0;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		visited[ny][nx] = 0;
	}
}
void solve(int cnt, int sum)
{
	if (cnt == 3)
	{
		ret = min(ret, sum);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (check(i, j))
			{
				solve(cnt + 1, sum + setFlower(i, j));
				removeFlower(i, j);
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> m[i][j];

	solve(0, 0);
	cout << ret << "\n";
	return 0;
}