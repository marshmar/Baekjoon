/*
* 필요한 알고리즘: 배열 회전 + 회전 연산 수행 순서, 배열의 행의 합의 최솟값 구하기
*/
#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<climits>
#include<cstring>
using namespace std;
using t_t = tuple<int, int, int>;
using p_t = pair<int, int>;

const int ms = 54;
const int dy[]{ 0, 1, 0, -1 };
const int dx[]{ 1, 0, -1, 0 };


int n, m, k, ret = INT_MAX;
int oa[ms][ms], a[ms][ms];
vector<t_t> rs;

void print()
{
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void rotate(int r, int c, int s)
{
	for (int i = 1; i <= s; i++)
	{
		int y = r-i, x = c-i, temp = 0, dir = 0;
		vector<p_t> v;
		v.push_back({ y, x });
		while (true)
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny == r-i && nx == c-i) break;
			if (ny < r - i || ny > r + i || nx < c - i || nx > c + i)
			{
				dir++;
				ny = y + dy[dir];
				nx = x + dx[dir];
			}
			if (ny == r - i && nx == c - i) break;
			y = ny;
			x = nx;
			v.push_back({ ny, nx });
		}

		if (v.size())
		{
			temp = a[v[v.size()-1].first][v[v.size()-1].second];
			for (int j = v.size() - 1; j > 0; j--)
				a[v[j].first][v[j].second] = a[v[j - 1].first][v[j - 1].second];
			a[v[0].first][v[0].second] = temp;
		}
	}
}

int findMax()
{
	int sum = 0, mx = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		for (int j = 0; j < m; j++)
		{
			sum += a[i][j];
		}
		mx = min(mx, sum);
	}

	return mx;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> oa[i][j];
	
	int r, c, s;
	for (int i = 0; i < k; i++)
	{
		cin >> r >> c >> s;
		rs.push_back({ r, c, s });
	}

	sort(rs.begin(), rs.end());
	do {
		memcpy(a, oa, sizeof(a));
		for(auto& e : rs)
		{
			tie(r, c, s) = e;
			rotate(r-1, c-1, s);
		}
		ret = min(ret, findMax());
	} while (next_permutation(rs.begin(), rs.end()));

	cout << ret << "\n";
	return 0;
}