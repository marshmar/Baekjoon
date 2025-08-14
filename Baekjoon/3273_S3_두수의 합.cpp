#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, t, x, l, r, ret;
vector<int> v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());

	cin >> x;

	l = 0;
	r = n - 1;

	while (l < r)
	{
		if (v[l] + v[r] == x)
		{
			ret++;
			l++;
		}
		else if (v[l] + v[r] > x)
			r--;
		else
			l++;
	}

	cout << ret << "\n";
	return 0;
}