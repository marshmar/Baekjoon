#include<iostream>
#include<string>
#include<cmath>
#include<bitset>
#include<cstring>
using namespace std;

const int ms = 1004;
int t, k, n, d, ret;
int g[ms];
bool visited[ms];

void print()
{
	for (int i = 0; i < t; i++)
		cout << bitset<8>(g[i]) << "\n";
}

void rotate(int n, int d)
{
	if (visited[n]) return;
	visited[n] = 1;

	if (n > 0)
	{
		int prev = ((g[n - 1] & (1 << 5))) >> 4;
		int cur = ((g[n] & (1 << 1)));
		if (prev ^ cur) rotate(n - 1, d * -1);
	}
	if (n < t-1)
	{
		int prev = ((g[n + 1] & (1 << 1)));
		int cur = ((g[n] & (1 << 5))) >> 4;
		if (prev ^ cur) rotate(n + 1, d * -1);
	}

	int temp, mask = 0b11111111;
	if (d == -1)
	{
		temp = (g[n] & (1 << 7)) ? 1 : 0;
		g[n] = ((g[n] << 1) & mask) | temp;
	}
	else
	{
		temp = (g[n] & 1) ? (1 << 7) : 0;
		g[n] = ((g[n] >> 1) & mask) | temp;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;

	string s;
	for (int i = 0; i < t; i++)
	{
		cin >> s;
		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] == '1')
				g[i] += (1 << (7 - j));
		}
	}
	
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		memset(visited, 0, sizeof(visited));
		cin >> n >> d;
		rotate(n-1, d);
		//print();
	}

	for (int i = 0; i < t; i++)
	{
		if (g[i] & (1 << 7))
			ret++;
	}

	cout << ret << "\n";
	return 0;
}