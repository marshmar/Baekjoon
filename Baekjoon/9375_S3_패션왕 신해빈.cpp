#include<iostream>
#include<string>
#include<map>


using namespace std;

int t, n;
using ll = long long;
string s1, s2;
int main()
{
	cin >> t;
	while (t--)
	{
		map<string, int> m;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> s1 >> s2;
			m[s2]++;
		}
		ll ret = 1;
		for (auto e : m)
			ret *= ((ll)e.second + 1);
		ret -= 1;
		cout << ret << '\n';
	}
}