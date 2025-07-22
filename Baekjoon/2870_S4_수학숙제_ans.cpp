#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int n;
vector<string> v;
string s, ret;

void solve()
{
	while (true)
	{
		if (ret.size() && ret.front() == '0') ret.erase(ret.begin());
		else break;
	}
	if (ret.size() == 0) ret = "0";	// 0000 등 0만 존재할 경우
	v.push_back(ret);
	ret = "";
}

bool cmp(string a, string b)
{
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		ret = "";
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] < 65) ret += s[j];
			else if (ret.size()) solve();
		}
		if (ret.size()) solve();
	}

	sort(v.begin(), v.end(), cmp);
	for (auto& e : v) cout << e << "\n";
	return 0;
}