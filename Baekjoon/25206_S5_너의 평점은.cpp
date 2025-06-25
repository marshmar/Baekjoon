#include<iostream>
#include<tuple>
#include<vector>
#include<string>
#include<iomanip>

using namespace std;

const int testCount = 20;

double CalculateGrade(string s)
{
	if (s == "A+")
		return 4.5;
	else if (s == "A0")
		return 4.0;
	else if (s == "B+")
		return 3.5;
	else if (s == "B0")
		return 3.0;
	else if (s == "C+")
		return 2.5;
	else if (s == "C0")
		return 2.0;
	else if (s == "D+")
		return 1.5;
	else if (s == "D0")
		return 1.0;
	else if (s == "F")
		return 0.0;
}

vector<string> split(const string& input, string delimiter)
{
	vector<string> result;
	auto start = 0;
	auto end = input.find(delimiter);
	while (end != string::npos)
	{
		result.push_back(input.substr(start, end - start));
		start = end + delimiter.size();
		end = input.find(delimiter, start);
	}

	result.push_back(input.substr(start));
	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	double totalCredit = 0;
	double totalGrade = 0;
	for (int i = 0; i < testCount; i++)
	{
		string input;
		getline(cin, input);
		vector<string> splitInputs = split(input, " ");

		if (splitInputs[2] != "P")
		{
			double grade = CalculateGrade(splitInputs[2]);
			double credit = stod(splitInputs[1]);
			totalCredit+= credit;
			totalGrade += grade * credit;
		}
	}

	cout << fixed << std::setprecision(6);
	cout << totalGrade / totalCredit;
	return 0;
}