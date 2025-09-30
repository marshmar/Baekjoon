#include<iostream>
using namespace std;
using ll = long long;

const ll maxGame = 1'000'000'000;
ll x, y, z;

bool check(ll mid)
{
	ll tz = (y + mid) * 100 / (x + mid);

	return z != tz;
}

int main()
{
	cin >> x >> y;

	z = y * 100 / x;

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