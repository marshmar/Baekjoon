#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

vector<int> v(9);
int main()
{
	for (int i = 0; i < 9; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	do {
		int sum = 0;
		for (int i = 0; i < 7; i++)
			sum += v[i];

		if (sum == 100) break;
	} while (next_permutation(v.begin(), v.end()));

	for (int i = 0; i < 7; i++)
		cout << v[i] << endl;

	return 0;
}
