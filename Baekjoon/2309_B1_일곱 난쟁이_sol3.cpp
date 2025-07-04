#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int cnt = 9;
vector<int> v(cnt);

pair<int, int> ret;
void combi()
{
	int sum = 0;

	for (auto& e : v)
		sum += e;

	for (int i = 0; i < cnt-1; i++)
	{
		for (int j = i + 1; j < cnt; j++)
		{
			if ((sum - v[i] - v[j]) == 100)
			{
				ret.first = v[i]; ret.second = v[j];
				return;
			}

		}
	}
}

int main()
{
	for (int i = 0; i < cnt; i++)
		cin >> v[i];

	sort(v.begin(), v.end());
	combi();

	for (int i = 0; i < cnt; i++)
	{
		if (v[i] == ret.first || v[i] == ret.second) continue;

		cout << v[i] << '\n';
	}
	return 0;
}