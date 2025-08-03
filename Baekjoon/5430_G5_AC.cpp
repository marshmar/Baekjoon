#include<iostream>
#include<string>
#include<vector>
using namespace std;

int T, n, l, r, sz;
bool flag;
string p, nums;

int a[100'000];

void split(const string& input, string delimiter)
{
	int index = 0;
	auto start = 0;
	auto end = input.find(delimiter);
	while (end != string::npos)
	{
		a[index] = atoi(input.substr(start, end - start).c_str());
		start = end + delimiter.size();
		end = input.find(delimiter, start);
		index++;
	}
	a[index] = atoi(input.substr(start, end - start).c_str());
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> p;
		cin >> n;
		cin >> nums;

		string temp = nums.substr(1, nums.size() - 2);
		//cout << temp << "\n";
		split(temp, ",");

		//for (int i = 0; i < n; i++)
		//{
		//	cout << a[i] << " ";
		//}
		//cout << "\n";
		
		l = 0;
		r = n-1;
		flag = 0;
		sz = n;
		for (int j = 0; j < p.length(); j++)
		{
			if (p[j] == 'R')
			{
				if (flag)
					flag = 0;
				else
					flag = 1;

				//cout << "flag: " << flag << "\n";
			}
			if (p[j] == 'D')
			{
				if (flag)
					r--;
				else
					l++;

				sz--;
			}
		}
		//cout << "l: " << l << "\n";
		//cout << "r: " << r << "\n";

		if (sz < 0)
		{
			cout << "error" << "\n";
		}
		else if (sz == 0)
		{
			cout << "[]" << "\n";
		}
		else
		{
			cout << "[";
			if (flag)
			{
				for (int j = r; j > l; j--)
				{
					cout << a[j] << ",";
				}
				cout << a[l];
			}
			else
			{
				for (int j = l; j < r; j++)
				{
					cout << a[j] << ",";
				}
				cout << a[r];
			}
			cout << "]" << "\n";
		}
		
	}
	return 0;
}