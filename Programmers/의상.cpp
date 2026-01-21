#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using ll = long long;
using namespace std;

// 결국엔 경우의 수: 입거나 안입거나
int solution(vector<vector<string>> clothes)
{
	unordered_map<string, int> m;
	for (auto& clothe : clothes)
	{
		if (m[clothe[1]])
			m[clothe[1]] += 1;
		else
			m[clothe[1]] = 1;
	}
	
	ll ret = 1;
	for (auto& e : m)
	{
		ret *= (ll)(e.second + 1);
	}

	return ret - 1;
}

int main()
{
	cout << solution({ {"yellow_hat", "headgear"},{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} }) << endl;
}

/*
* 헤드기어 2종류, 아이웨어 1종류의 경우를 예시로 문제 해설.
* 
* 각 종류마다 (1번, 2번, 안입음) 이렇게 선택이 가능
* 그렇게 헤드기어를 선택하는 경우의 수(1번, 2번, 안입음) 3가지 * 아이웨어를 선택하는 경우의 수(1번, 안입음) 2가지 를 곱하면 전체 경우의 수가 나오는데
* 여기서 둘 다 안입음을 선택하는 경우의 수는 제외해야 하므로 -1을 해주면 정답이 됨.
*/

