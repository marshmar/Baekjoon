#include<iostream>
using namespace std;
using ll = long long;
const int mn = 34; 
ll n , dp[mn][mn];

ll solve(int time, int wCnt, int hCnt)
{
	if (wCnt == 0 && hCnt == 0) return 1;

	ll& ret = dp[wCnt][hCnt];
	if (ret) return ret;

	if (wCnt > 0) ret += solve(time + 1, wCnt - 1, hCnt + 1);
	if(hCnt > 0) ret += solve(time + 1, wCnt, hCnt - 1);
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

		cout << solve(0, n, 0) << "\n";
	}
	return 0;
}