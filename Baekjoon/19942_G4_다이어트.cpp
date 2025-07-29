#include<iostream>
#include<vector>
#include<climits>
#include<string>
#include<algorithm>
using namespace std;

int n, mp, mf, ms, mv, retc = INT_MAX;

vector<int> p, f, s, v, c;
vector<string> ret;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> mp >> mf >> ms >> mv;

	int tp, tf, ts, tv, tc;
	for (int i = 0; i < n; i++)
	{
		cin >> tp >> tf >> ts >> tv >> tc;
		p.push_back(tp);
		f.push_back(tf);
		s.push_back(ts);
		v.push_back(tv);
		c.push_back(tc);
	}

	for (int i = 1; i < (1 << n); i++)
	{
		int sp = 0, sf = 0, ss = 0, sv = 0, sc = 0;
		string temp;
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				temp += to_string(j + 1) + " ";
				sp += p[j];
				sf += f[j];
				ss += s[j];
				sv += v[j];
				sc += c[j];
			}
		}

		if (sp >= mp && sf >= mf && ss >= ms && sv >= mv)
		{
			if (retc > sc)
			{
				ret.clear();
				retc = sc;
				ret.push_back(temp);
			}
			else if (retc == sc)
			{
				ret.push_back(temp);
			}
		}

	}
	
	if (retc == INT_MAX)
	{
		cout << -1 << "\n";
	}
	else
	{
		cout << retc << "\n";
		sort(ret.begin(), ret.end());
		cout << ret[0] << "\n";
	}
	return 0;
}