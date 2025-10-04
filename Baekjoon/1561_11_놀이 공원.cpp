#include<iostream>
#include<vector>
using namespace std;

vector<int> rides, temp;
int n, m, ret;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	int idx = 0;

	rides.resize(m);
	temp.resize(m);

	for (int i = 0; i < m; i++)
	{
		cin >> rides[i];
	}

	while (true)
	{
		for (int i = 0; i < m; i++)
		{
			if (--temp[i] <= 0)
			{
				temp[i] = rides[i];
				idx++;
			}
			if (idx == n)
			{
				ret = i + 1;
				break;
			}
			cout << "idx: " << idx << "\n";
		}
		if (ret != 0) break;
	}

	cout << ret << "\n";
	return 0;
}