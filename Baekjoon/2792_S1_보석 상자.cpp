#include<iostream>
#include<climits>
#include<vector>
using namespace std;

vector<int> v;
int n, m, k, ret = INT_MAX;

bool search(int quotient)
{
	int temp = 0;
	for (int i = 0; i < m; i++)
	{
		temp += v[i] / quotient;
		if (v[i] % quotient) temp++;
	}

	return temp <= n;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	int left = 1, right = 0, mid = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> k;
		v.push_back(k);
		right = max(right, v[i]);
	}

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (search(mid))
		{
			ret = min(ret, mid);
			right = mid -1;
		}
		else
			left = mid + 1;

	}

	cout << ret << "\n";
	return 0;
}