#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool checkCount(int& n)
{
	return n > 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	int N = 0;
	std::cin >> N;

	vector<int> v(N);
	vector<int> cnt(10, 0);

	for (int i = 0; i < N; i++)
	{
		std::cin >> v[i];
	}

	int start = 0, end = 0, ret = 1;
	cnt[v[end]]++;

	while (start < N)
	{
		while (end < N)
		{
			end++;
			if (end >= N)
				break;
			cnt[v[end]]++;


			if (count_if(cnt.begin(), cnt.end(), checkCount) > 2)
			{
				cnt[v[end]]--;
				end--;
				ret = max(ret, end - start + 1);
				break;
			}
			ret = max(ret, end - start + 1);

		}
		cnt[v[start]]--;
		start++;
	}

	cout << ret << '\n';

	return 0;
}