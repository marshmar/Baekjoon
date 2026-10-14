#include<iostream>
#include<vector>
//#include <bits/stdc++.h>
using namespace std;

int N, M, K; // N: 수의 개수, M: 수의 변경이 일어나는 횟수, K: 구간 합을 구하는 횟수
vector<long long> tree, nums;

void update(int index, long long value)
{
	while (index < tree.size())
	{
		tree[index] += value;
		index += (index & -index);
	}
}

long long sum(int index)
{
	long long ret = 0;
	while (index > 0)
	{
		ret += tree[index];
		index -= (index & -index);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N >> M >> K;
	// 펜윅트리, 숫자 벡터 초기화 및 N개의 수 저장
	tree.resize(N+1, 0); 
	nums.resize(N+1, 0);
	for (int i = 1; i <= N; i++)
	{
		cin >> nums[i];
	}

	for (int i = 1; i <= N; i++)
	{
		update(i, nums[i]);
	}

	// M + K번 동안 a, b, c입력을 받는데 
	// a가 1이면 b번째 수를 c로 바꾸고,
	// a가 2이면 b번째 수부터 c번째 수까지 합을 구하여 출력
	long long a, b, c;
	for (int i = 0; i < M + K; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			update(b, c - nums[b]);
			nums[b] = c;
		}
		else
		{
			cout << sum(c) - sum(b-1) <<endl;
		}
	}

	return 0;
}