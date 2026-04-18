#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	
	priority_queue<int, vector<int>, greater<int>> time;
	vector<pair<int, int>> v;
	int s, e;

	for (int i = 0; i < n; i++)
	{
		cin >> s >> e;
		v.push_back({ s, e });
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		// 강의실이 비어있으면 = 강의 종료 시간이 현재 원소의 시작 시간보다 앞이면
		// 강의실 할당 => 강의 종료 시간을 현재로 추가
		if (time.size() && time.top() <= v[i].first)
		{
			time.pop();
		}
		time.push(v[i].second);
	}

	cout << time.size()<< endl;
}