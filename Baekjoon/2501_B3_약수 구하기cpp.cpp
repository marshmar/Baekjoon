#include<iostream>

using namespace std;

int main()
{
	int N, K;

	cin >> N >> K;

	if (K == 1) {
		cout << 1;
		return 0;
	}

	int i = 2, cnt = 1;

	while (i < N)
	{
		if (N % i == 0)
			cnt++;

		if (cnt == K)
		{
			cout << i;
			return 0;
		}

		i++;
	}

	cnt++;
	if (i == N && cnt == K)
		cout << i;
	else
		cout << 0;
	return 0;
}