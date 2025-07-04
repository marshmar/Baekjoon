#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> alphaCnt(26, 0);

int main()
{
	string s;
	cin >> s;

	for (auto& c : s)
	{
		alphaCnt[c - 'a']++;
	}

	for (auto& e : alphaCnt)
		cout << e << " ";

	return 0;
}
