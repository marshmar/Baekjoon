#include<iostream>
#include<stack>
#include<string>
using namespace std;

int T;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		bool ret = true;
		stack<char> stk;
		string s;
		cin >> s;

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(')
				stk.push(s[i]);
			else
			{
				if (stk.size())
					stk.pop();
				else
				{
					ret = false;
					break;
				}
			}
		}

		if (stk.size() || ret == false)
			cout << "NO" << "\n";
		else
			cout << "YES" << "\n";
	}
	return 0;
}