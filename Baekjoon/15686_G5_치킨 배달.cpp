
/*
* c는 치킨집 위치
* h는 집 위치
* vc는 m개 선택한 치킨집 위치
*
* 핵심 알고리즘
* (13C? * 100 * k개)의 시간복잡도를 가지기에 무식하게 풀 수 있다고 생각함.
* 
* - 치킨집을 m개 선택하는 모든 경우의수를 조합으로 구하고,
* 각 치킨집과 집 위치간의 치킨 거리를 구한 뒤에
* 이를 sum에 더하고,
* 모든 치킨집 조합에 대하여 mnd(가장 최소의 도시의 치킨 거리)를 구한다.
*/

#include<iostream>
#include<vector>
#include<tuple>
#include<climits>
using namespace std;

int n, m, ret;

const int ms = 54;

using p_t = pair<int, int>;
vector<p_t> c, temp, h;
vector<vector<p_t>> vc;

void combi(int idx)
{
	if (temp.size() == m)
	{
		vc.push_back(temp);
		return;
	}

	for (int i = idx + 1; i < c.size(); i++)
	{
		temp.push_back(c[i]);
		combi(i);
		temp.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int num;
			cin >> num;
			if (num == 2)
				c.push_back({ i, j });
			else if (num == 1)
				h.push_back({ i, j });
		}
	}

	combi(-1);

	ret = INT_MAX;
	for (auto& cp : vc)
	{
		int sum = 0;
		for (int i = 0; i < h.size(); i++)
		{
			int mnd = INT_MAX;
			for (auto& c : cp)
			{
				int d = abs(h[i].first - c.first) + abs(h[i].second - c.second);
				mnd = min(mnd, d);
			}
			sum += mnd;
		}
		ret = min(ret, sum);
	}
	cout << ret << "\n";
	return 0;
}

