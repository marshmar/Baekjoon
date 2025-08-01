#include<iostream>
#include<bitset>
#include<queue>

using namespace std;

int n;
int p[11], a[11];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
	}

	int acnt;
	for (int i = 0; i < n; i++)
	{
		cin >> acnt;
		int na;
		for (int j = 0; j < acnt; j++)
		{
			cin >> na;
			a[i] |= (1 << (na-1));
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << bitset<11>(a[i]) << "\n";
		cout << "\n";
	}


	return 0;
}