#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;
using p_t = pair<int, int>;

int n, c, a[1004];
map<int, int> mp, mp_first;
vector<p_t> v;

bool compare(p_t a, p_t b)
{
	if (a.first == b.first)
	{
		return mp_first[a.second] < mp_first[b.second];
	}
	return a.first > b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> c;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		mp[a[i]]++;
		if (mp_first[a[i]] == 0) mp_first[a[i]] = i + 1; // 0이 할당되면 문제가 발생하기 때문에 i+1로.
	}
	for (auto& it : mp)
		v.push_back({ it.second, it.first });

	sort(v.begin(), v.end(), compare);

	for (auto& i : v)
	{
		for (int j = 0; j < i.first; j++)
		{
			cout << i.second << " ";
		}
	}
	return 0;
}