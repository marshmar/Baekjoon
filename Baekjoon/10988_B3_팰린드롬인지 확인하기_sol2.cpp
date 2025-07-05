#include<iostream>
#include<string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string input, r;
	cin >> input;
	
	for (unsigned int i = 0; i < input.size(); i++)
	{
		if (*(input.begin() + i) != *(input.rbegin() + i))
		{
			cout << 0 << endl;
			exit(0);
		}
	}	
	cout << 1 << endl;
	return 0;
}