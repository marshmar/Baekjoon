#include<iostream>
#include<vector>

using namespace std;

int n, d, temp, root;
vector<int> adj[51];

int dfs(int h)
{
	int ret = 0;
	int child = 0;
	for (int e : adj[h])
	{
		if (e == d) continue;
		ret += dfs(e);
		child++;
	}
	if (child == 0) return 1;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		if (temp == -1) root = i;
		else adj[temp].push_back(i);
	}
	cin >> d;
	if (d == root)
	{
		cout << 0 << "\n";
		return 0;
	}
	cout << dfs(root) << "\n";

	return 0;
}