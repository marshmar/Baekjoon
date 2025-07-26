/*
* 나는 먼저 visited를 구하고, dfs도 다시 돌아가면서 출력하면 되지 않나 라고 생각했으나.
* trace 알고리즘이 따로 있음
* 넘어갈때 마다 prev[next] = here
* 그리고 출력할 때 cout << prev[i]; i = prev[i];
* 이런식으로 역추적하면 ok
*/
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

int n, k;
const int ms = 200'000;
int visited[ms + 4];
long long cnt[ms + 4];

vector<int> ret;

void dfs(int cur, int vcnt)
{
	if (visited[cur] != vcnt) return;
	ret.push_back(cur);
	if (cur == n)
	{
		for (int i = ret.size() - 1; i >= 0; i--)
		{
			cout << ret[i] << " ";
		}
		exit(0);
	}

	dfs(cur - 1, vcnt - 1);
	dfs(cur + 1, vcnt - 1);
	if (cur % 2 == 0)
		dfs(cur / 2, vcnt - 1);

}
int main()
{
	cin >> n >> k;
	if (n == k)
	{
		cout << "0" << "\n";
		cout << n << "\n";
		return 0;
	}
	visited[n] = 1;
	cnt[n] = 1;
	queue<int> q;
	q.push(n);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == k) break;

		for (int next : {cur - 1, cur + 1, cur * 2})
		{
			if (next < 0 || next > ms) continue;

			if (!visited[next])
			{
				q.push(next);
				visited[next] = visited[cur] + 1;
			}
		}
	}

	cout << visited[k] - 1 << '\n';
	vector<int> t;
	dfs(k, visited[k]);

	return 0;
}