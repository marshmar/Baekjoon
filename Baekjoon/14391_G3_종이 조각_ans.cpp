/*
* 0은 가로, 1은 세로
* 001	011
* 001	011
* 000	011
* 
* 첫 번째 줄 탐색: 0 * M + 0
* 두 번째 줄 탐색: 0 * M + 1
* 세 번째 줄 탐색: 0 * M + 2
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int n, m, ret;
int p[4][4];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &p[i][j]);
		}
	}

	// s가 0부터 4 * 4 16전까지 로직
	for (int s = 0; s < (1 << (n * m)); s++)
	{
		// 0을 체크하는 로직(가로를 체크하는 로직)
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			int cur = 0;
			for (int j = 0; j < m; j++)
			{
				int k = i * m + j;
				if ((s & (1 << k)) == 0)
					cur = cur * 10 + p[i][j];
				else
				{
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}

		// 1을 체크하는 로직(세로를 체크하는 로직)
		for (int j = 0; j < m; j++)
		{
			int cur = 0;
			for (int i = 0; i < n; i++)
			{
				int k = i * m + j;
				if ((s & (1 << k)) != 0)
					cur = cur * 10 + p[i][j];
				else
				{
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}

		ret = max(ret, sum);
	}

	cout << ret << "\n";
	return 0;
}