#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string input;
	cin >> input;

	for (auto& c : input)
		v.push_back(c - '0');

	sort(v.rbegin(), v.rend());

	for (auto& n : v)
		cout << n;

	return 0;
}