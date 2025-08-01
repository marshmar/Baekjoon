#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<map>
using namespace std;

int result = INT_MAX;

int N;
int cp, cf, cs, cv;
struct Ingredients
{
	int mp, mf, ms, mv, c;
};

int calc_diet(vector<Ingredients>& ig)
{
	int sump = 0, sumf = 0, sums = 0, sumv = 0, sumc = 0;

	for (int i = 0; i < ig.size(); i++)
	{
		sump += ig[i].mp;
		sumf += ig[i].mf;
		sums += ig[i].ms;
		sumv += ig[i].mv;
		sumc += ig[i].c;
	}

	if (sump < cp || sumf < cf || sums < cs || sumv < cv)
	{
		return -1;
	}

	//비용을 리턴
	return sumc;
}


vector<vector<Ingredients>> get_combinations(const vector<Ingredients>& positions)
{
	vector<vector<Ingredients>> res;
	int K = positions.size();
	vector<int> bitmask(K, 1);
	for (int i = 0; i < 3; ++i)
		bitmask[i] = 0;

	do
	{
		vector<Ingredients> selected;
		for (int i = 0; i < K; ++i)
		{
			if (bitmask[i] == 0)
				selected.push_back(positions[i]);
		}
		res.push_back(selected);
	} while (next_permutation(bitmask.begin(), bitmask.end()));
	return res;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	cin >> cp >> cf >> cs >> cv;

	vector<Ingredients> ingredients(N);

	for (int i = 0; i < N; i++)
	{
		cin >> ingredients[i].mp >> ingredients[i].mf >>
			ingredients[i].ms >> ingredients[i].mv >>
			ingredients[i].c;
	}

	vector<Ingredients> result_comb;
	auto combinations = get_combinations(ingredients);
	bool flag = false;

	for (auto& comb : combinations)
	{
		int total = calc_diet(comb);

		if (total != -1 && total < result)
		{
			flag = true; //하나라도 조합이 가능.
			result = total;
			result_comb = comb;  // 현재 조합을 저장
		}
	}

	//출력
	if (flag)
	{
		vector<int> indexes;
		for (auto& ing : result_comb)
		{
			for (int i = 0; i < N; i++)
			{
				if (ingredients[i].mp == ing.mp &&
					ingredients[i].mf == ing.mf &&
					ingredients[i].ms == ing.ms &&
					ingredients[i].mv == ing.mv &&
					ingredients[i].c == ing.c)
				{
					indexes.push_back(i + 1);
					break;
				}
			}
		}
		sort(indexes.begin(), indexes.end());
		cout << result << '\n';
		for (int idx : indexes)
		{
			cout << idx << " ";
		}
	}
	else
		cout << -1;

	return 0;
}