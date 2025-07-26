/*
* 핵심 알고리즘은 dfs
* dfs를 통해 알파벳을 방문 처리 하고, dfs실행 후 다시 원복하는 과정이 핵심 알고리즘
* 나는 visited와 alpha 2개의 배열을 사용하였지만, 사실 alpha 배열 하나만 있어도 동작 가능
* 이런 사소한 디테일은 문제를 많이 풀어봐야 쌓을 수 있을듯.
*/
#include<iostream>
#include<string>
using namespace std;


int r, c, ret = 1;
const int ms = 21;
char map[ms][ms];
int visited[ms][ms];
bool alpha[26];

const int dy[]{ -1, 0, 1, 0 };
const int dx[]{ 0, 1, 0, -1 };

void dfs(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= r || nx < 0 || nx >= c || visited[ny][nx]) continue;
		if (alpha[map[ny][nx] - 'A']) continue;

		visited[ny][nx] = visited[y][x] + 1;
		ret = max(ret, visited[ny][nx]);
		alpha[map[ny][nx] - 'A'] = 1;
		dfs(ny, nx);
		alpha[map[ny][nx] - 'A'] = 0;
		visited[ny][nx] = 0;
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

	visited[0][0] = 1;
	alpha[map[0][0] - 'A'] = 1;
	dfs(0, 0);
	cout << ret << "\n";
	return 0;
}
