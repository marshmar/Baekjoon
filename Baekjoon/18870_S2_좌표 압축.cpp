#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> input;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		std::cin >> num;

		input.push_back(num);
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (auto& num : input)
	{
		cout << lower_bound(v.begin(), v.end(), num) - v.begin() << " ";
	}

	return 0;
}

//내 처음 풀이 -> map을 사용하니까 속도가 훨씬 느리다..
//map<int, int> result;
//vector<int> inputs;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//	int N;
//	std::cin >> N;
//
//	for (int i = 0; i < N; i++)
//	{
//		int num;
//		std::cin >> num;
//
//		inputs.push_back(num);
//
//		if (result[num]) continue;
//		else result[num] = 0;
//	}
//
//	int index = 0;
//	for (auto num : result)
//	{
//		result[num.first] = index;
//		index++;
//	}
//
//	for (auto& num : inputs)
//		cout << result[num] << " ";
//}


