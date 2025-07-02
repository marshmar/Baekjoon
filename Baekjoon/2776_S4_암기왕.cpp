#include<iostream>
#include<vector>
#include<set>

using namespace std;

const int maxSize = 1000004;
set<int> s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;

	int N, M, num;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		for (int j = 0; j < N; j++)
		{
			cin >> num;
			s.insert(num);
		}

		cin >> M;
		for (int j = 0; j < M; j++)
		{
			cin >> num;

			if (s.find(num) != s.end())
			{
				cout << 1 << '\n';
			}
			else
				cout << 0 << '\n';
		}

		s.clear();
	}
}