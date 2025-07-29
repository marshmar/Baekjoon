#include<iostream>
#include<vector>
using namespace std;
using p_t = pair<int, int>;

int n, m, h;

bool map[31][20];
bool visited[31][20];

vector<p_t> l;
vector<vector<p_t>> lc;

void print()
{
	cout << "\n";
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n * 2 - 1; j++)
		{
			cout << visited[i][j];
		}
		cout << "\n";
	}
	cout << "\n";

	cout << "\n";
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n * 2 - 1; j++)
		{
			cout << map[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

int dfs(int y, int x)
{
	//cout << "y: " << y << " x: " << x << "\n";
	if (y == h)
	{
		//cout << "Dest: " << x << "\n";
		return x;
	}


	if (map[y][x - 1])
	{
		return dfs(y+1, x - 2);
	}
	else if (map[y][x + 1])
	{
		return dfs(y+1, x + 2);
	}
	else
		return dfs(y + 1, x);
}

void combi(int idx, vector<p_t>& temp, int ms)
{
	//cout << "ms: " << ms << "\n";
	if (temp.size() == ms)
	{
		lc.push_back(temp);
		return;
	}

	for (int i = idx + 1; i < l.size(); i++)
	{
		temp.push_back(l[i]);
		combi(i, temp, ms);
		temp.pop_back();
	}
}

bool check(vector<p_t>& temp)
{
	for (int i = 0; i < temp.size()-1; i++)
	{
		if (temp[i].first == temp[i + 1].first)
		{
			if (abs(temp[i].second - temp[i + 1].second) == 2)
				return false;
		}
	}

	if (temp[0].first == temp[temp.size() - 1].first)
	{
		if (abs(temp[0].second - temp[temp.size() - 1].second) == 2)
			return false;
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> h;

	if (m == 0)
		cout << 0 << "\n";
	else
	{
		int y, x;
		for (int i = 0; i < m; i++)
		{
			cin >> y >> x;
			map[y - 1][x * 2 - 1] = 1;
		}

		for (int i = 0; i <h; i ++)
		{
			for (int j = 0; j < n * 2 - 1; j += 2)
			{
				map[i][j] = 1;
			}
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 1; j < n * 2-1; j += 2)
			{
				if (j - 2 >= 0)
				{
					if(map[i][j - 2]) continue;
				}

				if (j + 2 < n * 2 - 1)
				{
					if (map[i][j + 2]) continue;
				}

				if (map[i][j]) continue;

				l.push_back({ i, j });
			}
		}
		//print();

		//for (auto& e : l)
		//{
		//	cout << e.first << " " << e.second << "\n";
		//}
		bool flag = true;
		int combisize = 1;
		int ret = -1;


		for (int i = 0; i < n * 2 - 1; i += 2)
		{
			//cout << "Start: " << i << "\n";
			if (i != dfs(0, i))
			{
				flag = false;
				break;
			}
		}

		if (flag)
		{
			cout << 0 << "\n";
		}
		else
		{
			while (true)
			{
				if (combisize > 3) break;

				vector<p_t> temp;
				lc.clear();
				combi(-1, temp, combisize);

				//cout << "combisize: " << combisize<< "\n";
				for (auto& c : lc)
				{
					if (!check(c)) continue;
					flag = true;
					for (auto& e : c)
					{
						//cout << "l y: " << e.first << " l x: " << e.second << "\n";
						map[e.first][e.second] = 1;
					}
					//print();

					for (int i = 0; i < n * 2 - 1; i += 2)
					{
						//cout << "Start: " << i << "\n";
						if (i != dfs(0, i))
						{
							flag = false;
							break;
						}

					}

					if (flag)
					{
						ret = combisize;
						break;
					}

					for (auto& e : c)
					{
						map[e.first][e.second] = 0;
					}
				}
				if (flag) break;
				combisize++;


				//cout << "\n";
			}

			cout << ret << "\n";
		}


	}
	return 0;
}