#include<iostream>
#include<vector>
using namespace std;

const int ms = 4'000'000;
int n, l, r, sum, ret;
bool che[ms+4];
vector<int> p;

vector<int> era(int mx_n)
{
	vector<int> v;
	for (int i = 2; i <= mx_n; i++)
	{
		if (che[i]) continue;
		for (int j = 2 * i; j <= mx_n; j += i)
			che[j] = 1;
	}

	for (int i = 2; i <= mx_n; i++)
	{
		if (che[i] == 0)
			v.push_back(i);
	}
	return v;
}

int main()
{
	cin >> n;
	p = era(n);

	if (n == 1)
		cout << 0 << "\n";
	else if (n > 1 && n <= 3)
		cout << 1 << "\n";
	else
	{
		l = 0; r = 1; sum = p[l] + p[r];

		while (l < r && p[r] < n)
		{
			if (sum < n)
			{
				r++;
				sum += p[r];
			}
			else if (sum == n)
			{
				r++;
				ret++;
				sum += p[r];
			}
			else
			{
				sum -= p[l];
				l++;
			}
		}
		if (!che[n]) ret++;

		cout << ret << "\n";
	}

	return 0;
}