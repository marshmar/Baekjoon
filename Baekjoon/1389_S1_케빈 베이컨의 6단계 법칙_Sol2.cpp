/*
* 1389_S1_케빈 베이컨의 6단계 법칙
* 핵심 알고리즘: Floyd-Warshall
* 시간복잡도: O(N^3)
*/
#include<iostream>
#include<climits>
using namespace std;

const int INF = 1e9;
const int ms = 104;

int dist[ms][ms];
int n, m, ret;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		dist[a][b] = 1;
		dist[b][a] = 1;
	}

	// 거쳐가는 노드
	for (int k = 1; k <= n; k++)
	{
		// 출발 노드
		for (int i = 1; i <= n; i++)
		{
			// 목표 노드
			for (int j = 1; j <= n; j++)
			{
				if (dist[i][k] != INF && dist[k][j] != INF)
				{
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}

	int minSum = INT_MAX;
	for (int i = 1; i <= n; i++)
	{
		int tsum = 0;
		for (int j = 0; j <= n; j++)
		{
			tsum += dist[i][j];
		}

		if (minSum > tsum)
		{
			minSum = tsum;
			ret = i;
		}
	}

	cout << ret << "\n";
	return 0;
}