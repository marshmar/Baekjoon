#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, dn;
using p_t = pair<int, vector<int>>;
vector<p_t> v(51);
bool visited[51];

void dfs(int idx)
{
	v[idx].first = -2;
	visited[idx] = 1;

	for (int i = 0; i < v[idx].second.size(); i++)
	{
		if (visited[v[idx].second[i]]) continue;
		dfs(v[idx].second[i]);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		v[i].first = num;
		if (num != -1)
		{
			v[num].second.push_back(i);
		}
	}

	int p, ret = 0;
	cin >> dn;
	p = v[dn].first;

	if (p != -1)
	{
		dfs(dn);

		v[p].second.erase(find(v[p].second.begin(), v[p].second.end(), dn));

		for (int i = 0; i < n; i++)
		{
			if (v[i].first != -2 && v[i].second.size() == 0)
			{
				ret++;
			}
		}
	}
	cout << ret << "\n";
	return 0;
}