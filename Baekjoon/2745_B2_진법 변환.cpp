#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string input;
	int B;
	
	cin >> input >> B;

	int ret = 0;
	for (int i = (int)input.length() - 1; i >= 0; i--)
	{
		if(input[i] >= 'A')
			ret += (int)pow(B, input.length() - i -1) * (input[i] - 'A' + 10);
		else
			ret += (int)pow(B, input.length() - i - 1) * (input[i] - '0');
	}

	cout << ret << '\n';
	return 0;
}