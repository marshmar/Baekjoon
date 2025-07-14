#include<iostream>
#include<map>
#include<string>
#include<limits>
#include<vector>

using namespace std;


int t, n, ret;
vector<pair<string, int>> v;

void combi(int idx, vector<pair<string, int>>& t, const int size, const int choiCnt)
{
	if (t.size() == choiCnt)
	{
		int cnt = 1;
		for (int i = 0; i < t.size(); i++)
			cnt *= t[i].second;
		ret += cnt;
		
		return;
	}

	for (int i = idx + 1; i < size; i++)
	{
		t.push_back(v[i]);
		combi(i, t, size, choiCnt);
		t.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		map<string, int> m;
		string s;

		cin.ignore(std::numeric_limits<int>::max(), '\n');

		for (int i = 0; i < n; i++)
		{
			getline(cin, s);
			auto idx = s.find(" ");

			string type = s.substr(idx+1);

			if (m.find(type) != m.end())
				m[type]++;
			else
				m.insert({ type, 1 });
		}

		vector < pair<string, int>> temp;
		for (auto& e : m)
		{
			v.push_back(make_pair(e.first, e.second));
		}

		for(int i = 1; i <= v.size(); i++)
			combi(-1, temp, v.size(), i);

		cout << ret << '\n';
		ret = 0;
		v.clear();
	}
	
	return 0;
}