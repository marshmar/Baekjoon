#include<iostream>
#include<string>

using namespace std;


int main()
{
	int N;
	cin >> N;
	string s;
	
	cin >> s;
	int pos = s.find("*");
	string pre = s.substr(0, pos);
	string suf = s.substr(pos + 1);

	for (int i = 0; i < N; i++)
	{
		cin >> s;
		if (s.size() < pre.size() + suf.size())
		{
			cout << "NE" << endl;
			continue;
		}

		if (pre == s.substr(0, pre.size()) && suf == s.substr(s.size() - suf.size()))
			cout << "DA" << endl;
		else
			cout << "NE" << endl;
	}
}