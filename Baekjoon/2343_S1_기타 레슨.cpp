/*
* 백준 2343_S1_기타 레슨
* 알고리즘: 이분탐색
* 시간복잡도: O(nlogn)
* why?:
* when?:
* how?:
*/

#include<iostream>
#include<vector>
using namespace std;

int n, m, minTime = 10'001, maxTime = 0, ret;
vector<int> times;

// O(n)
bool search(int diskTime)
{
	int sum = 0, bCount = 0;
	for (int i = 0; i < times.size(); i++)
	{
		// mid가 강의 시간보다 작으면 안됨
		if (times[i] > diskTime) return false;

		sum += times[i];
		if (sum >= diskTime)
		{
			bCount++;
			if (sum == diskTime)
				sum = 0;
			else
				sum = times[i];
		}
	}

	if (sum > 0) bCount++;

	return bCount <= m;
}

// O(nlogn)
void solve()
{
	int left = minTime, right = maxTime, mid = 0;
	ret = maxTime;

	while (left <= right)
	{
		mid = (left + right) / 2;

		//cout << "left: " << left << " right: " << right << " mid: " << mid << "\n";

		if (search(mid))
		{
			ret = min(ret, mid);
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	
	int time;
	for (int i = 0; i < n; i++)
	{
		cin >> time;
		times.push_back(time);

		minTime = min(minTime, time);
		maxTime += time;
	}
	
	solve();
	cout << ret << "\n";
	return 0;
}