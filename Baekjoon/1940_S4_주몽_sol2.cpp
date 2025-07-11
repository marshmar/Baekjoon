#include<iostream>
#include<vector>

using namespace std;

int N, M, cnt = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cin >> M;

	vector<int> v(N);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	if (M > 200'000) cout << 0 << endl;
	else
	{
		// combination
		for (int i = 0; i < N - 1; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				if (v[i] + v[j] == M) cnt++;
			}
		}

		cout << cnt << endl;
	}


	return 0;
}