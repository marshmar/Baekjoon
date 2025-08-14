/*
* Memory Paging Optimal Algorithm.
* (Optimal Page Replacement Algorithm) -> 가장 먼 미래에 참조되는 페이지를 스와핑
*/
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

const int ms = 100;
int n, k, ret, a[ms+4], visited[ms + 4];
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < k; i++) 
		cin >> a[i];
	
	for (int i = 0; i < k; i++)
	{
		if (!visited[a[i]])
		{
			if (v.size() == n)
			{
				int lidx = 0, pos = 0;
				for (int t : v)
				{
					int e = INT_MAX;
					for (int j = i + 1; j < k; j++) // 미래를 보면서 가장 멀리 있는 것을 찾는 알고리즘
					{
						if (t == a[j])
						{
							e = j;
							break;
						}
					}
					if (lidx < e)
					{
						lidx = e;
						pos = t;
					}
				}
				visited[pos] = 0;
				ret++;
				v.erase(find(v.begin(), v.end(), pos));
			}
			v.push_back(a[i]);
			visited[a[i]] = 1;
		}
	}

	cout << ret << "\n";
	return 0;
}