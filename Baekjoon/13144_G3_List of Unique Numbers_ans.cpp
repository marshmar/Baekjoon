#include<iostream>
#include<map>
using namespace std;
using ll = long long;

const int ms = 100'000;
ll n, a[ms + 4], cnt[ms + 4], l, r, ret;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	
	while (r < n)
	{
		if (!cnt[a[r]])
		{
			cnt[a[r]]++;
			r++;
		}
		else
		{
			ret += (r - l);
			cnt[a[l]]--;
			l++;
		}
	}
	
	// 등차수열의 합
	ret += (ll)(r - l) * (r - l + 1) / 2;
	cout << ret << "\n";
	return 0;
}