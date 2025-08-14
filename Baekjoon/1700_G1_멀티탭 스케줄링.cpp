#include<iostream>
#include<queue>
using namespace std;
using p_t = pair<int, int>;

const int ms = 100;
int n, ret, k, a[ms+4], cnt[ms+4];
bool visited[ms + 4];

priority_queue<p_t, vector<p_t>, greater<p_t>> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> a[i];
		cnt[a[i]]++;
	}
	
	for (int i = 0; i < k; i++)
	{
		if (visited[a[i]])
		{
			cnt[a[i]]--;
			continue;
		}
		if (pq.size() < n)
		{
			pq.push({cnt[a[i]],  a[i]});
			cnt[a[i]]--;
		}
		else
		{
			//cout << pq.top().second << "\n";
			visited[pq.top().second] = 0;
			pq.pop();
			pq.push({ cnt[a[i]],  a[i]});
			cnt[a[i]]--;
			ret++;
		}
		visited[a[i]] = 1;
	}

	cout << ret << "\n";
	return 0;
}