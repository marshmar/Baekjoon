#include<iostream>
#include<string>
#include<queue>
#include<tuple>
using namespace std;
using p_t = pair<int, int>;

const int ms = 1504;
int r, c, sy, sx;

int visited[ms][ms];
char map[ms][ms];
queue<p_t> q;

const int dy[]{ -1, 0, 1, 0 };
const int dx[]{ 0, 1, 0, -1 };

void print()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << visited[i][j] << " ";
		} 
		cout << "\n";
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}
void dfs(int y, int x, int day)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
		if (visited[ny][nx] < day) continue;

		if (map[ny][nx] == 'x')
		{
			map[ny][nx] = '.';
			visited[ny][nx] = day + 1;
			return;
		}

		visited[ny][nx] = day;
		dfs(ny, nx, day);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c;
	cin.ignore();

	string s;
	for (int i = 0; i < r; i++)
	{
		getline(cin, s);
		for (int j = 0; j < s.length(); j++)
		{
			map[i][j] = s[j];
		}
	}

	int day = 0;
	while (true)
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (visited[i][j] == day && map[i][j] == '.')
				{
					visited[i][j] = day;
					dfs(i, j, day);
				}
			}
		}	
		cout << "\n";
		print();
		day++;
	}


	return 0;
}