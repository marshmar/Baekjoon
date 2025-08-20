#include<iostream>
using namespace std;

const int ms = 24;
int n, ret;
int b[ms][ms], tb[ms][ms];

void solve(int b[ms][ms], int cnt)
{
	if (cnt == 5)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				ret = max(ret, b[i][j]);
		return;
	}

	int j = n-1, temp;
	// 위
	for (int i = 0; i < n; i++)
	{
		while (j> 0 && b[j][i] != 0) j--;
		temp = b[j--][i];
		while (j > 0 && b[j][i] != 0) j--;
	}
	solve(tb, cnt + 1);
	memcpy(tb, b, sizeof(b));

	// 오른쪽

	solve(tb, cnt + 1);
	memcpy(tb, b, sizeof(b));

	// 아래

	solve(tb, cnt + 1);
	memcpy(tb, b, sizeof(b));

	// 왼쪽

	solve(tb, cnt + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> b[i][j];

	solve(b, 0);
	cout << ret << "\n";
	return 0;
}