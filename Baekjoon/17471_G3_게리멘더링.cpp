#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
#include<bitset>
using namespace std;

int n, visited, sum, ret = INT_MAX;
vector<int> adj[10], coms;
int p[10];

void dfs(int idx, int c)
{
	//cout << "idx: " << idx << "\n";

	for (int i = 0; i < adj[idx].size(); i++)
	{
		if (visited & (1 << adj[idx][i])) continue;
		if (!(c & (1 << adj[idx][i]))) continue;
		visited |= (1 << adj[idx][i]);
		sum += p[adj[idx][i]];
		dfs(adj[idx][i], c);
	}
}

void combi(int idx, int c, int m)
{
	if (idx == m)
		coms.push_back(c);

	for (int i = idx + 1; i < n; i++)
	{
		c |= (1 << i);
		combi(idx + 1, c, m);
		c &= ~(1 << i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
	}

	int na, tp;
	for (int i = 0; i < n; i++)
	{
		cin >> na;
		for (int j = 0; j < na; j++)
		{
			cin >> tp;
			tp -= 1;
			adj[i].push_back(tp);
		}
	}


	for (int i = 0; i < n / 2; i++)
	{
		combi(-1, 0, i);
	}

	int start, tsum, mask = (1 << n) - 1;
	for (auto& e : coms)
	{
		//cout << bitset<10>(e) << "\n";
		start = log2(e & -e);
		//cout << "start: " << start << "\n";
		visited = 1 << start;
		sum = p[start];
		dfs(start, e);
		tsum = sum;
		if (visited != e) continue;

		//cout << "\n";
		start = log2(~e & (e + 1));
		visited = 1 << start;
		sum = p[start];
		//cout << bitset<10>(~e & mask) << "\n";
		dfs(start, ~e & mask);
		if (visited != (~e & mask)) continue;

		//cout << "tsum: " << tsum << "\n";
		//cout << "sum: " << sum << "\n";
		ret = min(ret, abs(tsum - sum));
	}

	if (ret == INT_MAX) cout << -1 << "\n";
	else cout << ret << "\n";

	return 0;
}