#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	getline(cin, s);

	for (auto& c : s)
	{
		if (c >= 'a' && c <= 'z')
			cout << (char)((c - 'a' + 13) % 26 + 'a');
		else if (c >= 'A' && c <= 'Z')
			cout << (char)((c - 'A' + 13) % 26 + 'A');
		else
			cout << c;

	}

	return 0;
}