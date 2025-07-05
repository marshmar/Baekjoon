#include<iostream>
#include<vector>

using namespace std;

int N, K;
vector<int> ret(100004, 0);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	int num;
	for (int i = 1; i <= N; i++)    
	{
		cin >> num;
		ret[i] = ret[i - 1] + num;
	}


	int max;
	max = ret[K];

	for (int i = K+1; i <= N; i++)
	{
		if (ret[i] - ret[i - K] > max)
			max = ret[i] - ret[i - K];
	}

	cout << max << endl;
	return 0;
}