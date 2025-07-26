#include<iostream>
#include<string>
#include<vector>
#include<climits>
using namespace std;

int n, ret = INT_MIN;
vector<char> op;
vector<int> nums;

int oper(char op, int n1, int n2) 
{
	if (op == '+') return n1 + n2;
	if (op == '-') return n1 - n2;
	if (op == '*') return n1 * n2;
}

void solve(int idx, int num)
{
	if (idx == nums.size() - 1)
	{
		ret = max(ret, num);
		return;
	}

	solve(idx + 1, oper(op[idx],num, nums[idx+1]));

	if (idx  + 2 <= nums.size() - 1)
	{
		int temp = oper(op[idx + 1], nums[idx+1], nums[idx + 2]);
		solve(idx + 2, oper(op[idx], num, temp));
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	string s;
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