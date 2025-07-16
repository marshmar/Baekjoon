#include<iostream>
#include<stack>

using namespace std;

const int ms = 1'000'004;

int a[ms], ret[ms];
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	stack<int> s;
	fill(&ret[0], &ret[N], -1);
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];

		while (s.size() && a[s.top()] < a[i])
		{
			ret[s.top()] = a[i];
			s.pop();
		}
		s.push(i);
	}

	for (int i = 0; i < N; i++)
		cout << ret[i] << " ";

}