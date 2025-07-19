#include<iostream>
#include<stack>
#include<string>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	string s;
	while (true)
	{
		cin >> s;
		if (s == "end") break;

		stack<char> v, c;
		
		bool vowel = false, ret = true;
		for (int i = 0; i < s.size(); i++)
		{
			if (v.size())
			{
				if (s[i] == v.top() && (v.top() != 'e' && v.top() != 'o')) 
				{
					ret = false;
					break;
				}
			}

			if (c.size())
			{
				if (s[i] == c.top())
				{
					ret = false;
					break;
				}
			}


			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			{
				if (!vowel) vowel = true;
				v.push(s[i]);
				while(c.size())
					c.pop();
			}
			else
			{
				c.push(s[i]);
				while(v.size())
					v.pop();
			}

			if (v.size() >= 3 || c.size() >= 3)
			{
				ret = false;
				break;
			}

		}

		if (!vowel) ret = false;

		if(ret)
			cout << "<" << s << ">" << " is acceptable.\n";
		else
			cout << "<" << s << ">" << " is not acceptable.\n";
	}
	return 0;
}