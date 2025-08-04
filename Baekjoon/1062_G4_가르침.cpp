#include<iostream>
#include<string>
#include<bitset>
#include<vector>
#include<climits>
using namespace std;
using p_t = pair<int, int>;

int ret, n, k;

vector<char> ta = {
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
};

vector<char> a = {
	'b', 'd', 'e', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'o', 'p', 'q', 'r', 's', 'u', 'v', 'w', 'x', 'y', 'z'
};

vector<p_t> alphas;

void solve(int alpha, int cnt, int ms)
{
	if (cnt == ms)
	{
		int t = 0;
		for (int i = 0; i < alphas.size(); i++)
		{
			if ((alphas[i].first | alpha) == alpha) t++;
		}

		ret = max(ret, t);
		return;
	}

	for (int i = 0; i < a.size(); i++)
	{
		if (alpha & (1 << (a[i] - 'a'))) continue;
		alpha |= (1 << (a[i] - 'a'));
		solve(alpha, cnt + 1, ms);
		alpha &= ~(1 << (a[i] - 'a'));
	}
}

void combi()
{

}

void solve2(int alpha, int cnt, int ms)
{
	if (cnt == ms)
	{
		int t = 0;
		for (int i = 0; i < alphas.size(); i++)
		{
			if ((alphas[i].first | alpha) == alpha) t++;
		}

		ret = max(ret, t);
		return;
	}

	for (int i = 0; i < a.size(); i++)
	{
		if ((alpha & (1 << (a[i] - 'a'))) == 0) continue;
		alpha &= ~(1 << (a[i] - 'a'));
		//cout << "alpha: " << bitset<26>(alpha) << "\n";
		solve2(alpha, cnt + 1, ms);
		alpha |= (1 << (a[i] - 'a'));
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	string s;

	for (int i = 0; i < n; i++)
	{
		int alpha = 0, cnt = 0;
		cin >> s;

		for (int j = 0; j < s.length(); j++)
		{
			if (!(alpha & (1 << (s[j] - 'a'))))
			{
				alpha |= (1 << (s[j] - 'a'));
				cnt++;
			}
		}

		if (cnt <= k)
			alphas.push_back({ alpha, cnt });
	}

	if (k <= 5)
		cout << 0 << "\n";
	else
	{
		if (alphas.size())
		{
			for (int i = 0; i < alphas.size(); i++)
			{
				int t = 1;

				cout << "diff: " << abs(k - alphas[i].second) << "\n";
				if (abs(k - alphas[i].second) <= 11)
				{
					int alpha = alphas[i].first;
					solve(alpha, 0, k - alphas[i].second);
				}
				else
				{
					int alpha = (1 << 26) - 1;
					solve2(alpha, 0, 26 - k);
				}

			}
		}
		cout << ret << "\n";
	}
}