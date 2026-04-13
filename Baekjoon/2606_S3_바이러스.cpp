#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> computers;
bool visited[100];
int numComputers, numPairs;

int dfs(int index)
{
	visited[index] = 1;
	int count = 1;	
	for (auto& e : computers[index])
	{
		if (visited[e]) continue;
		
		count += dfs(e);
	}

	return count;
}

int main()
{
	cin >> numComputers;
	cin >> numPairs;

	computers.resize(numComputers);

	int n1, n2;
	for (int i = 0; i < numPairs; i++)
	{
		cin >> n1 >> n2;
		n1 -= 1;
		n2 -= 1;
		computers[n1].push_back(n2);
		computers[n2].push_back(n1);
	}

	cout << dfs(0) - 1 << endl;
	return 0;
}