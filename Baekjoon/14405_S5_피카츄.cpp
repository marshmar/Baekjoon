#include<iostream>
#include<string>
using namespace std;

string s;
bool ret;

void solve(int idx)
{
	//cout << "idx:" << idx << "\n";
	if (idx >= s.length())
	{
		ret = true;
		return;
	}

	if (s[idx] == 'p' && s[idx + 1] == 'i')
		solve(idx + 2);
	else if (s[idx] == 'k' && s[idx + 1] == 'a')
		solve(idx + 2);
	else if (idx + 3 <= s.length() && s[idx] == 'c' && s[idx + 1] == 'h' && s[idx + 2] == 'u')
		solve(idx + 3);
	else
		ret = false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	solve(0);
	if (ret) cout << "YES";
	else cout << "NO";
}