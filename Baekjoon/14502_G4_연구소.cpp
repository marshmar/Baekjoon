#include<iostream>
#include<climits>
#include<tuple>
#include<vector>
#include<cstring>

using namespace std;

int N, M, ret = 0, vcnt, wcnt;
const int dy[]{ -1, 0, 1, 0 };
const int dx[]{ 0, 1, 0, -1 };

const int ms = 9;
int m[ms][ms], om[ms][ms];
bool visited[ms][ms];

using p_t = pair<int, int>;
using t_t = tuple<p_t, p_t, p_t>;
vector<p_t> c, t;
vector<t_t> w;

void wall()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (m[i][j] == 0) c.push_back({ i, j });
}

void combi(int index)
{
	if (t.size() == 3)
	{
		w.push_back({t[0], t[1], t[2]});
		return;
	}

	for (int i = index + 1; i < c.size(); i++)
	{
		t.push_back(c[i]);
		combi(i);
		t.pop_back();
	}
}

void dfs(int y, int x)
{
	if (visited[y][x]) return;
	visited[y][x] = 1;
	m[y][x] = 2;
	vcnt++;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
		if (visited[ny][nx]) continue;
		if (m[ny][nx] == 0)
		{
			dfs(ny, nx);
		}

	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> om[i][j];
			if (om[i][j] == 1) wcnt++;
		}
	}
	memcpy(m, om, sizeof(om));

	wall();
	combi(-1);

	int ovcnt = vcnt;

	for (auto& ele : w)
	{
		p_t pt1, pt2, pt3;
		tie(pt1, pt2, pt3) = ele;
		vector<p_t> temp{ pt1, pt2, pt3};

		memcpy(m, om, sizeof(om));

		for (auto& e : temp)
		{
			m[e.first][e.second] = 1;
			wcnt++;
		}

		fill(&visited[0][0], &visited[0][0] + ms * ms, 0);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (m[i][j] == 2 && !visited[i][j])
					dfs(i, j);
			}
		}

		ret = max(ret, N * M - vcnt - wcnt);

		for (auto& e : temp)
		{
			m[e.first][e.second] = 0;
			wcnt--;
		}
		vcnt = ovcnt;


	}

	cout << ret << "\n";

	return 0;
}