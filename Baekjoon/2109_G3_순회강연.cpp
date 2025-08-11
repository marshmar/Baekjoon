/*
* 핵심 알고리즘: v를 탐색하면서 최소를 빼버린다. min heap에서 top을 계속 빼는 알고리즘
*/
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
using p_t = pair<int, int>;

int n, p, d, ret;
vector<p_t> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p >> d;
		v.push_back({ d, p });
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
	{
		pq.push(v[i].second);
		if (pq.size() > v[i].first)
			pq.pop();
	}

	while (pq.size())
	{
		ret += pq.top();
		pq.pop();
	}

	cout << ret << "\n";
	return 0;
}