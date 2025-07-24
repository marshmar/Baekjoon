#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;

int n, m, ret;

const int ms = 51;
char map[ms][ms];
int visited[ms][ms];

using p_t = pair<int, int>;
vector<vector<p_t>> lcc, c;

const int dy[]{ -1, 0, 1, 0 };
const int dx[]{ 0, 1, 0, -1 };

void bfs(int y, int x, bool makeCc, p_t target)
{
	visited[y][x] = 1;
	queue<p_t> q;
	q.push({ y, x });

	vector<p_t> t;
	if (makeCc)
		t.push_back({ y, x });

	while (q.size())
	{
		if (q.front() == target) break;

		int ty, tx;
		tie(ty, tx) = q.front();
		q.pop();


		for (int i = 0; i < 4; i++)
		{
			int ny = ty + dy[i];
			int nx = tx + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (visited[ny][nx]) continue;
			if (map[ny][nx] == 'W') continue;
			
			visited[ny][nx] = visited[ty][tx] + 1;

			if (makeCc)
				t.push_back({ ny, nx });
			q.push({ ny, nx });

		}
	}
	if(makeCc)
		lcc.push_back(t);
}

void combi(int idx, vector<p_t>& target, vector<p_t>& temp)
{
	if (temp.size() == 2)
	{
		c.push_back(temp);
		return;
	}

	for (int i = idx + 1; i < target.size(); i++)
	{
		temp.push_back(target[i]);
		combi(i, target, temp);
		temp.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++)
		{
			map[i][j] = s[j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 'L' && !visited[i][j])
				bfs(i, j, true, {-1, -1});
		}
	}


	for (auto& cc : lcc)
	{
		vector<p_t> temp;
		combi(-1, cc, temp);
	}

	ret = INT_MIN;
	for (auto& cc : c)
	{
		fill(&visited[0][0], &visited[0][0] + ms * ms, 0);
		int sy, sx;
		tie(sy, sx) = cc[0];

		bfs(sy, sx, false, cc[1]);
		ret = max(ret, visited[cc[1].first][cc[1].second]-1);
	}
	cout << ret << "\n";
	return 0;
}