#include<iostream>
#include<algorithm>
using namespace std;

const int row = 9;
const int col = 9;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int board[row][col];
	int maxNum = 0, maxRow = 1, maxCol = 1;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			int input;
			std::cin >> input;
			if (maxNum < input)
			{
				maxNum = input;
				maxRow = i + 1;
				maxCol = j + 1;
			}
		}
	}

	cout << maxNum << "\n";
	cout << maxRow << " " << maxCol;

	return 0;
}