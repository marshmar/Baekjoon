/*
* 시간내에 못푼 문제
* 핵심 알고리즘은 크게 2가지: 배열을 대칭으로 저장, 길을 체크하는 로직
* 길을 체크하는 로직은 cnt변수를 활용하여 높이가 같은것 끼리 cnt를 늘려가며 하면 됨
* (cnt가 l보다 길어지거나 내리막길의 경우 음수부터 시작하여 0보다 커지는 경우 경사로가 주어진 길이보다 길어지는 것임)
*/
#include<iostream>
using namespace std;

const int ms = 104;
int n, l, ret;
int a[ms][ms], b[ms][ms];

void solve(int m[ms][ms])
{
	for (int i = 0; i < n; i++)
	{
		int cnt = 1;
		int j;
		for (j = 0; j < n - 1; j++)
		{
			if (m[i][j] == m[i][j + 1]) cnt++;
			else if (m[i][j] + 1 == m[i][j + 1] && cnt >= l) cnt = 1;
			else if (m[i][j] - 1 == m[i][j + 1] && cnt >= 0) cnt = -l + 1;
			else break;
		}
		if (j == n - 1 && cnt >= 0) ret++;
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			b[j][i] = a[i][j]; 	// 대칭을 시킨다음에 똑같은 로직
		}
	}


	solve(a); solve(b);
	cout << ret << "\n";

	return 0;
}