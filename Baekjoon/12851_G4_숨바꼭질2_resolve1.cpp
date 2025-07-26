#include<iostream>
#include<queue>

using namespace std;

const int ms = 200'004;
int visited[ms], cnt[ms];
int n, k, ret;
queue<int> q;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k;
	
	if (n == k)
	{
		cout << "0" << '\n';
		cout << "1" << '\n';
		return 0;
	}

	q.push(n);
	visited[n] = 1;
	cnt[n] = 1;

	while (q.size())
	{
		int cur = q.front();
		q.pop();

		for (auto next : { cur - 1, cur + 1, cur * 2 })
		{
			if (next < 0 || next > ms) continue;

			if (!visited[next])
			{
				q.push(next);
				visited[next] = visited[cur] + 1;
				cnt[next] += cnt[cur];
			}
			else if (visited[next] == visited[cur] + 1)
				cnt[next] += cnt[cur];
		}
	}

	cout << visited[k] - 1<< "\n";
	cout << cnt[k] << "\n";
	return 0;
}