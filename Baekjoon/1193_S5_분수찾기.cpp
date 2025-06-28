#include<iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int X;
	cin >> X;

	int i = 1;
	int count = 0;
	do {
		i += count;
		count++;
	} while (i <= X);

	i -= count;
	count--;

	int deno = 0, numer = 0;

	if (count % 2 == 0)
	{
		deno = count;
		numer = 1;
		for (int n = 1; n < X - i; n++)
		{
			deno--;
			numer++;
		}
	}
	else
	{
		deno = 1;
		numer = count;
		for (int n = 1; n <X - i; n++)
		{
			deno++;
			numer--;
		}
	}

	cout << numer << "/" << deno << '\n';

	return 0;
}