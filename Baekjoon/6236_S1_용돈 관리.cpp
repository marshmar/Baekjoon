/*
* 핵심 알고리즘: 이분 탐색
* 시간복잡도: O(nlogn): 이분 탐색(O(logn)) * checkPrice(O(n))
*/
#include<iostream>
#include<vector>
using namespace std;

const int maxK = 1'000'000'004;
int n, m, minPrice, ret = maxK;
vector<int> prices;

bool checkPrice(int mid)
{
	if (minPrice > mid) return false;

	int kCount = 0, temp = mid;
	for (int i = 0; i < prices.size(); i++)
	{
		if (mid - prices[i] < 0)
		{
			kCount++;
			mid = temp;
		}
		mid -= prices[i];
	}

	if (mid != temp) kCount++;
	return kCount <= m;
}

void binarySearch()
{
	int left = 1, right = maxK, mid;

	while (left <= right)
	{
		mid = (left + right) / 2;
		
		if (checkPrice(mid))
		{
			ret = min(ret, mid);
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	int price;
	for (int i = 0; i < n; i++)
	{
		cin >> price;
		prices.push_back(price);
		minPrice = max(minPrice, price);
	}
		
	binarySearch();
	cout << ret << "\n";
	
	return 0;
}