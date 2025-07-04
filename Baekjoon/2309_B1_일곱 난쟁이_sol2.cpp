#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int cnt = 9;

vector<int> v(cnt);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < cnt; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	do
	{
		int sum = 0;
		for (int i = 0; i < 7; i++)
		{
			sum += v[i];
			

		}
		if (sum == 100) {
			break;
		}
	} while (next_permutation(v.begin(), v.end()));

	for (int i = 0; i < 7; i++)
		cout << v[i] << '\n';

	return 0;
}

