#include<iostream>
#include<string>

using namespace std;

int n;

int main()
{

	while(cin >> n)
	{ 
		long long ret = 1, s = 1;
		while (true)
		{
			if (s % n == 0)
			{
				cout << ret << '\n';
				break;
			}
			else 
			{
				s = s * 10 + 1;
				s %= n;
				ret++;
			}
		}
	}
	return 0;
}