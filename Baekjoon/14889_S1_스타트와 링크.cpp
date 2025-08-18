#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;

const int ms = 24;
int n, t1r, t2r, ret = INT_MAX;
int p[ms][ms];
bool visited[ms];

vector<vector<int>> c;
vector<int> players;

void combi(vector<int>& temp, int idx)
{
	if (temp.size() == (n / 2))
	{
		c.push_back(temp);
		return;
	}

	for (int i = idx + 1; i < n; i++)
	{
		temp.push_back(players[i]);
		combi(temp, i);
		temp.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> p[i][j];

	for (int i = 0; i < n; i++)
		players.push_back(i);

	vector<int> t;
	combi(t, -1);

	for (auto& t1 : c)
	{
		fill(visited, visited + ms, 0);

		t1r = 0;
		t2r = 0;

		for (auto& e : t1)
			visited[e] = 1;

		vector<int> t2;
		for (int i = 0; i < n; i++)
		{
			if (!visited[i]) t2.push_back(i);
		}

		for (auto& i : t1)
			for (int j = 0; j < t1.size(); j++)
				t1r += p[i][t1[j]];

		for (auto& i : t2)
			for (int j = 0; j < t2.size(); j++)
				t2r += p[i][t2[j]];

		ret = min(ret, abs(t2r - t1r));
	}

	cout << ret << "\n";
	return 0;
}