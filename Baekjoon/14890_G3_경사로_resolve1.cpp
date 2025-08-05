#include<iostream>
using namespace std;

const int ms = 104;
int n, l, ret;
int a[ms][ms], b[ms][ms];

void solve(int m[ms][ms])
{
	for (int i = 0; i < n; i++)
	{
		int cnt = 1;
		int j;
		for (j = 0; j < n - 1; j++)
		{
			if (m[i][j] == m[i][j + 1]) cnt++;
			else if (m[i][j] + 1 == m[i][j + 1] && cnt >= l) cnt = 1;
			else if (m[i][j] - 1 == m[i][j + 1] && cnt >= 0) cnt = 1 - l;
			else break;
		}

		if (j == n - 1 && cnt >= 0) ret++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			b[j][i] = a[i][j];
		}
	}

	solve(a); solve(b);
	cout << ret << "\n";
	return 0;
}