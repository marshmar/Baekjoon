/*
* 백준 1072_S3_게임
* 핵심 알고리즘: 이분 탐색
* 시간복잡도: 이분 탐색 -> O(logn)
* 틀림 여부: O
* 틀린 이유: 승률이 99퍼인 상태에서 100프로로 가는 것은 불가능 하기에 예외처리를 해주어야 함..
*/

#include<iostream>
#include<climits>
using namespace std;
using ll = long long;

const ll maxGame = 1'000'000'000'000;
ll x, y, z;

bool check(ll mid)
{
	ll tz = (y + mid) * 100 / (x + mid);
	//cout << "mid: " << mid << " z: " << z  << " tz: " << tz << "\n";

	return z != tz;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> x >> y;

	z = y * 100 / x;
	
	// 승률이 99프로인 상태에서 100프로로 가는 것은 불가능하다.
	if (z >= 99) cout << "-1\n";
	else
	{
		ll left = 1, right = maxGame, mid;

		while (left <= right)
		{
			mid = (left + right) / 2;
			if (check(mid))
				right = mid - 1;
			else
				left = mid + 1;
		}

		cout << left << "\n";
	}


	return 0;
}