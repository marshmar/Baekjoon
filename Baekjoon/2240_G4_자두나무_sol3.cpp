#include<iostream>
using namespace std;
const int mt = 1004, mw = 34;

int t, w, p[mt], dp[mt][2][mw];

int solve(int time, int pos, int cnt)
{
	if (cnt < 0) return -1e9;
	if (time == t) return 0;
	
	int& ret = dp[time][pos][cnt];
	if (ret) return ret;

	ret = max(solve(time + 1, pos ^ 1, cnt - 1), solve(time + 1, pos, cnt)) + (pos == p[time] - 1);
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t >> w;
	for (int i = 0; i < t; i++)
		cin >> p[i];

	cout << max(solve(0, 0, w), solve(0, 1, w - 1)) << "\n";
	return 0;
}