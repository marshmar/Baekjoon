#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int t, n1, n2;


bool binarySearch(vector<int>& note1, int target)
{
	int left = 0, right = n1 - 1, mid;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (note1[mid] == target)
			return true;
		else if (note1[mid] > target)
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

	cin >> t;

	int num;
	for (int i = 0; i < t; i++)
	{
		vector<int> note1;
		cin >> n1;
		for (int j = 0; j < n1; j++)
		{
			cin >> num;
			note1.push_back(num);
		}

		sort(note1.begin(), note1.end());

		cin >> n2;
		for (int j = 0; j < n2; j++)
		{
			cin >> num;
			if (binarySearch(note1, num))
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
	}
	return 0;
}