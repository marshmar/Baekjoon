#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr)
{
	vector<int> ret = arr;
	ret.erase(unique(ret.begin(), ret.end()), ret.end());

	for (auto& e : ret)
	{
		cout << e << " ";
	}
	cout << endl;

	return ret;
}

int main()
{
	solution({4,4,4,3,3 });
	return 0;
}