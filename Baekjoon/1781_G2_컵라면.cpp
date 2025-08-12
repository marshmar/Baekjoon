#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
using p_t = pair<int, int>;

int n, c, d, ret;
vector<p_t> v;

priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> d >> c;
		v.push_back({ d, c });
	}
	sort(v.begin(), v.end());

	int td = 1;
	for (int i = 0; i < n; i++)
	{
		pq.push(v[i].second);
		td = v[i].first;
		if (pq.size() > td)
		{
			pq.pop();
		}
	}

	while (pq.size())
	{
		ret += pq.top();
		pq.pop();
	}

	cout << ret << "\n";
}