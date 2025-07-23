#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int n, m, maxRet = INT_MIN;
vector<int> adj[100'004];
bool visited[100'004];
vector<int> retVec;

int dfs(int h)
{
	visited[h] = 1;

	int temp = 1;
	for (auto& e : adj[h])
	{
		if (visited[e]) continue;
		temp += dfs(e);
	}

	return temp;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int f, t;
		cin >> f >> t;

		adj[t-1].push_back(f-1);
	}

	for (int i = 0; i < n; i++)
	{
		fill(&visited[0], &visited[n], 0);
		int ret = dfs(i);

		if (ret > maxRet)
		{
			maxRet = ret;
			retVec.clear();
			retVec.push_back(i + 1);
		}
		else if (ret == maxRet)
		{
			retVec.push_back(i+1);
		}
	}

	sort(retVec.begin(), retVec.end());

	for (auto& e : retVec)
		cout << e << " ";

}