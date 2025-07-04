#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int n = 9, r = 7;
vector<int> v(n);

void solve()
{
	int sum = 0;
	for (int i = 0; i < r; i++)
		sum += v[i];

	if (sum == 100)
	{
		sort(v.begin(), v.begin() + 7);
		for (int i = 0; i < r; i++)
		{
			cout << v[i] << '\n';
		}
		exit(0);
	}
}

void makePermutation(int n, int r, int depth)
{
	if (depth == r)
	{
		solve();
		return;
	}

	for (int i = depth; i < n; i++)
	{
		swap(v[i], v[depth]);
		makePermutation(n, r, depth + 1);
		swap(v[i], v[depth]);
	}

	return;
}
int main()
{
	for (int i = 0; i < n; i++)
		cin >> v[i];

	makePermutation(9, 7, 0);
	return 0;
}