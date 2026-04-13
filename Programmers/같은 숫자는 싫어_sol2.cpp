#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr)
{
	vector<int> ret;
	stack<int> s;

	for (auto& e : arr)
	{
		if (s.size())
		{
			if (s.top() == e) 
				continue;
		}
		s.push(e);
	}

	while (s.size())
	{
		ret.push_back(s.top());
		s.pop();
	}
	reverse(ret.begin(), ret.end());

	return ret;
}

int main()
{
	auto temp = solution({ 1, 1, 3, 3, 0, 1, 1 });

	for (auto& e : temp)
		cout << e << " ";

	return 0;
}