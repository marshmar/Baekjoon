#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n = 9, k = 7;
vector<int> v(9);

void print()
{
	for (int i = 0; i < 7; i++)
		cout << v[i] << endl;

	return;
}

[[noreturn]]void solve()
{
	int sum = 0;
	
	for (int i = 0; i < 7; i++)
	{
		sum += v[i];
	}

	if (sum == 100)
	{
		print();
		exit(0);
	}
	return;
}

void combi()
{

}

int main()
{
	for (int i = 0; i < 9; i++)
		cin >> v[i];

	sort(v.begin(), v.end());
	do
	{
		solve();
	} while (next_permutation(v.begin(), v.end()));
	return 0;
}