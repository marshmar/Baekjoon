#include<iostream>
#include<cstring>
using namespace std;

const int maxSize = 16, INF = 987654321;
int n, dist[maxSize][maxSize], dp[maxSize][1 << maxSize];

/*
* tsp 알고리즘 흐름
* 1) base: 모든 정점을 방문 했을 때 돌아오는 길이 있으면 더해주고 없으면 INF
* 2) dp가 존재하는 지 확인하고 존재하면 dp 반환
* 3) 존재하지 않으면 dp 갱신
*/


int tsp(int cur, int visited)
{
	// 1)
	if (visited == (1 << n) - 1)
	{
		return dist[cur][0] ? dist[cur][0] : INF;
	}

	// 2)
	int& ret = dp[cur][visited];
	if (ret != -1) return ret;

	// 3)
	ret = INF;
	for (int i = 0; i < n; i++)
	{
		if (visited & (1 << i)) continue;
		if (dist[cur][i] == 0) continue;
		ret = min(ret, tsp(i, visited | (1 << i)) + dist[cur][i]);
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
			cin >> dist[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	cout << tsp(0, 1) << "\n";
	return 0;
}