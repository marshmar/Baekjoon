#include<iostream>
using namespace std;

int x, sum, sub, idx, ret;

int solve(int s1, int s2)
{
	if (s1 + s2 == x)
	{
		return 1;
	}


	if (s1 + s2 > x)
	{
		idx = (s1 & -s1) >> 1;
		s1 = s1 >> 1;

		if (s1 + s2 >= x)
			return solve(s1, s2);
		else
			return 1 +solve(s1, s2 + idx);
	}
}
int main()
{
	cin >> x;
	cout << solve(64, 0) << "\n";
	return 0;
}