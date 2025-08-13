#include<iostream>
using namespace std;

const int ms = 4'000'000;
bool che[ms + 4];
int n, a[2'000'001], p, l, r, ret, sum;

int main()
{
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		if (che[i]) continue;
		for (int j = 2 * i; j <= n; j += i)
			che[j] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		if (!che[i]) a[p++] = i; // º¤ÅÍ Çª½¬¹éÃ³·³ µ¿ÀÛ
	}

	while(1)
	{
		if (sum >= n) sum -= a[l++];
		else if (r == p) break;
		else sum += a[r++];
		if (sum == n) ret++;
	}

	cout << ret << "\n";
}