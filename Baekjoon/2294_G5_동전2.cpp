#include<iostream>
using namespace std;

const int mn = 104, mk = 10'004, INF = 987654321;
int n, k, dp[mk];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	fill(dp, dp + mk, INF);
	cin >> n >> k;

	dp[0] = 0;
	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		for (int j = num; j <= k; j++)
		{
			dp[j] = min(dp[j], dp[j - num] + 1);
		}
	}

	if (dp[k] == INF) cout << -1 << "\n";
	else cout << dp[k] << "\n";

	return 0;
}