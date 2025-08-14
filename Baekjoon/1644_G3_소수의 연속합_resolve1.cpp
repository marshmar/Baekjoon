#include<iostream>
#include<vector>
using namespace std;

const int ms = 4'000'000;
int n, l, r, ret;
bool che[ms + 4];
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 2; i <= n; i++)
	{
		if (che[i]) continue;
		for (int j = 2 * i; j <= n; j += i)
			che[j] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		if (!che[i])
			v.push_back(i);
	}
	
	if (!v.size())
	{
		cout << 0 << "\n";
	}
	else
	{
		int sum = v[0];
		while (r < v.size()-1)
		{
			if (sum == n)
			{
				ret++;
				sum -= v[l];
				l++;
			}
			else if (sum < n)
			{
				r++;
				sum += v[r];
			}
			else
			{
				sum -= v[l];
				l++;
			}
		}

		if (!che[n]) ret++;
		cout << ret << "\n";
	}


	return 0;
}