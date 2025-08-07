#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<climits>
using namespace std;

const int ms = 4;
int n, m, sum, ret = INT_MIN;
int p[4][4];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &p[i][j]);

	for (int s = 0; s < (1 << (n * m)); s++)
	{
		sum = 0;
		// 가로 체크
		for (int i = 0; i < n; i++)
		{
			int cur = 0;
			for (int j = 0; j < m; j++)
			{
				int idx = i * m + j;
				if ((s & (1 << idx)) == 0)
					cur = cur * 10 + p[i][j];
				else
				{
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;	// 마지막이 0일 경우 더해줘야 하기에 
		}

		// 세로 체크
		for (int j = 0; j < m; j++)
		{
			int cur = 0;
			for (int i = 0; i < n; i++)
			{
				int idx = i * m + j;
				if ((s & (1 << idx)) != 0)
					cur = cur * 10 + p[i][j];
				else
				{
					sum += cur;
					cur = 0;
				}
			}
			sum += cur; // 마지막이 0일 경우 더해줘야 하기에 
		}

		ret = max(ret, sum);
	}

	cout << ret << "\n";
	return 0;
}