#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int ms = 24;
int ret, n;

struct B
{
	int b[ms][ms];
	void rotateR90()
	{
		int temp[ms][ms];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				temp[i][j] = b[n - j - 1][i];
			}
		}
		memcpy(b, temp, sizeof(b));
	}
	void move()
	{
		int temp[ms][ms];
		for (int i = 0; i < n; i++)
		{
			int c = -1, d = 0;
			for (int j = 0; j < n; j++)
			{
				if (b[i][j] == 0) continue;
				if (d && (b[i][j] == temp[i][c]))
				{
					temp[i][c] *= 2;
					d = 0;
				}
				else
				{
					temp[i][++c] = b[i][j];
					d = 1;
				}
			}
			for (c++; c < n; c++)
				temp[i][c] = 0;
		}
		memcpy(b, temp, sizeof(b));
	}
	void set_max()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				ret = max(ret, b[i][j]);
			}
		}
	}
};

void solve(B b, int cnt)
{
	if (cnt == 5)
	{
		b.set_max();
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		B t = b;
		t.move();
		solve(t, cnt + 1);
		b.rotateR90();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	B t;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> t.b[i][j];
		}
	}
	solve(t, 0);
	cout << ret << "\n";

	return 0;
}