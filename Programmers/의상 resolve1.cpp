#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;
// 핵심 알고리즘: 각 의상 종류마다 입는 경우의 수 = 각 의상 종류의 의상 개수 + 1(안입는 경우)
// 각 의상 종류의 경우의 수를 곱하여 전체 집합을 구한 뒤에
// 모두 안입는 경우의 수 하나를 빼면 정답이 나온다.

int solution(vector<vector<string>> clothes)
{
	unordered_map<string, int> um;
	
	for (auto& clothe : clothes)
	{
		if (um[clothe[1]])
			um[clothe[1]]++;
		else
			um[clothe[1]] = 1;
	}

	int ret = 1;
	for (auto& e : um)
	{
		ret *= (e.second + 1);
	}

	return ret - 1;
}