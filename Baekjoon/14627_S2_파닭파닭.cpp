/*
* 14627_S2_파닭파닭
* 핵심 알고리즘: 이분 탐색
* 시간복잡도: O(nlongn)" 이분탐색->O(logn) * 조건 체크->O(n)
* 틀림 여부: O
* 틀린 이유: 예외 처리 1. 한 파의 길이가 매우 커서 조건을 충족하고 나머지 파를 모두 라면에 사용하는 경우
*					 2. 파를 나누다가 이미 조건을 충족해서 나머지 파를 모두 라면에 사용하는 경우
*/
#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

const int maxS = 1'000'000;
vector<ll> length(maxS);
int s, c;
ll maxL = 1'000'000'000, ret;

pair<ll, ll> check(ll mid)
{
	ll cnt = 0, sum = 0;
	for (int i = 0; i < s; i++)
	{
		if (cnt >= c)
		{
			sum += length[i];
		}
		else
		{
			cnt += length[i] / mid;
			if (cnt >= c)
				sum +=(mid * (cnt - c));
			sum += length[i] % mid;
		}

	}

	//cout << "mid: " << mid << " cnt: " << cnt << " sum: " << sum << "\n";

	return { cnt, sum};
}

void binarySearch()
{
	ll left = 1, right = maxL, mid;
	while (right >= left)
	{
		mid = (left + right) / 2;
		pair<ll, ll> p= check(mid);
		if (p.first < c)
		{
			right = mid - 1;
		}
		else if(p.first >= c)
		{
			left = mid + 1;
			ret = p.second;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s >> c;
	for (int i = 0; i < s; i++)
	{
		cin >> length[i];
	}

	binarySearch();
	cout << ret << "\n";
	return 0;
}