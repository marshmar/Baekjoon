/*
* 백준 16434_G4_드래곤 앤 던전
* 핵심 알고리즘: 이분 탐색
* 시간복잡도: O(nlogn) -? 이분탐색(nlogn) * 이분탐색 마다 배열 탐색(n)
* 틀림 여부: 틀림
* 틀린 이유: 몬스터의 공격 횟수를 세는 과정에서 나누어 떨어질 때와 떨어지지 않을 때를 구분하여 계산하였어야 함.
*			몬스터의 공격 횟수 = 용사의 공격 횟수 - 1
*			maxHp 최대 범위 오버 플로우 주의
*/
#include<iostream>
#include<tuple>
#include<vector>
#include<climits>
using namespace std;
using t_t = tuple<int, int, int>;
using ll = long long;
ll maxHp = LLONG_MAX-1, curHp, atk, n, ret;

const int ms = 123'460;
vector<t_t> rooms(ms);

bool search(ll mid)
{
	ll chp = mid, catk = atk;
	ll rt, ratk, rhp;
	for (int i = 0; i < n; i++)
	{
		tie(rt, ratk, rhp) = rooms[i];

		if (rt == 1)
		{
			ll hitCnt;
			if (rhp % catk == 0)
				hitCnt = rhp / catk - 1;
			else
				hitCnt = rhp / catk;

			chp -= hitCnt * ratk;
			if (chp <= 0) return false;
		}
		else
		{
			chp = min(chp + rhp, mid);
			catk += ratk;
			//cout << "mid: " << mid << " chp: " << chp << "\n";
		}

	}

	return true;
}

void binarySearch()
{
	ll left = 1, right = maxHp, mid = 0;

	while (left <= right)
	{
		//cout << "left: " << left << " right: "<< right << "\n";
		mid = (left + right) / 2;
		if (search(mid))
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	ret = left;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> atk;

	ll roomType, atkVal, hpVal;
	ll tAtk = atk;
	for (int i = 0; i < n; i++)
	{
		cin >> roomType >> atkVal >> hpVal;
		rooms[i] = { roomType, atkVal, hpVal };
	}

	binarySearch();
	cout << ret << "\n";

	return 0;
}