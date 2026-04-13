#include<iostream>
#include<string>
using namespace std;
const int ms = 54;

int n, m, dp[ms][ms];
char coins[ms][ms];
bool visited[ms][ms];
const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };

bool isIn(int ny, int nx)
{
	return ny >= 0 && ny < n && nx >= 0 && nx < m;
}

int solve(int y, int x)
{
	if (!isIn(y, x) || coins[y][x] == 'H') return 0;
	if (visited[y][x])
	{
		cout << -1 << "\n";
		exit(0);
	}

	int& ret = dp[y][x];
	if (ret) return ret;

	visited[y][x] = 1;
	int num = (int)coins[y][x] - '0';
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i] * num;
		int nx = x + dx[i] * num;
		ret = max(ret, solve(ny, nx) + 1);
	}
	visited[y][x] = 0;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			coins[i][j] = s[j];
		}
	}

	cout << solve(0, 0) << "\n";
	return 0;
}