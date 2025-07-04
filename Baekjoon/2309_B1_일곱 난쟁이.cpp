#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int cnt = 9;
vector<int> v(cnt);
int n = cnt, k = 7;

void print(vector<int>& b)
{
	sort(b.begin(), b.end());
	for (int i : b) cout << i << "\n";
}

void combi(int start, vector<int>& b)
{
	if (b.size() == k)
	{
		int sum = 0;
		for (auto& e : b)
			sum += e;

		if (sum == 100)
		{
			print(b);
			exit(0);
		}
	}

	for (int i = start + 1; i < n; i++)
	{
		b.push_back(v[i]);
		combi(i, b);
		b.pop_back();
	}

	return;
}

int main()
{
	for (int i = 0; i < cnt; i++)
		cin >> v[i];

	vector<int> b;
	combi(-1, b);
	return 0;
}