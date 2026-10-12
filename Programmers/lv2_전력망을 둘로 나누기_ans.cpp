#include<iostream>
#include<vector>
#include<functional>
#include<limits>

using namespace std;

int solution(int n, vector<vector<int>> wires)
{
	vector<vector<int>> graph(n + 1);
	for (int i = 0; i < (int)wires.size(); i++)
	{
		int u = wires[i][0];
		int v = wires[i][1];
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	vector<int> siz(n + 1);
	function<void(int, int)> dfs = [&](int cur, int prev) -> void
		{
			siz[cur] = 1;
			for (int next : graph[cur])
			{
				if (next == prev) continue;
				dfs(next, cur);
				siz[cur] += siz[next];
			}
		};
	dfs(1, -1);
	int answer = INT_MAX;
	for (int i = 1; i <= n; i++)
	{
		for (int j : graph[i])
		{
			int l = siz[j];
			int r = n - siz[j];
			answer = min(answer, abs(l - r));
		}
	}

	return answer;
}