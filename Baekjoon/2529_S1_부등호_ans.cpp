/*
* 강의 정답 코드
* 숫자 선택은 0~9 * 개수 이므로
* 재귀적으로 인덱스를 늘려가면서, for문으로 0~9의 숫자를 집어넣으면서 체크하면 되는 문제 
* operation과 결과를 string에 넣고 마지막에 string만 벡터에 추가하면 되는 아이디어가 인상적임.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
using ll = long long;

int n, check[10];
char op[20];
vector<string> ret;

bool oper(char op, char x, char y)
{
	if (x < y && op == '<') return true;
	if (x > y && op == '>') return true;
	return false;
}

void solve(int idx, string num)
{
	if (idx == n + 1)
	{
		ret.push_back(num);
		return;
	}

	for (int i = 0; i <= 9; i++)
	{
		if (check[i]) continue;
		if (idx == 0 || oper(op[idx - 1], num[idx - 1], i + '0'))
		{
			check[i] = 1;
			solve(idx + 1, num + to_string(i));
			check[i] = 0;
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> op[i];
	solve(0, "");
	sort(ret.begin(), ret.end());
	cout << ret[ret.size() - 1] << "\n" << ret[0] << "\n";
	return 0;
	
}