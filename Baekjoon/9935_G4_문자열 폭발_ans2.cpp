#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

string s, e, ret;
stack<char> stk;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s >> e;
	for (char c : s)
	{
		stk.push(c);
		if (stk.size() >= e.size() && stk.top() == e[e.size() - 1])
		{
			string t = "";
			for (char tc : e)
			{
				t += stk.top();
				stk.pop();
			}
			reverse(t.begin(), t.end());

			if (e != t)
			{
				for (char tc : t)
				{
					stk.push(tc);
				}
			}
		}
	}

	if (stk.size())
	{
		while (stk.size())
		{
			ret += stk.top();
			stk.pop();
		}
		reverse(ret.begin(), ret.end());
		cout << ret << "\n";
	}
	else
	{
		cout << "FRULA" << "\n";
	}
	return 0;
}