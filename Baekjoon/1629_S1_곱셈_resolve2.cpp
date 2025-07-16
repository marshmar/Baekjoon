#include<iostream>
using namespace std;

int A, B, C;

using ll = long long;

ll solve(ll a, ll b)
{
	if (b == 1) return a % C;

	ll ret = solve(a, b / 2);
	ret = (ret * ret) % C;
	if (b % 2 == 1) ret = (ret* a) % C;

	return ret;
}
int main()
{
	cin >> A >> B >> C;

	cout << solve(A, B) << "\n";
	return 0;
}