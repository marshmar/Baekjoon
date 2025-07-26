/*
* 핵심 알고리즘은 조합 + 순열로 완전 탐색인데
* 시간을 줄이는 방법을 모르겠다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<climits>
#include<algorithm>
using namespace std;
using ll = long long;

int k;
string mx = "0000000000", mn = "9999999999";

vector<int> nums
{
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9
};
vector<vector<int>> c;
vector<char> op;

void print(vector<int>& t)
{
	for (auto& e : t)
		cout << e << " ";
	cout << "\n";
}

void combi(int idx, vector<int>& t)
{
	if (t.size() == k + 1)
	{
		c.push_back(t);
		print(t);
		return; 
	}

	for (int i = idx + 1; i < nums.size(); i++)
	{
		t.push_back(i);
		combi(i, t);
		t.pop_back();
	}
}

bool oper(char op, int n1, int n2)
{
	if (op == '<') return n1 < n2;
	if (op == '>') return n1 > n2;
}

bool solve(int idx, vector<int>& t)
{
	if (idx == t.size() - 1)
		return true;

	if (!oper(op[idx], t[idx], t[idx + 1]))
		return false;
	else
		return solve(idx + 1, t);
}

int main()
{
	scanf("%d", &k);

	for (int i = 0; i < k; i++)
	{
		char c;
		scanf(" %c", &c);
		op.push_back(c);
	}

	vector<int> temp;
	combi(-1, temp);

	for (auto e : c)
	{
		do {
			if (solve(0, e))
			{
				string s;
				for (auto& i : e)
					s += (char)(i + '0');

				if (mx < s) mx = s;
				if (mn > s) mn = s;
			}

		} while (next_permutation(e.begin(), e.end()));
	}

	cout << mx << "\n";
	cout << mn << "\n";
	return 0;
}