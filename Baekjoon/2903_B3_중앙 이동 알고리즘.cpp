#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	int ret = 2;
	for (int i = 0; i < N; i++)
	{
		ret = (ret * 2 - 1);
	}

	cout << ret * ret;
	return 0;
}