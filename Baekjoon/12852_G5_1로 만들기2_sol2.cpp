#include<iostream>
using namespace std;

const int ms = 1'000'004, INF = 987654321;
int n, dp[ms], p[ms];
	
int main()
{
	cin >> n;
	fill(dp, dp + ms, INF);

	int tmp;
	dp[1] = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i % 3 == 0)
		{
			tmp = dp[i / 3] + 1;
			if (dp[i] > tmp)
			{
				p[i] = i / 3;
				dp[i] = tmp;
			}
		}
		if (i % 2 == 0)
		{
			tmp = dp[i / 2] + 1;
			if (dp[i] > tmp)
			{
				p[i] = i / 2;
				dp[i] = tmp;
			}
		}
		tmp = dp[i - 1] + 1;
		if (dp[i] > tmp)
		{
			p[i] = i - 1;
			dp[i] = tmp;
		}
	}

	cout << dp[n] << "\n";
	int idx = n;
	while (idx != 0)
	{
		cout << idx << " ";
		idx = p[idx];
	}
	return 0; 
}