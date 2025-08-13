#include<iostream>
#include<vector>
#include<algorithm>
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
		v.push_back({ s, e });
	}
	sort(v.begin(), v.end());

	s = v[0].first;
	e = v[0].first + v[0].second;
	for (int i = 1; i < n; i++)
	{
		if (v[i].first < e)
		{
			s = e;
			e = s + v[i].second;
		}
		else
		{
			s = v[i].first;
			e = s + v[i].second;
		}
		//cout << "s: " << s << " e: " << e << "\n";
	}

	cout << e << "\n";
	return 0;
}