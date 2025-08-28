#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
using ll = long long;
using p_t = pair<ll, ll>;

int n, l;
ll ret;
vector<p_t> v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> l;

	ll s, e;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> e;
		v.push_back({ s, e-1 });
	}

	sort(v.begin(), v.end());
	ll pos = 0, q = 0;
	for (int i = 0; i < n; i++)
	{
		if (pos >= v[i].first)
		{
			q = ceil(((double)v[i].second - pos) / l);
			ret += q;
			pos += l * q;
		}
		else
		{
			q = ceil(((double)v[i].second + 1.0 - v[i].first) / l);
			ret += q;
			pos = v[i].first + l * q-1;
		}
	}

	cout << ret << "\n";
	return 0;
}