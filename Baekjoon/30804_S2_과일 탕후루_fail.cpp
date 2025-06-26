#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void RemoveDupNum(vector<int>& v)
{
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
}

vector<int> input;
vector<int> s;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	{
		int num;
		for (int i = 0; i < N; i++)
		{
			cin >> num;
			input.push_back(num);
			s.push_back(num);
		}
	}

	RemoveDupNum(s);
	
	// 과일 종류가 2개 이하인 경우
	if (s.size() <= 2)
	{
		cout << input.size();
		return 0;
	}

	// 과일 종류가 3개 이상인 경우
	vector<int> copy(input);

	// 뒤에서 먼저 지우는 경우
	int backDelCouint;
	while (true)
	{
		copy.pop_back();
		s = copy;
		RemoveDupNum(s);
		if (s.size() <= 2)
			break;

		copy.erase(copy.begin(), copy.begin() + 1);

		RemoveDupNum(s);
		if (s.size() <= 2)
			break;
	}
	backDelCouint = (int)copy.size();

	// 앞에서 먼저 지우는 경우
	copy = input;
	int frontDelCouint;
	while (true)
	{
		copy.erase(copy.begin(), copy.begin() + 1);

		s = copy;
		RemoveDupNum(s);
		if (s.size() <= 2)
			break;

		copy.pop_back();
		RemoveDupNum(s);
		if (s.size() <= 2)
			break;
	}
	frontDelCouint = (int)copy.size();

	cout << (backDelCouint > frontDelCouint ? backDelCouint : frontDelCouint);

	return 0;
}