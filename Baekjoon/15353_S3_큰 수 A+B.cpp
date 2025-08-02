#include<iostream>
#include<string>
using namespace std;

int s, m;
string n1, n2, ret;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n1 >> n2;

	s = min(n1.length(), n2.length()) - 1;
	m = max(n1.length(), n2.length()) - 1;
	int p = 0, sum = 0;
	for (int i = 0; i <= m; i++)
	{
		if (i > s)
		{
			if (n1.length() > n2.length())
				sum = n1[m -i] - '0';
			else
				sum = n2[m -i] - '0';
		}
		else
		{
			if (n1.length() > n2.length())
				sum = (n1[m - i] - '0') + (n2[s - i] - '0');
			else
				sum = (n1[s - i] - '0') + (n2[m - i] - '0');
		}

		if (p)
		{
			sum += 1;
		}

		if (sum >= 10)
			p = 1;
		else
			p = 0;

		ret.insert(0, to_string(sum % 10));
	}

	if (p)
	{
		ret.insert(0, to_string(1));
	}

	cout << ret << "\n";
	return 0;
}