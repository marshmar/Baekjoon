#include<iostream>
#include<array>
using namespace std;

std::array<std::array<int, 31>, 31> dp{0};

int Combination(int n, int r)
{
	if (n == r || r == 0)
		return 1;
	else {
		if (dp[n][r] != 0)
			return dp[n][r];
		else {
			dp[n][r] = Combination(n - 1, r - 1) + Combination(n - 1, r);
			return dp[n][r];
		}
	}
}

int main()	
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;


	int N, M;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> M;
		cout << Combination(M, N) << '\n';
	}

	return 0;
}