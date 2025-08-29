#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using p_t = pair<ll, ll>;

ll n, s, e, ret;
vector<p_t> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> e;
		v.push_back({s, e});
	}
	sort(v.begin(), v.end());

	s = v[0].first;
	e = v[0].second;

	for (int i = 1; i < n; i++)
	{
		if (e < v[i].first)
		{
			ret += e - s;
			s = v[i].first;
			e = v[i].second;
		}
		else if (e < v[i].second)
		{
			e = v[i].second;
		}
	}
	ret += e - s;
	cout << ret << "\n";
	return 0;
}