#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

set<int> s;
vector<int> input;


int ReturnDupNumSize(vector<int> v)
{
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	return v.size();
}

int test1(vector<int>& v)
{
	v.pop_back();
	if (ReturnDupNumSize(v) > 2) {
		test1(v);
	}

	return v.size();
}

int test2(vector<int>& v)
{
	v.erase(v.begin(), v.begin() + 1);
	if (ReturnDupNumSize(v) > 2) {
		test1(v);
	}
	return v.size();
}

int test3(vector<int>& v)
{
	v.pop_back();
	if (ReturnDupNumSize(v) <= 2) {
		return v.size();
	}

	v.erase(v.begin(), v.begin() + 1);
	if (ReturnDupNumSize(v) <= 2) {
		return v.size();
	}

	test3(v);
}

int test4(vector<int>& v)
{
	v.erase(v.begin(), v.begin() + 1);
	if (ReturnDupNumSize(v) <= 2) {
		return v.size();
	}

	v.pop_back();
	if (ReturnDupNumSize(v) <= 2) {
		return v.size();
	}

	test4(v);
}



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

			if (s.find(num) != s.end()) continue;
			else(s.insert(num));

		}

		if (s.size() <= 2)
		{
			cout << input.size();
			return 0;
		}

		vector<int> counts;
		vector<int> copy = input;
		counts.push_back(test1(copy));

		copy = input;
		counts.push_back(test2(copy));

		copy = input;
		counts.push_back(test3(copy));

		copy = input;
		counts.push_back(test4(copy));

		sort(counts.begin(), counts.end());
		cout << counts[3];
	}


	return 0;
}