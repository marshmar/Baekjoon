#include<iostream>
#include<map>
#include<string>
using namespace std;


map<char, int> m;
string input, ret;

void solve()
{
	bool canP = true;
	int index = 0;
	char center;
	int	flag = 0;
	for (auto& e : m)
	{
		if (e.second % 2 == 1)
		{
			flag++;
			if (flag == 2)
			{
				cout << "I'm Sorry Hansoo" << endl;
				break;
			}

			center = e.first;
			e.second--;
		}
		
		int n = e.second;
		
		while (n > 0)
		{
			ret.insert(ret.begin() + index, e.first);
			n--;
		}
		index += e.second / 2;
		
		
	}

	if(center)
		ret.insert(ret.begin() + ret.size() / 2, center);
	cout << ret << endl;
}
int main()
{
	cin >> input;

	for (auto i = 0; i < input.size(); i++)
	{
		if (m.find(input[i]) != m.end())
			++m[input[i]];
		else
			m.insert({ input[i], 1 });
	}

	solve();
	return 0;
}