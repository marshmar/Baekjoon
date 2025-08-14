#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
using p_t = pair<int, int>;
using ll = long long;

int n, k, mi, vi;
ll ret;
priority_queue<int> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	vector <p_t> v(n);
	vector <int> c(k);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	
	for (int i = 0; i < k; i++)
	{
		cin >> c[i];
	}

	sort(v.begin(), v.end());
	sort(c.begin(), c.end());

	int j = 0;
	for (int i = 0; i < k; i++)
	{
		while (j < n && v[j].first <= c[i])
			pq.push(v[j++].second);


		if(pq.size())
		{
			ret += pq.top();
			pq.pop();
		}
	}

	cout << ret << "\n";
	return 0;
}