#include<iostream>
#include<stack>
#include<string>
using namespace std;

const int ms = 200'004;
int n, ret, cnt, c[ms];
string s;
stack<int> stk;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(')
			stk.push(i);
		else if (stk.size())
		{
			c[i] = c[stk.top()] = 1;
			stk.pop();
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (c[i])
		{
			cnt++;
			ret = max(ret, cnt);
		}
		else
			cnt = 0;
	}

	cout << ret << "\n";
	return 0;
}