#include<iostream>
using namespace std;

const int ms = 16;
int n, m[ms][ms], dp[ms][ms][3], ret;

bool check(int ny, int nx, int d)
{
	if (ny < 0 || ny >= n || nx < 0 || nx >= n) return false;

	if (d == 0 || d == 1)
	{
		if (m[ny][nx] == 0) return true;
	}
	else if (d == 2)
	{
		if (m[ny][nx] == 0 && m[ny - 1][nx] == 0 && m[ny][nx - 1] == 0) return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> m[i][j];

	dp[0][1][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// 가로
			if (check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][0];
			if (check(i + 1, j + 1, 2)) dp[i + 1][j + 1][2] += dp[i][j][0];

			// 세로
			if (check(i + 1, j, 1)) dp[i + 1][j][1] += dp[i][j][1];
			if (check(i + 1, j + 1, 2)) dp[i + 1][j + 1][2] += dp[i][j][1];

			// 대각선
			if (check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][2];
			if (check(i + 1, j, 1)) dp[i + 1][j][1] += dp[i][j][2];
			if (check(i + 1, j + 1, 2)) dp[i + 1][j + 1][2] += dp[i][j][2];
		}
	}

	ret = dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2];
	cout << ret << "\n";
	return 0;
}