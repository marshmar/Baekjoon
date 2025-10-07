#include<iostream>
#include<cstring>
using namespace std;

const int ms = 16, INF = 987654321;
int n, d[ms][ms], dp[ms][1<<ms];

int tsp(int cur, int visited)
{
	if (visited == (1 << n) - 1)
	{
		return d[cur][0] ? d[cur][0] : INF;
	}

	int& ret = dp[cur][visited];
	if (ret != -1) return ret;
	ret = INF;
	for (int i = 0; i < n; i++)
	{
		if (visited & (1 << i)) continue;
		if (d[cur][i] == 0) continue;
		ret = min(ret, tsp(i, visited | (1 << i)) + d[cur][i]);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> d[i][j];

	memset(dp, -1, sizeof(dp));
	cout << tsp(0, 1) << "\n";
	return 0;
}