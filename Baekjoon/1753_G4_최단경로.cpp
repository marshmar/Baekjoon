#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using p_t = pair<int, int>;
const int INF = 1e9;
const int ms = 20'004;
int e, v, k;
vector<p_t> adj[ms];
vector<int> dist(ms, INF);

void dijkstra(int start)
{
	priority_queue<p_t, vector<p_t>, greater<p_t>> pq;
	dist[start] = 0;
	pq.push({ 0, start });

	while (pq.size())
	{
		int cur_cost = pq.top().first;
		int u = pq.top().second;	
		pq.pop();

		if (cur_cost != dist[u]) continue;

		for (auto& next : adj[u])
		{
			int new_cost = cur_cost + next.first;
			if (new_cost < dist[next.second])
			{
				dist[next.second] = new_cost;
				pq.push({ new_cost, next.second });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> v >> e >> k;

	int u, tv, w;
	for (int i = 0; i < e; i++)
	{
		cin >> u >> tv >> w;
		adj[u].push_back({ w, tv });
	}

	dijkstra(k);

	for (int i = 1; i <= v; i++)
	{
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
	return 0;
}