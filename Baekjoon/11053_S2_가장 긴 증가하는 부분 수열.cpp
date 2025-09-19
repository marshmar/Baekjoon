#include<iostream>
#include<algorithm>
using namespace std;

const int ms = 1000;
int n, arr[ms], cnt[ms], ret;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int maxValue = 0;
		cin >> arr[i];
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && maxValue < cnt[j])
				maxValue = cnt[j];
		}
		cnt[i] = maxValue + 1;
		ret = max(ret, cnt[i]);
	}
	cout << ret << "\n";
	return 0;
}