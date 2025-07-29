/*
* 필요한 핵심 로직: 1. 수빈이와 동생이 같이 갈 때, 만나는 지 체크하는 로직.
*					2. 수빈이가 동생의 지점에 미리 도착했을 때 왔다리 갔다리(홀수와 짝수가 맞아야함. ex) 수빈이가 3초에 도착, 동생이 5초에 도착 -> 가능)
*/
#include<iostream>
#include<queue>
using namespace std;

const int ms = 500'000;
int visited[2][ms + 4];	// 2차원 배열인 이유는 홀수 짝수 따로 저장(수빈이는 홀짝만 판단하면 된다)
int n, k, turn = 1, flag; // turn은 시간 (1초, 2초...)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	if (n == k)
	{
		cout << 0 << "\n";
		return 0;
	}

	queue<int> q;
	visited[0][n] = 1;
	q.push(n);
	while (q.size())
	{
		k += turn;
		if (k > ms) break;
		if (visited[turn % 2][k]) // 수빈이가 지점이 미리 와있고, 홀짝이 맞는다면 break; why? 수빈이는 왔다리 갔다리 할 수 있기 때문에 홀짝만 맞으면 됨
		{
			flag = 1;
			break;
		}

		// 플루드 필? 단계별로 색을 칠하는 알고리즘 
		// bfs를 한 덩어리 묶음으로 진행하고 싶을 때 사용 가능(즉, 턴을 분리)
		int qSize = q.size();
		for (int i = 0; i < qSize; i++)
		{
			int cur = q.front();
			q.pop();
			for (int next : {cur + 1, cur - 1, cur * 2})
			{
				if (next < 0 || next > ms || visited[turn % 2][next]) continue;
				visited[turn % 2][next] = visited[(turn + 1) % 2][cur] + 1;	// 이 부분에서 (turn +1) % 2인 이유가 뭘까 -> 지금이 홀수 번째라면 이전에 짝수번째이기 때문에 이전 값을 +1 해주어야 함
																		    // 만약 여기서 visited[turn % 2][next] = visited[turn % 2][cur] +1 이라면 이전 번째가 아닌, 이전 홀수 번째 이기에 결과가 다름.
				if (next == k)
				{
					flag = 1;
					break;
				}
				q.push(next);
			}
			if (flag) break;
		}
		if (flag) break;
		turn++;
	}
	if (flag) cout << turn << "\n";
	else cout << -1 << "\n";
	return 0;
}