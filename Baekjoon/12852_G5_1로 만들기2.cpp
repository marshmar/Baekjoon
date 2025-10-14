#include<iostream>
using namespace std;

const int ms = 1e7 + 4, INF = 987654321;
int dp[ms], n, nxt[ms];

int main()
{
	cin >> n;

	fill(dp, dp + ms, INF);
	int temp;

	dp[1] = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i % 3 == 0)
		{
			temp = dp[i / 3] + 1;
			if (dp[i] > temp)
			{
				nxt[i] = i / 3;
				dp[i] = temp;
			}
		}
		if (i % 2 == 0)
		{
			temp = dp[i / 2] + 1;
			if (dp[i] > temp)
			{
				nxt[i] = i / 2;
				dp[i] = temp;
			}
		}

		temp = dp[i - 1] + 1;
		if (dp[i] > temp)
		{
			nxt[i] = i - 1;
			dp[i] = temp;
		}
	}

	cout << dp[n] << "\n";
	int idx = n;
	while (idx != 0)
	{
		cout << idx << " ";
		idx = nxt[idx];
	}
	return 0;
}