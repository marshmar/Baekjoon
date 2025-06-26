#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(int x)
{
	return x > 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	int start = 0, end = 0, ret = 1;
	vector<int> cnt(10, 0);
	cnt[v[end]]++;

	while (start < N)
	{
		while (end < N)
		{
			end++;
			if (end >= N)
				break;

			cnt[v[end]]++;
			if (count_if(cnt.begin(), cnt.end(), compare) > 2)
			{
				cnt[v[end]]--;
				end--;
				ret = max(ret, end - start + 1);
				break;
			}
			else
				ret = max(ret, end - start + 1);
		}

		cnt[v[start]]--;
		start++;
	}

	cout << ret << '\n';
	return 0;
}