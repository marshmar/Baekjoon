#include<iostream>
using namespace std;

const int ms = 1004;
int n, a[ms], cnt[ms], ret;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++)
	{
		int maxValue = 0;
		for (int j = 0; j < i; j++)
		{
			if (a[j] < a[i] && maxValue < cnt[j])
			{
				maxValue = cnt[j];
			}	
		}
		cnt[i] = maxValue + 1;
		ret = max(ret, cnt[i]);
	}

	cout << ret << "\n";
	return 0;
}