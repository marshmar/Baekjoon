/*
* 백준 1269_S4_대칭 차집합
* 시간복잡도: O(nlogn) : sort->O(nlogn), 배열 원소마다 binarySearch-> O(nlogn)
* 
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int na, nb, intersection;
vector<int> a, b;

bool binarySearch(vector<int>& t, int target)
{
	int left = 0, right = t.size() - 1, mid = 0;

	while (left <= right)
	{
		mid = (left + right) / 2;

		if (t[mid] == target)
			return true;
		else if (t[mid] > target)
			right = mid - 1;
		else
			left = mid + 1;
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> na >> nb;

	int num;
	for (int i = 0; i < na; i++)
	{
		cin >> num;
		a.push_back(num);
	}

	sort(a.begin(), a.end());

	for (int i = 0; i < nb; i++)
	{
		cin >> num;
		b.push_back(num);
		if (binarySearch(a, num))
			intersection++;
	}

	cout << (b.size() - intersection) + (a.size() - intersection) << "\n";

	return 0;
}