/*
* 혼자서 풀었던 풀이, dfs를 이용해 0을 전부 탐색하고, 주위에 맞닿은 1들을 0으로 변경
* 그리고 flag가 1이 될 때까지 반복
* 단점은 계속 visited를 0으로 초기화 하기 때문에 탐색했던 지점을 또 탐색하게 되어서 비효율적임
*/
#include<iostream>
#include<queue>
#include<tuple>
#include<string>
#include<climits>
using namespace std;

int n, m, dey, dex, sy, sx, ret;
const int ms = 304;
bool visited[ms][ms];
char map[ms][ms];
bool flag;

const int dy[]{ -1, 0, 1, 0 };
const int dx[]{ 0, 1, 0, -1 };

using p_t = pair<int, int>;

void dfs(int y, int x)
{
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		if (visited[ny][nx]) continue;
		if (map[ny][nx] == '1')
		{
			visited[ny][nx] = 1;
			map[ny][nx] = '0';
		}
		else if (map[ny][nx] == '#')
		{
			flag = 1;
		}
		else if(map[ny][nx] == '0')
			dfs(ny, nx);
	}
}

int main()
{    
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	cin >> sy >> sx >> dey >> dex;

	cin.ignore();
	string s;
	for (int i = 0; i < n; i++)
	{
		getline(cin, s);
		for (int j = 0; j < m; j++)
			map[i][j] = s[j];
	}

	if (sy == dey && sx == dex)
		cout << 0 << "\n";

	else
	{
		flag = false;
		while (true)
		{
			fill(&visited[0][0], &visited[0][0] + ms * ms, 0);
			visited[sy - 1][sx - 1] = true;
			dfs(sy - 1, sx - 1);

			ret++;
			if (flag)
				break;
		}


		cout << ret << "\n";
	}

	return 0;
	
}