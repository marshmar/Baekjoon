/*
* dp로 풀려고 했으나 못 풀었음.
* 핵심 알고리즘은 bfs
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int MAX = 200'000;
int visited[MAX + 4];
long long cnt[MAX + 4];
vector<int> ret[MAX+4];

int main()
{
	int n, k;
	cin >> n >> k;
	if (n == k)
	{
		cout << "0" << "\n";
		cout << "1" << "\n";
		return 0;
	}
	visited[n] = 1;
	cnt[n] = 1;
	queue<int> q;
	q.push(n);
	ret[n].push_back(n);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		
		for (int next : {cur - 1, cur + 1, cur * 2})
		{
			vector<int> t = ret[cur];

			if (next >= 0 && next <= MAX)
			{
				if (!visited[next])
				{
					q.push(next);
					visited[next] = visited[cur] + 1;
					t.push_back(next);
					ret[k] = t;
				}
				//else if (visited[next] == visited[cur] + 1)
				//	cnt[next] += cnt[cur];
			}
		}
	}

	cout << visited[k] - 1 << '\n';
	for (auto& e : ret[k])
		cout << e << " ";
	return 0;
}