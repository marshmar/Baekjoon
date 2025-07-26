#include<iostream>
#include<string>
using namespace std;


int r, c, ret = 1;
const int ms = 21;
char map[ms][ms];
bool alpha[26];

const int dy[]{ -1, 0, 1, 0 };
const int dx[]{ 0, 1, 0, -1 };

void dfs(int y, int x, int cnt)
{
	ret = max(ret, cnt);
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
		
		int next = (int)(map[ny][nx] - 'A');

		if (alpha[next] == 0)
		{
			alpha[next] = 1;
			dfs(ny, nx, cnt+1);
			alpha[next] = 0;
		}

	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c;

	string s;
	for (int i = 0; i < r; i++)
	{
		cin >> s;
		for (int j = 0; j < s.length(); j++)
			map[i][j] = s[j];
	}

	alpha[map[0][0] - 'A'] = 1;
	dfs(0, 0, 1);
	cout << ret << "\n";
	return 0;
}
