#include<iostream>
#include<map>
#include<vector>

using namespace std;

map<int, int> result;
vector<int> inputs;

int main()
{
	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		std::cin >> num;

		inputs.push_back(num);

		if (result[num]) continue;
		else result[num] = 0;
	}

	int index = 0;
	for (auto num : result)
	{
		result[num.first] = index;
		index++;
	}

	for (auto& num : inputs)
		cout << result[num] << " ";
}