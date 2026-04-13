#include<iostream>
using namespace std;
using ll = long long;

const int ms = 34;
int n;
ll dp[ms][ms];

ll solve(int w, int h)
{
	if (w == 0 && h == 0) return 1;
	if (dp[w][h]) return dp[w][h];
	ll& ret = dp[w][h];
	if (w > 0) ret += solve(w - 1, h + 1);
	if (h > 0) ret += solve(w, h - 1);
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	while (true)
	{
		cin >> n;
		if (!n) break;

		cout << solve(n, 0) << "\n";
	}
	return 0;
}