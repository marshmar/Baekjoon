#include<iostream>
using namespace std;
const int ms = 10004;

int n, k, dp[ms];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k;
	dp[0] = 1;

	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		for (int j = temp; j <= k; j++)
		{
			dp[j] += dp[j - temp];
		}
	}

	cout << dp[k] << "\n";
	return 0;
}