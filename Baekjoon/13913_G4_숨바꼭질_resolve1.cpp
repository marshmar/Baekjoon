#include<iostream>
#include<queue>

using namespace std;

const int ms = 200'000;
int n, k, ret;
int pre[ms + 4], visited[ms + 4];
vector<int> retVec;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	
	queue<int> q;
	visited[n] = 1;
	q.push(n);
	while (q.size())
	{
		int cur = q.front(); q.pop();

		if (cur == k)
		{
			ret = visited[k] - 1;
			break;
		}
		for (int next : {cur - 1, cur + 1, cur * 2})
		{
			if (next >= 0 && next <= ms)
			{
				if (visited[next]) continue;
				visited[next] = visited[cur] + 1;
				pre[next] = cur;
				q.push(next);
			}
		}
	}

	cout << ret << "\n";

	for (int i = k; i != n; i = pre[i])
		retVec.push_back(i);
	retVec.push_back(n);

	reverse(retVec.begin(), retVec.end());
	for (auto& e : retVec)
		cout << e << " ";
}