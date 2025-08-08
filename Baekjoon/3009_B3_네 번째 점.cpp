#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using p_t = pair<int, int>;

int mxx = 1, mnx = 1000, mxy = 1, mny = 1000;

vector<p_t> input;
vector<p_t> square;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int x, y;

	for (int i = 0; i < 3; i++)
	{
		cin >> x >> y;
		input.push_back({ x, y });
		mxx = max(mxx, x);
		mnx = min(mnx, x);
		mxy = max(mxy, y);
		mny = min(mny, y);
	}

	square.push_back({ mnx, mny });
	square.push_back({ mnx, mxy });
	square.push_back({ mxx, mny });
	square.push_back({ mxx, mxy });

	for (int i = 0; i < 4; i++)
	{
		if (find(input.begin(), input.end(), square[i]) == input.end())
		{
			cout << square[i].first << " " << square[i].second << "\n";
		}
	}
}