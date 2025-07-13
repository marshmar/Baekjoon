#include<iostream>
#include<stack>
#include<string>

using namespace std;

int N, ret = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	string s;
	for (int i = 0; i < N; ++i)
	{
		cin >> s;

		stack<char> stk;
		for (auto& c : s)
		{
			if (stk.size() && stk.top() == c) stk.pop();
			else stk.push(c);
		}

		if (stk.size() == 0) ret++;
	}

	cout << ret << '\n';
	return 0;
}