#include<iostream>
#include<vector>
#include<climits>
using namespace std;
using p_t = pair<int, int>;

int n, m, temp, ret = INT_MAX;
int p[11], comp[11], visited[11];
vector<int> adj[11];

p_t dfs(int cur, int v)
{
	visited[cur] = 1;
	p_t ret = { 1, p[cur] };
	for (int next : adj[cur])
	{
		if (comp[next] != v) continue;
		if (visited[next]) continue;
		p_t t = dfs(next, v);
		ret.first += t.first;
		ret.second += t.second;
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			cin >> temp;
			adj[i].push_back(temp);
			adj[temp].push_back(i);
		}
	}

	for (int i = 1; i < (1 << n) - 1; i++)
	{
		fill(comp, comp + 11, 0);
		fill(visited, visited + 11, 0);
		int idx1 = -1, idx2 = -1;
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				comp[j + 1] = 1;
				idx1 = j + 1;
			}
			else
				idx2 = j + 1;
		}

		p_t comp1 = dfs(idx1, 1);
		p_t comp2 = dfs(idx2, 0);
		if (comp1.first + comp2.first == n)
			ret = min(ret, abs(comp1.second - comp2.second));
	}

	cout << (ret == INT_MAX ? -1 : ret) << "\n";
	return 0;
}