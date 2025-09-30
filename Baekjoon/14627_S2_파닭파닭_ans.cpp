#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

const int maxS = 1'000'000;
vector<ll> length(maxS);
int s, c;
ll maxL = 1'000'000'000, ret, sum;

bool check(ll mid)
{
	ll cnt = 0;
	for (int i = 0; i < s; i++)
		cnt += length[i] / mid;

	return cnt >= c;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s >> c;
	for (int i = 0; i < s; i++)
	{
		cin >> length[i];
		sum += length[i];
	}

	ll left = 1, right = maxL, mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (check(mid))
		{
			left = mid + 1;
			ret = mid;
		}
		else
			right = mid - 1;
	}
	cout << sum - ret * c << "\n";
	return 0;
}