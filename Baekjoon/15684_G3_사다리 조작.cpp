#include<iostream>
using namespace std;

int n, m, h;

bool map[31][20];
bool visited[31][20];
void print()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n * 2 - 1; j++)
		{
			cout << visited[i][j];
		}
		cout << "\n";
	}
}

int dfs(int y, int x)
{
	cout << "y: " << y << " x: " << x << "\n";
	if (y == h-1) return x;

	if (x - 1 > 0 && map[y][x - 1] && !visited[y][x - 1])
	{
		visited[y][x - 1] = 1;
		return dfs(y, x - 2);
	}
	else if (x + 1 < n * 2 && map[y][x + 1] && !visited[y][x + 1])
	{
		visited[y][x + 1] = 1;
		return dfs(y, x + 2);
	}
	else
		return dfs(y + 1, x);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> h;

	if (m == 0)
		cout << 0 << "\n";
	else
	{
		int y, x;
		for (int i = 0; i < m; i++)
		{
			cin >> y >> x;
			map[y - 1][x] = 1;
		}

		for (int i = 0; i <h; i ++)
		{
			for (int j = 0; j < n * 2 -1; j += 2)
				map[i][j] = 1;
		}

		print();

		bool flag = true;
		cout << n * 2 - 1;
		for (int i = 0; i < n * 2 - 1; i += 2)
		{
			cout << "i: " << i << "\n";
			fill(&visited[0][0], &visited[31][20], 0);
			print();
			if (i != dfs(0, i))
			{
				flag = false;
			}
		}
		if(flag)
		{
			cout << "success!" << "\n";
		}
	}
	return 0;
}