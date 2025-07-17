#include<iostream>
using namespace std;


int n, m, j, l, r, p, ret;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	l = 1;
	cin >> j;

	for (int i = 0; i < j; i++)
	{
		r = l + m - 1;
		cin >> p;

		if (p >= l && p <= r) continue;
		else 
		{
			if (p < l)
			{
				ret += (l - p);
				l = p;
			}
			else
			{
				l += (p - r);
				ret += (p - r);
			}

		}
	}

	cout << ret << "\n";
}