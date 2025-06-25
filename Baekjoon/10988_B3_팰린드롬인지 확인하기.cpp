#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string input;
	std::cin >> input;

	stack<char> s;

	for (int i = 0; i < input.length(); i++)
		s.push(input[i]);

	int stackSize = static_cast<int>(s.size());
	for (int i = 0; i < stackSize; i++)
	{
		if (s.top() != input[i]) 
		{
			cout << 0;
			return 0;
		}
		s.pop();
	}

	cout << 1;
	return 0;
}