#include<iostream>
#include<string>
#include<climits>
using namespace std;

int h, w;
const int ms = 104;

char m[ms][ms];
int ret[ms][ms];
bool visited[ms][ms];


void dfs(int y, int x)
{
	visited[y][x] = 1;

	int nx = x + 1;
	if (nx >= w || m[y][nx] == 'c' || visited[y][nx]) return;

	ret[y][nx] = ret[y][x] + 1;
	dfs(y, nx);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> h >> w;
	fill(&visited[0][0], &visited[0][0] + ms * ms, 0);
	fill(&ret[0][0], &ret[0][0] + ms * ms, -1);

	cin.ignore();
	for (int i = 0; i < h; i++)
	{
		string s;
		getline(cin, s);
		for (int j = 0; j < s.length(); j++)
		{
			m[i][j] = s[j];
		}

	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (m[i][j] == 'c')
			{
				ret[i][j] = 0;
				dfs(i, j);
			}

		}
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
			cout << ret[i][j] << " ";
		cout << "\n";
	}

	return 0;
}