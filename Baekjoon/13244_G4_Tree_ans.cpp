#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

const int ms = 1004;
int t, n, m, a, b, cnt;
bool visited[ms];
vector<int> adj[ms];

void dfs(int cur)
{
	visited[cur] = 1;
	for (int next : adj[cur])
	{
		if (!visited[next])
			dfs(next);
	}
}
int main()
{
	scanf("%d\n", &t);
	while (t--)
	{
		for (int i = 0; i < ms; i++)
			adj[i].clear();

		fill(visited, visited + ms, 0);
		cnt = 0;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d", &a, &b);
			adj[b].push_back(a);
			adj[a].push_back(b);
		}

		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
			{
				dfs(i);
				cnt++;
			}
		}

		if (m == n - 1 && cnt == 1) puts("tree");
		else puts("graph");
	}
	return 0;
}