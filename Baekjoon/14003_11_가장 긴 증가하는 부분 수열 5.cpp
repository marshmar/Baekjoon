#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int ms = 1'000'004, INF = 1'000'000'004;
int n, a[ms];
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	v.push_back(-INF);
	for (int i = 0; i < n; i++)
	{
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << "\n";

		if (a[i] <= v.back())
		{
			auto idx = lower_bound(v.begin(), v.end(), a[i]);
			if (v.end() - idx < 0)
				continue;
			else
				*(idx) = a[i];


		}
		else
			v.push_back(a[i]);
	}

	cout << v.size()-1 << "\n";
	for (int i = 1; i < v.size(); i++)
		cout << v[i] << " ";
	cout << "\n";

	return 0;
}