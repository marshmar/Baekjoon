#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<climits>
using namespace std;
using p_t = pair<int, int>;
int n, m, ret = INT_MIN;
char p[5][5];
int visited[5][5];


// 1은 정지, 2는 오른쪽, 3은 아래
void solve(int y, int x, int sum, string s)
{
	cout << "y: " << y << " x: " << x << " " << s << "\n";
	if (y == n-1 && x == m-1)
	{
		if (visited[n - 1][m - 1] == 1)
		{
			cout << "bef sum: " << sum << "\n";
			sum += p[n - 1][m - 1] - '0';
		}

		else
		{
			cout << "bef sum: " << sum << "\n";
			cout << s + p[y][x] << "\n";
			sum += atoi((s + p[n - 1][m - 1]).c_str());
		}


		cout << sum << "\n";
		cout << "\n";
		ret = max(ret, sum);
		return;
	}

	if (visited[y][x]== 1)
	{
		sum += (p[y][x] - '0');

		if (x + 1 < m)
		{
			if (visited[y][x + 1]) return;
			visited[y][x + 1] = 1;
			solve(y, x + 1, sum, "");
			visited[y][x + 1] = 0;
		}
		else
		{
			if (visited[y+1][0]) return;
			visited[y+1][0] = 1;
			solve(y + 1, 0, sum, "");
			visited[y+1][0] = 0;
		}
		sum -= (p[y][x] - '0');

		if (x + 1 < m)
		{
			if (visited[y][x + 1]) return;
			visited[y][x + 1] = 2;
			solve(y, x + 1, sum, s + p[y][x]);
			visited[y][x + 1] = 0;
		}

		if (y + 1 < n)
		{
			if (visited[y + 1][x]) return;
			visited[y+1][x] = 3;
			solve(y+1, x, sum, s + p[y][x]);
			visited[y + 1][x] = 0;
		}
	}
	else if (visited[y][x] == 2)
	{
		cout << s + p[y][x] << "\n";
		int tn = atoi((s + p[y][x]).c_str());
		sum += tn;

		if (x + 1 < m)
		{
			if (visited[y][x + 1]) return;
			visited[y][x + 1] = 1;
			solve(y, x + 1, sum, "");
			visited[y][x + 1] = 0;
		}
		else
		{
			if (visited[y + 1][0]) return;
			visited[y + 1][0] = 1;
			solve(y + 1, 0, sum, "");
			visited[y + 1][0] = 0;
		}

		sum -= tn;

		if (x + 1 < m)
		{
			if (visited[y][x + 1]) return;
			visited[y][x + 1] = 2;
			solve(y, x + 1, sum, s + p[y][x]);
			visited[y][x + 1] = 0;
		}

	}
	else if (visited[y][x]== 3)
	{
		cout << (s + p[y][x]) << "\n";
		int tn = atoi((s + p[y][x]).c_str());
		sum += tn;

		if (x + 1 < m)
		{
			if (visited[y][x + 1]) return;
			visited[y][x + 1] = 1;
			solve(y, x + 1, sum, "");
			visited[y][x + 1] = 0;
		}
		else
		{
			if (visited[y + 1][0]) return;
			visited[y + 1][0] = 1;
			solve(y + 1, 0, sum,  "");
			visited[y + 1][0] = 0;
		}

		sum -= tn;

		if (y + 1 < n)
		{
			if (visited[y + 1][x]) return;
			visited[y+1][x] = 3;
			solve(y+1, x, sum, s + p[y][x]);
			visited[y + 1][x] = 0;
		}
	}
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
			p[i][j] = s[j];
		}
	}

	visited[0][0] = 1;
	solve(0, 0, 0, "");

	fill(&visited[0][0], &visited[0][0] + 5 * 5, 0);
	cout << "\n";
	visited[0][0] = 2;
	solve(0, 0, 0, "");

	fill(&visited[0][0], &visited[0][0] + 5 * 5, 0);
	cout << "\n";
	visited[0][0] = 3;
	solve(0, 0, 0, "");

	cout << ret << "\n";
	return 0;
}