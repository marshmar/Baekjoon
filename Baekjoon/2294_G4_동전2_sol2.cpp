#include<iostream>
using namespace std;

const int ms = 10'004, INF = 987654321;
int n, k, dp[ms];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	int temp;

	fill(dp, dp + ms, INF);
	dp[0] = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		for (int j = temp; j <= k; j++)
		{
			dp[j] = min(dp[j], dp[j - temp] + 1);
		}
	}

	if (dp[k] == INF) cout << -1 << "\n";
	else cout << dp[k] << "\n";

	return 0;
}