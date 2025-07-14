#include<iostream>

using namespace std;

using ll = long long;
typedef long long ll;

int main()
{
	int n;

	// 입력이 없을 때까지 입력 받기
	while (cin >> n)
	{
		ll cnt = 1, ret = 1;
		while (true)
		{
			if (cnt % n == 0)
			{
				printf("%lld\n", ret);
				break;
			}
			else
			{
				cnt = (cnt * 10) + 1;
				cnt %= n;	// 정수론 (a x b) % n = (a % n x b % n ) %n
				ret++;
			}
		}
	}
	return 0;
}