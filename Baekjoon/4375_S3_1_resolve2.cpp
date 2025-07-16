#include<iostream>
using namespace std;

int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (cin >> n)
	{
		int t = 1, ret = 1;
		while (true)
		{
			if (t % n == 0)
			{
				cout << ret << "\n";
				break;
			}
			else
			{
				t = t * 10 + 1;
				t %= n;

				ret++;
			}
		}
	}
}