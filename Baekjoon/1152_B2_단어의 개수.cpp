#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> split(const string& input, string delimiter)
{
	vector<string> result;
	auto start = 0;
	auto end = input.find(delimiter);

	while (end != string::npos)
	{
		auto subString = input.substr(start, end - start);
		if(subString != "" || subString != "\0")
			result.push_back(subString);
		start = end + delimiter.size();
		end = input.find(delimiter, start);
	}

	auto subString = input.substr(start);
	if (subString != "" || subString != "\0")
		result.push_back(subString);
	return result;
}

int main()
{
	string input;
	vector<string> result;
	getline(cin, input);
	
	result = split(input, " ");
	cout << result.size() << '\n';
	return 0;
}