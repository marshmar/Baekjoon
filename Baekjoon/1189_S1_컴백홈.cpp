#include<iostream>
#include<map>
#include<string>
using namespace std;

const int ms = 6;
int r, c, k;
char m[ms][ms];
int visited[ms][ms];

map<int, int> ret;

const int dy[]{ -1, 0, 1, 0 };
const int dx[]{ 0, 1, 0, -1 };

void dfs(int y, int x)
{
	if (y == 0 && x == c - 1) return;
	

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
		if (visited[ny][nx] || m[ny][nx] == 'T') continue;

		int temp = visited[y][x] + 1;
		visited[ny][nx] = temp;

		if (ny == 0 && nx == c - 1)
		{
			if (ret[temp])
				ret[temp]++;
			else
				ret[temp] = 1;
		}

		dfs(ny, nx);
		visited[ny][nx] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c >> k;

	cin.ignore();
	string s;
	for (int i = 0; i < r; i++)
	{
		getline(cin, s);
		for (int j = 0; j < s.length(); j++)
			m[i][j] = s[j];
	}

	visited[r-1][0] = 1;
	dfs(r-1, 0);

	
	cout << ret[k] << "\n";
	return 0;
}