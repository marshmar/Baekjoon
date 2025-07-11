#include<iostream>
#include<vector>

using namespace std;

int N, M, cnt = 0, input[15001];

void Combi(int start, vector<int>& v)
{
	if (v.size() == 2)
	{
		if (input[v[0]] + input[v[1]] == M)
		{
			cnt++;
			return;
		}

	}

	for (int i = start + 1; i < N; i++)
	{
		v.push_back(i);
		Combi(i, v);
		v.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> input[i];
	}

	vector<int> ret;
	Combi(-1, ret);
	cout << cnt << '\n';
	return 0;
}