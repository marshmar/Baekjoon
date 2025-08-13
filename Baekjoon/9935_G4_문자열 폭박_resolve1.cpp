#include<iostream>
#include<string>
using namespace std;

string s, e, ret;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s >> e;

	for (char c : s)
	{
		ret += c;
		if (ret.size() >= e.size() && ret.substr(ret.size() - e.size(), e.size()) == e)
			ret.erase(ret.size() - e.size());
	}

	if (ret.size()) cout << ret << "\n";
	else cout << "FRULA" << "\n";

	return 0;
}