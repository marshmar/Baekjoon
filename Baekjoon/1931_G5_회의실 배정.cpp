#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using p_t = pair<int, int>;

int n, s, e, ret;
vector<p_t> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> e;
		v.push_back({ e, s });
	}
	sort(v.begin(), v.end());

	s = v[0].first;
	ret = 1;
	for (int i = 1; i < n; i++)
	{
		if (v[i].second >= s)
		{
			s = v[i].first;
			ret++;
		}
	}

	cout << ret << "\n";
}