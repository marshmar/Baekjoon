#include<iostream>
#include<vector>
using namespace std;

int N;
string s;


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

void solve(string& s, vector<string>& v)
{
	if (s.size() < v[0].size() + v[1].size())
	{
		cout << "NE" << endl;
		return;
	}

	for (unsigned int j = 0; j < v[0].size(); j++)
	{
		if (*(s.begin() + j) != v[0][j])
		{
			cout << "NE" << endl;
			return;
		}
	}

	for (unsigned int j = 0; j < v[1].size(); j++)
	{
		if (*(s.rbegin() + j) != *(v[1].rbegin() + j))
		{
			cout << "NE" << endl;
			return;
		}

	}

	cout << "DA" << endl;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	string s;
	cin >> s;

	vector<string> ret;
	ret = split(s, "*");
	
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		solve(s, ret);
	}

	return 0;
}