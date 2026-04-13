#include<iostream>
#include<cstring>
using namespace std;

const int mt = 1004, mw = 34;
int t, w, plums[mt], dp[mt][2][mw];

int solve(int time, int pos, int cnt)
{
	if (cnt < 0) return -987654321;
	if (time == t) return 0;
	int& ret = dp[time][pos][cnt];
	if (ret != -1) return ret;

	return ret = max(solve(time + 1, pos ^ 1, cnt - 1), solve(time + 1, pos, cnt)) + (pos == plums[time] - 1);
}
int main()
{
	cin >> t >> w;
	for (int i = 0; i < t; i++)
	{
		cin >> plums[i];
	}
	memset(dp, -1, sizeof(dp));

	cout << max(solve(0, 1, w-1), solve(0, 0, w)) << "\n";
	return 0;
}