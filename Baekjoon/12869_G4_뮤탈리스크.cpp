/*
	완전탐색으로 next permutation을 통해 풀려고 시도하였으나, 최대 케이스에서 시간 초과 발생
	핵심 알고리즘은 bfs
	목표 : 0, 0, 0인 정점 탐색
	cs를 돌면서 레벨 별로 탐색 -> 0, 0, 0이 되면 최단 거리
	y,x 2개의 변수로 bfs하는 것처럼 a, b, c로 bfs탐색
	dp로도 풀 수가 있음
*/
#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

int n;
int scv[3], visited[64][64][64];
int cs[6][3] = {
	{9, 3, 1},
	{9, 1, 3},
	{3, 1, 9},
	{3, 9, 1},
	{1, 3, 9},
	{1, 9, 3}
};

struct A {
	int a, b, c;
};

queue<A> q;

int solve(int a, int b, int c)
{
	visited[a][b][c] = 1;
	q.push({ a,b,c });
	while (q.size())
	{
		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;
		q.pop();
		if (visited[0][0][0]) break;
		for (int i = 0; i < 6; i++)
		{
			int na = max(0, a - cs[i][0]);
			int nb = max(0, b - cs[i][1]);
			int nc = max(0, c - cs[i][2]);
			if (visited[na][nb][nc]) continue;
			visited[na][nb][nc] = visited[a][b][c] + 1;
			q.push({ na, nb, nc });
		}
	}
	return visited[0][0][0] - 1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> scv[i];
	cout << solve(scv[0], scv[1], scv[2]) << "\n";
	return 0;
}
