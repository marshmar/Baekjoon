/*
* 핵심 알고리즘은 bfs
* 내가 틀린 이유: 똑같은 지점에 수빈이는 홀수로 방문할 수도 있고, 짝수로 방문할 수도 있기 때문에,
* 짝수와 홀수를 둘다 기록해 두어야 풀 수 있다.
*/
#include<iostream>
#include<queue>
#include<climits>
using namespace std;

const int MAX = 500'000;
int visited[MAX + 4], dvisited[MAX+4];

int main()
{
	int n, k, plus = 1, orik;
	cin >> n >> k;
	if (n == k)
	{
		cout << "0" << "\n";
		return 0;
	}

	orik = k;
	fill(&dvisited[0], &dvisited[0] + MAX + 4, 0);
	dvisited[k] = 1;
	while (k <= MAX)
	{
		dvisited[k + plus] = dvisited[k] + 1;
		k += plus;
		plus += 1;
	}

	int ret = INT_MAX;
	visited[n] = 1;
	queue<int> q;
	q.push(n);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int next : {cur - 1, cur + 1, cur * 2})
		{
			if (next >= 0 && next <= MAX)
			{
				if (!visited[next])
				{
					q.push(next);
					visited[next] = visited[cur] + 1;
				}

				if (visited[next] <= dvisited[next])
				{
					if(visited[next] % 2 == dvisited[next] % 2)
						ret = min(ret, dvisited[next]);
				}	
			}
		}
	}


	k = orik;
	plus = 1;

	while (k <= MAX)
	{
		cout << "k: " << k << " divisited[k]: " << dvisited[k] << " visited[k]: " << visited[k] << "\n";
		k += plus;
		plus += 1;
	}


	if (ret != INT_MAX)
		cout << ret - 1 << '\n';
	else
		cout << -1 << "\n";

	return 0;
}