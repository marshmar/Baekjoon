/*
* 1202_G2_보석도둑
* 핵심 알고리즘: 
* 1. 보석과 가방을 무게를 기준으로 오름차순으로 정렬
* 2. 가방을 기준으로 탐색하면서 각 가방에 넣을 수 있는 모든 보석들을 최대 힙에 넣음(보석의 가치만 넣음)
* 3. 우선순위 큐에 원소가 존재한다면 각 가방에 넣을 수 있다는 것이 보장되기에 최대 값만 추출하여 ret에 더함
* 4. ret 출력
* 
* 앞에서 이미 넣을 수 있는 보석들을 탐색해두었기에, 앞부분을 또 탐색할 필요가 없다는 것이 큰 장점.
*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using p_t = pair<int, int>;
using ll = long long;

int n, k;
priority_queue<int> pq;
vector<p_t> je;
vector<int> b;
ll ret;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	int m, v;
	for (int i = 0; i < n; i++)
	{
		cin >> m >> v;
		je.push_back({ m, v });
	}

	for (int i = 0; i < k; i++)
	{
		cin >> m;
		b.push_back(m);
	}
	sort(je.begin(), je.end());
	sort(b.begin(), b.end());

	int j = 0;
	for (int i = 0; i < k; i++)
	{
		while (j < n && je[j].first <= b[i])	// 각 가방에서 넣을 수 있는 보석들을 전부 우선순위 큐(최대 힙)에 넣음.
		{
			pq.push(je[j++].second);
		}
			
		if (pq.size())  // 만약 우선순위 큐에 내용물이 있으면 최대값을 결과에 더함. 
		{
			ret += pq.top();
			pq.pop();
		}
	}

	cout << ret << "\n";
	return 0;
}