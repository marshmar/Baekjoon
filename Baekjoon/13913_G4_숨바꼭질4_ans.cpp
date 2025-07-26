#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

const int ms = 200'004;
vector<int> v;
queue<int> q;

int n, k, ret;
int visited[ms], pre[ms];

int main()
{
	cin >> n >> k;
	visited[n] = 1;
	q.push(n);

	while (q.size())
	{
		int cur = q.front();
		q.pop();
		if (cur == k)
		{
			ret = visited[k];
			break;
		}
		for (int next : {cur + 1, cur - 1, cur * 2})
		{
			if (next < 0 || next >= ms || visited[next]) continue;
			visited[next] = visited[cur] + 1;
			pre[next] = cur;
			q.push(next);
		}
	}


	for (int i = k; i != n; i = pre[i])
		v.push_back(i);
	v.push_back(n);

	cout << ret - 1 << "\n";
	reverse(v.begin(), v.end());
	for (auto& e : v) cout << e << " ";
	return 0;
}