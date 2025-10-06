#include<iostream>
#include<climits>
#include<cstring>
using namespace std;

const int ms = 16, INF = 987654321;
int n, w[ms][ms], dp[ms][1 << ms];

int tsp(int here, int visited)
{
	// 모든 정점을 다 방문했을 경우
	if (visited == (1 << n) - 1)
	{
		// 처음으로 돌아오는 경로가 있는지 체크하고 없으면 INF
		return w[here][0] ? w[here][0] : INF;
	}

	int& ret = dp[here][visited];
	if (ret != -1) return ret;
	ret = INF;
	for (int i = 0; i < n; i++)
	{
		if (visited & (1 << i)) continue;
		if (w[here][i] == 0) continue;
		ret = min(ret, tsp(i, visited | (1 << i)) + w[here][i]);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> w[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	cout << tsp(0, 1) << "\n";
	
	return 0;
}