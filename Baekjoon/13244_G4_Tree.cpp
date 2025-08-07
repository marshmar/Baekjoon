/*
* 트리의 성질을 알면 풀 수 있는 굉장히 쉬운 문제
* 트리의 간선은 V-1, 한번의 탐색으로 모두 탐색 가능
* 출력을 graph로 해야하는데 grpah로 해버려서 한번 틀림(앞으로 출력은 꼭 복붙하자)
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int ms = 1004;
int t, n, m, n1, n2;
bool visited[ms];
bool flag;
vector<int> adj[ms];

void bfs(int idx, int n)
{
	visited[idx] = 1;
	queue<int> q;
	q.push(idx);
	
	int cnt = 1;
	while (q.size())
	{
		int cur = q.front();
		q.pop();
		
		for (int i = 0; i < adj[cur].size(); i++)
		{
			int next = adj[cur][i];
			if (visited[next]) continue;
			visited[next] = 1;
			q.push(next);
			cnt++;
		}
	}

	if (cnt != n)
		flag = 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n;
		cin >> m;
		
		for (auto& e : adj)
			e.clear();

		for (int j = 0; j < m; j++)
		{
			cin >> n1 >> n2;

			adj[n1].push_back(n2);
			adj[n2].push_back(n1);
		}

		flag = 1;
		if (m <= n - 2 || m >= n)
			flag = 0;
		else
		{
			fill(&visited[0], &visited[0] + ms, 0);
			bfs(1, n);
		}
		
		if (flag) cout << "tree" << "\n";
		else cout << "graph" << "\n";
	}
	return 0;
}