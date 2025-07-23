#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool check(string& s)
{
	stack<char> stk;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(' || s[i] == '[')
			stk.push(s[i]);
		else if(s[i] == ')' || s[i] == ']')
		{
			if (stk.empty()) return false;
			else
			{
				if (s[i] == ')' && stk.top() == '(')
					stk.pop();
				else if (s[i] == ']' && stk.top() == '[')
					stk.pop();
				else
					return false;

			}
		}
	}

	return stk.empty();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s;
	while (true)
	{
		getline(cin, s);
		if (s == ".") break;

		if (check(s)) cout << "yes" << "\n";
		else cout << "no" << "\n";
	}
}