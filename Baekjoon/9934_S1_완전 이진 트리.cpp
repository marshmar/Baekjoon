#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

int k, root;
vector<int> nums(1024);
vector<int> adj[1024];
bool visited[1024];

void print()
{
	for (int i = 0; i < 10; i++)
		cout << visited[i] << " ";
	cout << "\n";
}

void bfs(int s, int level)
{
	queue<int> q;
	q.push(s);
	int cnt = 1, d = 2;
	visited[nums[s]] = 1;
	while (q.size())
	{
		int idx = q.front();
		q.pop();
		cout << nums[idx] << " ";

		if (visited[nums[idx - level]]) continue;
		if (visited[nums[idx + level]]) continue;

		visited[nums[idx - level]] = 1;
		visited[nums[idx + level]] = 1;
		q.push(idx - level);
		q.push(idx + level);

		cnt++;
		if (cnt % d == 0)
		{
			cout << "\n";
			d *= 2;
			level /= 2;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> k;

	int num  =pow(2, k) - 1;
	for (int i = 0; i < num; i++)
	{
		cin >> nums[i];
	}

	if (k == 1)
		cout << nums[0];
	else
	{
		root = num / 2;
		int level = root / 2 + 1;

		bfs(root, level);

	}
	
	return 0;
}