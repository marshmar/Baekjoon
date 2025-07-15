#include<iostream>
#include<stack>

using namespace std;

const int maxN = 1'000'004;
int a[maxN], ret[maxN];

int n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	stack<int> s;
	fill(&ret[0], &ret[n], -1);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		
		while (s.size() && a[s.top()] < a[i])
		{
			ret[s.top()] = a[i];
			s.pop();
		}
		s.push(i);
	}

	for (int i = 0; i < n; i++)
		cout << ret[i] << " ";
}