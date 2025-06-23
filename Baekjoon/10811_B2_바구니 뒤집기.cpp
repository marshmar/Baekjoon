#include<iostream>

using namespace std;

int buckets[100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		buckets[i] = i + 1;

	for (int m = 0; m < M; m++)
	{
		int i, j;
		cin >> i >> j;
		i--; 
		j--;

		for (int k = 0; k < (j - i) / 2 + 1; k++)
		{
			std::swap(buckets[j - k], buckets[i + k]);
		}
	}

	for (int i = 0; i < N; i++)
		cout << buckets[i] << " ";
	return 0;
}