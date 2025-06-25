#include<iostream>

using namespace std;

int pieces[6] = { 1, 1, 2, 2, 2, 8 };
int input[6] = { 0, 0, 0, 0, 0, 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 6; i++)
	{
		cin >> input[i];
	}

	for (int i = 0; i < 6; i++)
	{
		cout << pieces[i] - input[i] << " ";
	}

	return 0;
}