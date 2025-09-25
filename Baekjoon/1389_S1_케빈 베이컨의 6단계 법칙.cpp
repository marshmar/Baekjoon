/*
* 1389_S1_케빈 베이컨의 6단계 법칙
* 핵심 알고리즘: BFS
* 시간복잡도:O(V(V + E)) = O(V^2 + VE)
* 틀린 이유: DFS로 풀어서 한번 틀림(DFS는 최소값을 보장하지 않기 때문)
*/

#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

const int ms = 104;
int n, m, minStep = INT_MAX, ret;

vector<int> adj[ms];
int visited[ms];

void bfs(int start)
{
	int sum = 0;
	queue<int> q;
	visited[start] = 1;
	q.push(start);

	while (q.size())
	{
		int cur = q.front();
		q.pop();
		sum += (visited[cur] - 1);

		for (auto& next : adj[cur])
		{
			if (visited[next]) continue;

			visited[next] = visited[cur] + 1;
			q.push(next);
		}
	}

	
	if (minStep > sum)
	{
		minStep = sum;
		ret = start + 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		adj[a - 1].push_back(b - 1);
		adj[b - 1].push_back(a - 1);
	}

	for (int i = 0; i < n; i++)
	{
		fill(visited, visited + ms, 0);
		bfs(i);
	}

	cout << ret << "\n";
	return 0;
}