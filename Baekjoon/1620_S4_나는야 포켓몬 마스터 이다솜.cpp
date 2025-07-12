#include<iostream>
#include<string>
#include<map>

using namespace std;

using p_t = pair<string, int>;

int N, M;
map<string, int> m;
string a[100'004];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	
	string s;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		m.insert({ s, i });
		a[i] = s;
	}


	for (int i = 0; i < M; i++)
	{
		cin >> s;

		if (atoi(s.c_str()))
			cout << a[atoi(s.c_str())-1] << '\n';
		else
		{
			cout << m[s]+1 << '\n';
		}
	}
	return 0;
}