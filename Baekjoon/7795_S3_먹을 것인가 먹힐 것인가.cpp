#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t, n, m;

int binarySearch(vector<int>& t, int value)
{
	int left = 0, right = t.size()-1, mid = -1;

	while (left <= right)
	{
		mid = (left + right) / 2;

		if (t[mid] >= value)
			right = mid - 1;
		else
			left = mid + 1;
	}
	
	return left;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> m;
		vector<int> a(n), b(m);

		for (int j = 0; j < n; j++)
			cin >> a[j];

		for (int j = 0; j < m; j++)
			cin >> b[j];

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		int ret = 0;
		for (int j = 0; j < n; j++)
		{
			ret += binarySearch(b, a[j]);
		}

		cout << ret << "\n";
	}
	return 0;
}