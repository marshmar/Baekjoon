#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool binarySearch(vector<int>& v, const int& num)
{
	int l = 0, r = v.size()-1, m = 0;

	while (l <= r)
	{
		m = (l + r) / 2;
		if (v[m] == num) return true;
		
		if (v[m] < num) l = m + 1;
		else if (v[m] > num) r = m - 1;
	}

	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N = 0, M = 0;
	cin >> N;
	vector<int> v(N);

	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v[i] = num;
	}

	sort(v.begin(), v.end());

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> num;
		if (binarySearch(v, num))
			cout << 1;
		else
			cout << 0;
		
		cout << " ";
	}

	return 0;
}