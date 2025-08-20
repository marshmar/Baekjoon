#include<iostream>
using namespace std;
using ll = long long;

ll n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cout << (n - 1) * n / 2<< "\n";
	cout << "2" << "\n";
	return 0;
}