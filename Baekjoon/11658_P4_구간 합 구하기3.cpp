#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

const int ms = 1024;
int n, m, table[ms + 4][ms + 4];
vector<int> tree[ms + 4];

void update(int xindex, int yindex, int value)
{
	while (xindex < tree[yindex].size())
	{
		tree[yindex][xindex] += value;
		xindex += xindex & -xindex;
	}
}

ll sum(int xindex, int yindex)
{
	ll tSum = 0;
	while (xindex > 0)
	{
		tSum += tree[yindex][xindex];
		xindex -= xindex & -xindex;
	}

	return tSum;
}

ll rangeQuery(int lx, int ly,  int rx, int ry)
{
	return sum(rx, ry) - sum(lx-1, ly);
}

ll solve(int x1, int y1, int x2, int y2)
{
	ll ret = 0;
	
	for (int i = 0; i <= y2 - y1; i++)
	{
		ret += rangeQuery(x1, y1 + i, x2, y1 + i);
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		tree[i+1].resize(n + 1);
		for (int j = 0; j < n; j++)
		{
			cin >> table[i][j];
			update(j+1, i+1, table[i][j]);
		}
	}

	int w, x1, y1, x2, y2, c;
	for (int i = 0; i < m; i++)
	{
		cin >> w >> y1 >> x1;
		if (w == 0)
		{
			cin >> c;
			update(x1, y1, c - table[y1-1][x1-1]);
			table[y1 - 1][x1 - 1] = c;
		}
		else
		{
			cin >> y2 >> x2;
			cout << solve(x1, y1, x2, y2) << "\n";
		}
	}
	return 0;
}