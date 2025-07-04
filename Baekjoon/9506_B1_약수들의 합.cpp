#include<iostream>
#include<vector>

using namespace std;

void findDiv(int num, vector<int>& v)
{
	int ret = 0;

	for (int i = 1; i < num; i++)
	{
		if (num % i == 0)
		{
			v.push_back(i);
			ret += i;
		}
	}

	if (ret != num)
		v.clear();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int num;
	do {
		cin >> num;
		if (num == -1) break;

		vector<int> v;
		findDiv(num, v);

		if (v.size() == 0)
			cout << num << " is NOT perfect.\n";
		else
		{
			cout << num << " = ";
			for (int i = 0; i < v.size() - 1; i++)
			{
				cout << v[i] << " + ";
			}
			cout << v[v.size()-1] << "\n";
		}

	} while (true);

	return 0;
}