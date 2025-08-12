#include<iostream>
#include<string>
using namespace std;

string s, e, ret;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	cin >> e;

	for (char c : s)
	{
		ret += c;
		if (ret.size() >= e.size() && ret.substr(ret.size() - e.size(), e.size()) == e)
			ret.erase(ret.end() - e.size(), ret.end());
	}


	if (ret == "")
		cout << "FRULA" << "\n";
	else
		cout << ret << "\n";

	return 0;
}