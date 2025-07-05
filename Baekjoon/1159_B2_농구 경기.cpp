#include<iostream>
#include<map>
#include<string>

using namespace std;

int N = 0;
map<char, int> ret;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		if (ret.find(s[0]) != ret.end())
			ret[s[0]] += 1;
		else
			ret.insert({s[0], 1});
	}

	bool flag = false;
	for (auto& e : ret)
	{
		if (e.second >= 5)
		{
			cout << e.first;
			flag = true;
		}
	}

	if (!flag)
		cout << "PREDAJA" << endl;

	return 0;
}