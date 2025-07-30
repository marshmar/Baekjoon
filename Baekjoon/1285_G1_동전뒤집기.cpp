#include<iostream>
#include<bitset>
#include<string>
#include<climits>
using namespace std;

const int s = 20;
int n, ret;

int coins[21];

void rowRev(int r)
{
	for (int i = 0; i < n; i++)
	{
		coins[r] ^= (1 << i);
	}
}

void colRev(int c)
{
	for (int i = 0; i < n; i++)
	{
		coins[i] ^= (1 << (n - c - 1));
	}
}

void print()
{
	for (int i = 0; i < n; i++)
	{
		cout << "r: " << i << " " << bitset<s>(coins[i]) << "\n";
	}
	cout << "\n";
}
int check()
{
	int tcnt = 0;;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (coins[i] & (1 << j)) tcnt++;
		}
	}
	
	return tcnt;
}
void solve(int cnt, int pr, int pc)
{
	print();

	for (int i = 0; i < n; i++)
	{
		rowRev(i);
		if (check() <= cnt && i != pr)
		{
			cnt = check();
			ret = min(cnt, check());
			solve(cnt, i, -1);
		}

		rowRev(i);
	}

	for (int i = 0; i < n; i++)
	{
		colRev(i);
		if (check() <= cnt && i != pc)
		{
			cnt = check();
			ret = min(cnt, check());
			solve(cnt, -1, i);
		}
		colRev(i);
	}


}

int main()
{
	cin >> n;
	cin.ignore();

	string s;
	int tcnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> s;

		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] == 'T')
			{
				coins[i] |= (1 << (n - j - 1));
				tcnt++;
			}
		}
	}

	//print();

	ret = tcnt;
	solve(tcnt, -1, -1);
	
	cout << ret << "\n";
	return 0;
}