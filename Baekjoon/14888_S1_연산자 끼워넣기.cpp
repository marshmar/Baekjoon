#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
const int ms = 12;

int n, mx = INT_MIN, mi = INT_MAX, cnt;
int a[ms];
vector<char> op;

int solve(int idx, int tret)
{
	if (idx == n-1)
		return tret;

	switch (op[idx])
	{
	case '+':
		return solve(idx + 1, tret + a[idx + 1]);
		break;
	case '-':
		return solve(idx + 1, tret - a[idx + 1]);
		break;
	case 'x':
		return solve(idx + 1, tret * a[idx + 1]);
		break;
	case '/':
		return solve(idx + 1, tret / a[idx + 1]);
		break;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	cin >> cnt;
	for (int i = 0; i < cnt; i++)
		op.push_back('+');

	cin >> cnt;
	for (int i = 0; i < cnt; i++)
		op.push_back('-');

	cin >> cnt;
	for (int i = 0; i < cnt; i++)
		op.push_back('x');

	cin >> cnt;
	for (int i = 0; i < cnt; i++)
		op.push_back('/');


	sort(op.begin(), op.end());
	int ret;
	do
	{
		ret = solve(0, a[0]);
		mx = max(mx, ret);
		mi = min(mi, ret);
	} while (next_permutation(op.begin(), op.end()));

	cout << mx << "\n";
	cout << mi << "\n";
	return 0;
}