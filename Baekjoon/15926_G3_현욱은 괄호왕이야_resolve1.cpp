#include<iostream>
#include<stack>
#include<string>
using namespace std;

const int ms = 200'000;
int n, ret, cnt[ms+4];
string s;
stack<int> stk;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(')
			stk.push(i);
		else
		{
			if (stk.size())
			{
				cnt[i] = cnt[stk.top()] = 1;
				stk.pop();
			}
		}
	}

	int tcnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (cnt[i])
		{
			tcnt++;
			ret = max(ret, tcnt);
		}
		else
			tcnt = 0;
	}

	cout << ret << "\n";
	return 0;
}