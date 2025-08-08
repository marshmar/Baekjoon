#include<iostream>
#include<stack>
using namespace std;

const int ms = 500'004;
int n, ret, cnt, a[ms], v[ms];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n; 
	
	for (int i = 0; i < n; i++)
		cin >> a[i];

	fill(v, v + ms, 1);
	stack<int> s;
	s.push(0);
	cnt = 1;

	for (int i = 1; i < n; i++)
	{
		while (s.size() && i < n)
		{
			if (a[s.top()] > a[i])
			{
				cnt++;
			}
			else 
			{
				v[s.top()] = cnt;
				s.pop();
				s.push(i);
				cnt = 1;
			}
			i++;
		}
	}
	
	if (cnt != 1)
	{
		v[s.top()] = cnt;
	}

	for (int i = 0; i < n; i++)
	{
		//cout << v[i] << " ";
		ret += v[i];
	}
	//cout << "\n";


	cout << ret-1 << "\n";
	return 0;
}