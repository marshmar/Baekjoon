#include<iostream>
#include<set>
#include<climits>

using namespace std;

int N, maxh, minh, ret;
const int mSize = 104;
int m[mSize][mSize];
 
set<int> s;

const int dy[]{ -1, 0, 1, 0 };
const int dx[]{ 0, 1, 0, -1 };

bool visited[mSize][mSize];

void dfs(int y, int x, const int h)
{
	if (visited[y][x]) return;
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
		if (m[y][x] <= h) continue;

		dfs(ny, nx, h);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> m[i][j];
			if (s.find(m[i][j]) == s.end())
				s.insert(m[i][j]);
		}
	}


	if (s.size() == 1)
		cout << 1 << "\n";
	else
	{
		ret = INT_MIN;
		for (auto& e : s)
		{
			int tRet = 0;
			fill(&visited[0][0], &visited[N - 1][N], 0);

			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (visited[i][j] || m[i][j] <= e) continue;
					dfs(i, j, e);
					tRet++;
				}
			}

			if (tRet > ret)
				ret = tRet;

		}
		cout << ret << "\n";
	}

	return 0;
}