#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int main()
{
	string str[5];
	int maxLen = 0;

	for (int i = 0; i < 5; i++)
	{
		cin >> str[i];
		maxLen = max(maxLen, (int)str[i].length());
	}

	for (int i = 0; i < maxLen; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i >= str[j].length()) continue;
			cout << str[j][i];
		}
	}

	return 0;
}