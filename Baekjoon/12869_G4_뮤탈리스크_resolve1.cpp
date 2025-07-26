#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

const int ms = 64;
int n, ret = INT_MAX;
int scv[3], visited[ms][ms][ms];

vector<int> atk[]
{
	{9, 3, 1},
	{9, 1, 3},
	{3, 1, 9},
	{3, 9, 1},
	{1, 3, 9},
	{1, 9, 3}
};

struct A
{
	int a; int b; int c;
};

void solve(int s1, int s2, int s3)
{
	queue<A> q;
	q.push({ s1, s2, s3 });
	visited[s1][s2][s3] = 1;

	while (q.size())
	{
		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;
		q.pop();
		if (visited[0][0][0]) break;
		for (int i = 0; i < 6; i++)
		{
			int ta = max(0, a - atk[i][0]);
			int tb = max(0, b - atk[i][1]);
			int tc = max(0, c - atk[i][2]);

			if (visited[ta][tb][tc]) continue;
			visited[ta][tb][tc] = visited[a][b][c] + 1;
			q.push({ ta, tb, tc });
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> scv[i];
	}

	solve(scv[0], scv[1], scv[2]);
	cout << visited[0][0][0] -1 << "\n";

}
