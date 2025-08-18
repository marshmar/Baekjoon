#include<iostream>
#include<climits>
#include<vector>
#include<cmath>
using namespace std;
using p_t = pair<int, int>;

const int ms = 24;
int n, ret = INT_MAX;
int p[ms][ms];

int solve(vector<int>& a, vector<int>& b)
{
	p_t ret;
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < n / 2; j++)
		{
			if (i == j) continue;
			ret.first += p[a[i]][a[j]];
			ret.second += p[b[i]][b[j]];
		}
	}

	return abs(ret.first - ret.second);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> p[i][j];

	for (int i = 0; i < (1 << n); i++)
	{
		if (__popcnt(i) != n / 2) continue;				// __popcnt(): visual studio 전용
		//if (__builtin_popcount(i) != n / 2) continue; // __builtin_popcount() 백준에서 제출할 시에 필요.
		vector<int> start, link;
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j)) start.push_back(j);
			else link.push_back(j);
		}
		ret = min(ret, solve(start, link));
	}
	cout << ret << "\n";
}