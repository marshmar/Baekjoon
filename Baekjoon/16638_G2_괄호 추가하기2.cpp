/*
* 재귀적으로 풀어야 한다는 것은 알았고 아이디어도 생각했지만, 어떻게 코드를 짜야할 지 감도 안온 문제, 1시간 30분 고민
* 누적합 + 인덱스
*/
#include<iostream>
#include<string>
#include<vector>
#include<climits>
using namespace std;

int n, ret = INT_MIN;
string s;
vector<int> nums;
vector<char> op;

int oper(char op, int a, int b)
{
	if (op == '+') return a + b;
	if (op == '-') return a - b;
	if (op == '*') return a * b;
}

void solve(int idx, int num)
{
	cout << "idx: " << idx << " " << "num:  " << num << "\n";
	if (idx == nums.size() - 1)
	{
		ret = max(ret, num);
		return;
	}

	if (idx + 2 >= nums.size() - 1)
	{
		if (op[idx] != '*' && op[idx + 1] == '*')
		{
			int temp = oper(op[idx + 1], nums[idx + 1], nums[idx + 2]);
			cout << "temp: " << temp << " " << "num: " << num << "\n";
			ret = max(ret, oper(op[idx], num, temp));
			return;
		}

	}
	solve(idx + 1, oper(op[idx], num, nums[idx + 1]));


	if (idx + 2 <= nums.size() - 1)
	{
		int temp = oper(op[idx + 1], nums[idx + 1], nums[idx + 2]);
		solve(idx + 2, oper(op[idx], num, temp));
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	cin >> s;

	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0) nums.push_back(s[i] - '0');
		else op.push_back(s[i]);
	}

	solve(0, nums[0]);
	cout << ret << "\n";
	return 0;
}