#include<iostream>
#include<vector>

using namespace std;

const int t = 104;

vector<int> cnt(t, 0);

int A = 0, B = 0, C = 0, ret = 0;
int main()
{
	ios_base::sync_with_stdio(false);	
	cin >> A >> B >> C;

	// 트럭 수 설정
	for (int i = 0; i < 3; i++)
	{
		int start = 0, end = 0;
		cin >> start >> end;

		for (int j = start; j < end; j++)
			cnt[j]++;
	}

	// 누적합
	for (int i = 1; i <= 100; i++)
	{
		if (cnt[i] == 1)
			ret += A;
		else if (cnt[i] == 2)
			ret += B * 2;
		else if (cnt[i] == 3)
			ret += C * 3;
	}

	cout << ret << '\n';
	return 0;
}