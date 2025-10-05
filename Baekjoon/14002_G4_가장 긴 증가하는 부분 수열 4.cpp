#include<iostream>
#include<vector>
using namespace std;

const int ms = 1'000'004;
int n, a[ms], cnt[ms], prev_list[ms], ret, idx;
vector<int> v;

void solve(int idx)
{
	if (idx == -1) return;
	v.push_back(a[idx]);
	solve(prev_list[idx]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	fill(prev_list, prev_list + ms, -1);;

	for (int i = 0; i < n; i++)
	{
		int maxValue = 0;
		for (int j = 0; j < i; j++)
		{
			if (a[j] < a[i] && maxValue < cnt[j])
			{
				maxValue = cnt[j];
				prev_list[i] = j;
			}
				
		}
		cnt[i] = maxValue + 1;
		if (ret < cnt[i])
		{
			ret = cnt[i];
			idx = i;
		}
	}

	solve(idx);

	cout << ret << "\n";
	for (int i = v.size()-1; i >= 0; i--)
		cout << v[i] << " ";
	cout << "\n";
	return 0;
}