#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int k, check[10];
char op[20];
vector<string> ret;

bool oper(char op, char a, char b)
{
	if (op == '<' && a < b) return true;
	if (op == '>' && a > b) return true;
	return false;
}

void solve(int idx, string num)
{
	if (idx == k + 1)
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
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> k;
	for (int i = 0; i < k; i++)
		cin >> op[i];

	solve(0, "");
	sort(ret.begin(), ret.end());
	cout << ret[ret.size() - 1] << "\n" << ret[0] << "\n";
	return 0;
}