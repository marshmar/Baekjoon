#include<iostream>
#include<climits>
using namespace std;

const int ms = 100'000;
int a[ms];
int n, ret = INT_MIN, sum;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++)
	{
		sum += a[i];
		ret = max(sum, ret);
		if (sum < 0) sum = 0;
	}
	
	cout << ret << "\n";
	return 0; 
}