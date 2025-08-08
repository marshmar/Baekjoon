#include<iostream>
#include<stack>
using namespace std;
using ll = long long;

ll n, ret, temp;
stack<pair<ll, ll>> s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		int cnt = 1;
		while (s.size() && s.top().first <= temp)
		{
			ret += s.top().second;
			if (s.top().first == temp)	// 같은 경우에는 누적해서 더해야 함.
				cnt = s.top().second + 1;
			else
				cnt = 1;

			s.pop();
		}

		if (s.size()) ret++;	// 내림차순 계산
		s.push({ temp, cnt });
	}

	cout << ret << "\n";
}