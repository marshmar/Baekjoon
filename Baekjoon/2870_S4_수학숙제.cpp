#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int n, index;
vector<string> ret;


bool compare(string a, string b)
{
	if (a.length() < b.length())
		return true;
	else if (a.length() > b.length())
		return false;
	else 
	{
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] < b[i])
				return true;
			else if (a[i] > b[i])
				return false;
			else
				continue;
		}
		return false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;


	for (int i = 0; i < n; i++)
	{
		string s, t;
		cin >> s;

		index = 0;
		while (index < s.length())
		{

			while (index < s.length() && s[index] >= '0' && s[index] <= '9')
			{
				t += s[index];
				index++;
				continue;
			}

			if (t != "")
			{
				int it = 0;
				while (t[it] == '0')
				{
					it++;
				}
				if (it == t.length())
					ret.push_back("0");
				else
					ret.push_back(t.substr(it));
				t = "";
			}

			index++;
		}

		if (t != "")
		{
			int it = 0;
			while (t[it] == '0')
			{
				it++;
			}
			if (it == t.length())
				ret.push_back("0");
			else
				ret.push_back(t.substr(it));
			t = "";
		}

	}

	sort(ret.begin(), ret.end(), compare);
	for (auto& e : ret)
		cout << e << "\n";

	return 0;
}