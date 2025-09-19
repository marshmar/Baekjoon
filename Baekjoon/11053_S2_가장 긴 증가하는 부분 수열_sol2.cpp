#include<iostream>
#include<algorithm>
using namespace std;

const int ms = 1001;
int n, a[ms], ret, len, num;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;

		auto lowerPos = lower_bound(a, a + len, num);
		if (*lowerPos == 0) len++;
		*lowerPos = num;
	}

	cout << len << "\n";
	return 0;
}