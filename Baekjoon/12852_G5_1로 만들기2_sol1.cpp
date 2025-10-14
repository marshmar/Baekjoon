#include<iostream>
using namespace std;

const int ms = 1'000'004, INF = 987654321;
int n, dp[ms], p[ms];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	fill(dp, dp + ms, INF);
	dp[1] = 0;

	int temp;
	for (int i = 1; i <= n; i++)
	{	
		if (i % 3 == 0)
		{
			temp = dp[i / 3] + 1;
			if (dp[i] > temp)
			{
				p[i] = i / 3 ;
				dp[i] = temp;
			}
		}
		if (i % 2 == 0)
		{
			temp = dp[i / 2] + 1;
			if (dp[i] > temp)
			{
				p[i] = i / 2;
				dp[i] = temp;
			}
		}

		temp = dp[i - 1] + 1;
		if (dp[i] > temp)
		{
			p[i] = i-1;
			dp[i] = temp;
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