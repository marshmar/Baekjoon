#include<unordered_map>
#include<iostream>
#include<algorithm>

using namespace std;

using p_t = pair<int, int>;

vector<p_t> v;

int N, C;

int find(int num)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].second == num) return i;
	}
	return -1;
}

bool compare(p_t p1, p_t p2)
{
	return p1.first > p2.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N  >> C;
	int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		int index = find(num);
		if (index != -1)v[index].first++;
		else v.push_back({ 1, num });

	}

	stable_sort(v.begin(), v.end(), compare);

	for (auto& e : v)
	{
		for (int i = 0; i < e.first; i++)
			cout << e.second << " ";
	}

	return 0;
}