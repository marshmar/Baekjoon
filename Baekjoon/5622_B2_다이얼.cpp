#include<iostream>
#include<string>

using namespace std;

int calTime(char c)
{
	if (c >= 'A' && c <= 'C')
		return 3;
	else if (c >= 'D' && c <= 'F')
		return 4;
	else if (c >= 'G' && c <= 'I')
		return 5;
	else if (c >= 'J' && c <= 'L')
		return 6;
	else if (c >= 'M' && c <= 'O')
		return 7;
	else if (c >= 'P' && c <= 'S')
		return 8;
	else if (c >= 'T' && c <= 'V')
		return 9;
	else if (c >= 'W' && c <= 'Z')
		return 10;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string word;
	cin >> word;

	int result = 0;
	for (char c : word)
	{
		result += calTime(c);
	}

	cout << result;

	return 0;
}