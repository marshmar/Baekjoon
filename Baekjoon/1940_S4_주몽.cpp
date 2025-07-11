#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M, l, r, ret = 0;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cin >> M;

	vector<int> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	l = 0;
	r = N - 1;

	sort(v.begin(), v.begin() + N);

	while (l < r)
	{
		if (v[l] + v[r] < M)
			++l;
		else if (v[l] + v[r] > M)
			--r;
		else
		{
			++l; --r;
			ret++;
		}

	}
	cout << ret << endl;

	return 0;
}