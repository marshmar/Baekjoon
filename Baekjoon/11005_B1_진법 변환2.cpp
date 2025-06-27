#include<iostream>
#include<string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string ret;
	int N, B;

	cin >> N >> B;

	while (N >= 1)
	{
		int temp = N % B;
		char c;
		if (temp >= 10)
			c = temp + 'A' - 10;
		else
			c = temp + '0';
		ret.insert(ret.begin(), c);

		N /= B;
	}

	cout << ret;
	return 0;
}