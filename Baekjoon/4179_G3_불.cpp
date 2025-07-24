#include<iostream>
#include<queue>
#include<tuple>
#include<string>
#include<cstring>
#include<vector>

using namespace std;

int r, c, ret, t;

bool dead, clear, blocked;
const int ms = 1004;
char m[ms][ms];
bool visited[ms][ms];
int mins[ms][ms];

const int dy[]{ -1, 0, 1, 0 };
const int dx[]{ 0, 1, 0, -1 };
using p_t = pair<int, int>;
vector<p_t> j;

void bfs(int y, int x)
{
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
		if (visited[ny][nx]) continue;
		if (m[ny][nx] == '#' || m[ny][nx] == 'F') continue;

		visited[ny][nx] = 1;
		if (m[y][x] == 'J')
		{
			blocked = false;
			m[ny][nx] = 'J';
			mins[ny][nx] = mins[y][x] + 1;
		}
		else
			m[ny][nx] = 'F';
	}
}

void print()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << m[i][j] << " ";
		}
		cout << "\n";
	}
}

void printVisited()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
}

void check()
{
	dead = true;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (m[i][j] == 'J')
			{
				dead = false;
				if (i == 0 || i == r - 1 || j == 0 || j == c - 1)
				{
					clear = true;
					ret = mins[i][j];
					return;
				}
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c;
	cin.ignore();


	for (int i = 0; i < r; i++)
	{
		string s;
		getline(cin, s);
		for (int j = 0; j < s.length(); j++)
		{
			m[i][j] = s[j];	
		}
	}

	while (true)
	{
		blocked = true;
		check();

		if (clear)
		{
			cout << ret + 1 << "\n";
			return 0;
		}

		if (dead)
		{
			cout << "IMPOSSIBLE" << "\n";
			return 0;
		}

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (m[i][j] == 'J' && !visited[i][j])
				{
					bfs(i, j);

					//print();
					//printVisited();
					//cout << "\n";
				}
			}
		}

		if (blocked)
		{
			cout << "IMPOSSIBLE" << "\n";
			return 0;
		}
		
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (m[i][j] == 'F' && !visited[i][j])
				{
					bfs(i, j);

					//print();
					//printVisited();
					//cout << "\n";
				}

			}
		}
		//cin >> t;
	}
	
}