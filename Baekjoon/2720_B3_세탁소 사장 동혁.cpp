#include<iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;

	int Q, D, N, P;

	for (int i = 0; i < T; i++)
	{
		int m;
		cin >> m;

		Q = (int)(m / 25);
		m %= 25;
		D = (int)(m / 10);
		m %= 10;
		N = (int)(m / 5);
		m %= 5;
		P = (int)(m / 1);
		
		cout << Q << " " << D << " " << N << " " << P << '\n';
	}

	return 0;
}