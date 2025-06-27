#include<iostream>

using namespace std;

const int maxSize = 104;
int paper[maxSize][maxSize] = {};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	int row, col;
	for (int i = 0; i < N; i++)
	{
		cin >> row >> col;
		for (int r = 0; r < 10; r++)
		{
			for (int c = 0; c < 10; c++)
			{
				paper[row + r][col + c]++;
			}
		}
	}

	int ret = 0;
	for (int i = 0; i < maxSize; i++)
	{
		for (int j = 0; j < maxSize; j++)
		{
			if (paper[i][j] >= 1)
				ret++;
		}
	}


	cout << ret << endl;
	return 0;
}