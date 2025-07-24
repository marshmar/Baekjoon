#include<iostream>
#include<vector>
#include<climits>
#include<tuple>
using namespace std;

int n, ret;
const int ms = 11;

int m[ms][ms];

using p_t = pair<int, int>;

vector<p_t> s;
vector<vector<p_t>> f;


bool check(vector<p_t>& temp)
{
	for (int i = 0; i < temp.size(); i++)
	{
		int diff;
		if (i == temp.size() - 1)
		{
			diff = abs(temp[i].first - temp[0].first) + abs(temp[i].second - temp[0].second);
		}
		else
		{
			diff = abs(temp[i].first - temp[i + 1].first) + abs(temp[i].second - temp[i + 1].second);
		}

		if (diff <= 2) return false;
	}
	return true;
}

void combi(int idx, vector<p_t>& temp)
{
	if (temp.size() == 3)
	{
		if (check(temp)) f.push_back(temp);
		return;
	}

	for (int i = idx + 1; i < s.size(); i++)
	{
		temp.push_back(s[i]);
		combi(i, temp);
		temp.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> m[i][j];


	for (int i = 1; i < n - 1; i++)
		for (int j = 1; j < n - 1; j++)
			s.push_back({ i, j });

	vector<p_t> temp;
	combi(-1, temp);

	ret = INT_MAX;
	for (auto& e : f)
	{
		int sum = 0;
		for (int i = 0; i < e.size(); i++)
		{
			int y, x;
			tie(y, x) = e[i];

			sum += m[y][x];
			sum += m[y - 1][x];
			sum += m[y][x-1];
			sum += m[y + 1][x];
			sum += m[y][x+1];
		}

		ret = min(ret, sum);
	}

	cout << ret << "\n";
	return 0;
}