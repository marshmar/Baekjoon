#include <vector>
#include <set>
using namespace std;

// 포켓몬 N마리 중에서 N/2마리를 가져갈 수 있다.
// NUMS는 1이상 10000이하의 자연수, 항상 짝수임
// 폰켓몬의 종류 번호는 1 이상 200000이하의 자연수
// 같은 것이 있는 것중에서 조합

int solution(vector<int> nums)
{
	int answer = 0;
	set<int> types;

	for (auto& num : nums)
	{
		if (types.find(num) == types.end())
			types.insert(num);
	}

	int maxChoiceCnt = nums.size() / 2;

	if (types.size() <= maxChoiceCnt)
		answer = types.size();
	else
		answer = maxChoiceCnt;

	return answer;
}