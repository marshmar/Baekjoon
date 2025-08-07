#include<iostream>
#include<string>
#include<stack>
#include<climits>
using namespace std;

int n, cnt, scnt, ret;
string input;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> input;

	int idx = 0;
	while (idx < n)
	{
		stack<char> s;
		cnt = 0;
		if (input[idx] == '(')
		{
			s.push(input[idx]);
		}

		while (s.size())
		{
			idx++;
			if (idx >= n)
			{
				break;
			}

			if (input[idx] == '(')
			{
				s.push(input[idx]);
				if (idx + 1 < n && input[idx + 1] == '(')
				{
					ret = max(ret, scnt);
					scnt = 0;
				}
			}
			else
			{
				cnt += 2;
				scnt += 2;
				s.pop();
			}


			if (s.size() == 0)
			{
				if (idx < n - 1 && input[idx + 1] == '(')
				{
					s.push(input[idx + 1]);
					idx++;
				}
			}
		}

		ret = max(ret, cnt);
		idx++;
	}

	cout << ret << "\n";
	return 0;
}