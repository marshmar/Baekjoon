#include<iostream>
using namespace std;

int n, x, a, b;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> x;
		cout << a * (x - 1) + b << "\n";
	}
	return 0;
}