#include<iostream>
#include<string>
using namespace std;

int N;
string s;

char q[101][101];

string quard(int y, int x, int size)
{
	// covnert char to str
	if (size == 1) return string(1, q[y][x]);
	char t = q[y][x];
	string ret = "";
	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (t != q[i][j])
			{
				ret += '(';
				ret += quard(y, x, size / 2);
				ret += quard(y, x + size / 2, size / 2);
				ret += quard(y + size / 2, x, size / 2);
				ret += quard(y + size / 2, x + size / 2, size / 2);
				ret += ')';
				return ret;
			}
		}
	}

	return string(1, q[y][x]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j = 0; j < N; j++)
			q[i][j] = s[j];
	}

	cout << quard(0, 0, N) << '\n';
	return 0;
}