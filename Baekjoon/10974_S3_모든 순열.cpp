#include<iostream>
#include<algorithm>
#include<vector>

int main()
{
	using namespace std;

	int N;

	std::cin >> N;
	vector<int> v;

	for (int i = 1; i < N + 1; i++)
		v.push_back(i);

	do {
		for (int num : v)
			cout << num << " ";

		cout << '\n';
	} while (next_permutation(v.begin(), v.end()));

	return 0;
}