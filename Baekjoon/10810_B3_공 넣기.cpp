#include<iostream>

using namespace std;

int buckets[100];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int r = 0; r < M; r++)
	{
		int i, j, k;
		cin >> i >> j >> k;
		for (int index = i-1; index < j; index++)
		{
			buckets[index] = k;
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << buckets[i] << ' ';
	}
}