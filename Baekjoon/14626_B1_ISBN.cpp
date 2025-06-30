#include<iostream>

using namespace std;

int main()
{
	string input;
	std::cin >> input;

	int index = 0, ret = 0;
	for (int i = 0; i < input.length()-1; i++)
	{
		if (input[i] == '*')
		{
			index = i;
			continue;
		}

		if (i % 2 == 0)
			ret += input[i] - '0';
		else
			ret += 3 * (input[i] - '0');
		
		cout << ret << endl;
	}

	if (index % 2 == 0)
		cout << 10 - (input[12] - '0' + ((ret % 10)));
	else
		cout << (10 -  (input[12] - '0' + ((ret % 10)))) / 3;


	return 0;
}