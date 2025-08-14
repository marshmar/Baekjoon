#include<iostream>
#include<map>
using namespace std;
using ll = long long;

const int ms = 100'000;
int n, a[ms + 4], l, r, ret = 0;
ll s[ms + 4];
map<int, int> m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int i = 2;
	s[1] = 1;
	while (i <= n)
	{
		s[i] = s[i - 1] + i;
		i++;
	}

	m[a[0]] = 1;
	r = 1;
	while (true)
	{
		cout << "l: " << l << " r: " << r << " ret: " << ret << "\n";
		if (r == n)
		{
			ret += s[r - l];
			break;
		}
		if (l == r)
		{
			r++;
			continue;
		}
		if (m[a[r]])
		{
			cout << "c" << "\n";
			ret += s[r-l];
			l = m[a[r]];
			m[a[r]] = r + 1;
			r++;
		}
		else
		{
			m[a[r]] = r + 1;
			cout << "add: " << m[a[r]] << "\n";
			r++;
		}
	}
	
	//'if (a[l] == a[r]) ret++;

	cout << ret << "\n";
	return 0;
}