#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

const int m = 49;
const int s = 60;

int one[m][s];
int two[m][s];

int oneRet, twoRet;

int main()
{
	int n,team, oneS = 0, twoS = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> team;

		string temp;
		cin >> temp;

		int min, sec;
		min = atoi(temp.substr(0, temp.find(":")).c_str());
		sec = atoi(temp.substr(temp.find(":")+1).c_str());

		if (team == 1)
		{
			oneS++;
			fill(&one[min][sec], &one[m-1][s - 1], oneS);
			one[m - 1][0] = oneS;
		}
		else if (team == 2)
		{
			twoS++;
			fill(&two[min][sec], &two[m-1][s - 1], twoS);
			two[m - 1][0] = twoS;
		}
	}

	for (int i = 0; i < m-1; i++)
	{
		for (int j = 0; j < s; j++)
		{
			if (one[i][j] < two[i][j])
				twoRet++;
			else if (one[i][j] > two[i][j])
				oneRet++;
		}
	}
	
	cout << setw(2) << setfill('0');
	cout << oneRet / 60 << ":";
	cout << setw(2) << setfill('0');
	cout << oneRet % 60 << '\n';

	cout << setw(2) << setfill('0');
	cout << twoRet / 60 << ":";
	cout << setw(2) << setfill('0');
	cout << twoRet % 60 << '\n';

	return 0;
}
