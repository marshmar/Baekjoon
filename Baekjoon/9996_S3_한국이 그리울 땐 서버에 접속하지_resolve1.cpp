#include<iostream>
#include<string>

using namespace std;

string s, p, ret, pre, suf;
int N, cnt;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cin >> p;
	
	cnt = p.find("*");
	pre = p.substr(0, cnt);
	suf = p.substr(cnt + 1);
	
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

	return 0;
}