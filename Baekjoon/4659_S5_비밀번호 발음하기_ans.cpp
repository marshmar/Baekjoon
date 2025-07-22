#include<iostream>
#include<string>

using namespace std;

string s;
int lcnt, vcnt;

bool isVowel(int index)
{
	return (index == 'a' || index == 'e' || index == 'i' || index == 'o' || index == 'u');
}

int main()
{
	while (true)
	{
		cin >> s;
		if (s == "end") break;
		lcnt =0, vcnt = 0;
		bool flag = 0;
		bool is_include_v = 0;
		int prev = -1;
		for (int i = 0; i < s.size(); i++)
		{
			int index = s[i];
			if (isVowel(index))
			{
				lcnt++;
				vcnt = 0;
				is_include_v = 1;
			}
			else
			{
				vcnt++;
				lcnt = 0;
			}

			if (vcnt == 3 || lcnt == 3) 
				flag = 1;

			if (i >= 1 && (prev == index) && (index != 'e' && index != 'o'))
				flag = 1;

			prev = index;
		}

		if (is_include_v == 0) 
			flag = 1;

		if (flag) cout << "<" << s << ">" << " is not acceptable.\n";
		else cout << "<" << s << ">" << " is acceptable.\n";
	}
	return 0;
}