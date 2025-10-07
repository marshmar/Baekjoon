#include<iostream>
using namespace std;
using p_t = pair<int, int>;
const int ms = 16;
int n, m[ms][ms], ret;

bool checkHorizontal(p_t pos)
{
	int ny = pos.first;
	int nx = pos.second + 1;

	if (ny < 0 || ny >= n || nx < 0 || nx >= n) return false;
	if (m[ny][nx] == 1) return false;

	return true;
}

bool checkVertical(p_t pos)
{
	int ny = pos.first + 1;
	int nx = pos.second;

	if (ny < 0 || ny >= n || nx < 0 || nx >= n) return false;
	if (m[ny][nx] == 1) return false;

	return true;
}

bool checkDiagonal(p_t pos)
{
	int ny = pos.first + 1;
	int nx = pos.second + 1;

	if (ny < 0 || ny >= n || nx < 0 || nx >= n) return false;
	if (m[ny][nx] == 1 || m[ny-1][nx] == 1 || m[ny][nx-1] == 1) return false;

	return true;
}

// 가로: 0, 세로: 1, 대각선: 2
void solve(int type, p_t pos)
{
	if (pos.first == n - 1 && pos.second == n - 1)
	{
		ret++;
		return;
	}
	
	int y = pos.first;
	int x = pos.second;

	switch (type)
	{
	case 0:
		if (checkHorizontal(pos))
			solve(0, { y, x + 1 });
		if (checkDiagonal(pos))
			solve(2, { y + 1, x + 1 });
		break;
	case 1:
		if (checkVertical(pos))
			solve(1, { y+1, x });
		if (checkDiagonal(pos))
			solve(2, { y + 1, x + 1 });
		break;
	case 2:
		if (checkHorizontal(pos))
			solve(0, { y, x + 1 });
		if (checkVertical(pos))
			solve(1, { y + 1, x });
		if (checkDiagonal(pos))
			solve(2, { y + 1, x + 1 });
		break;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> m[i][j];

	solve(0, { 0, 1 });
    cout << ret << "\n";
	return 0;
}