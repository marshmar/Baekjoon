#include<iostream>
#include<string>
using namespace std;

int N;
int ret = 0, cnt = 0;

int main()
{
	cin >> N;

	while (true)
	{
		string s = to_string(ret);
		if (s.find("666") != s.npos)
			cnt++;
		if (cnt == N) break;
		ret++;
	}
	cout << ret << "\n";
	return 0;
}