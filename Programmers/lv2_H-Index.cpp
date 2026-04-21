#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 문제정의: n개의 논문중에서 h번이상 인용된 논문이 h개 이상이고, 나머지 논문이 h번이하
// 인용되는 h인덱스의 최대값을 구하라

// 입력 3 0 6 1 5
// 정렬 0 1 3 5 6
// 3번이상 인용된 논문 3, 3번이하 인용된 논문 3개 그래서 h인덱스는 3

// 핵심 알고리즘
// h값을 정하고 배열에서 h번 이상인게 몇 개인지만 알면 되는거 아닌가?
// h값을 찾는건 이분탐색(logn)
// h번 이상인걸 찾으면 O(n) -> O(nlogn)

bool IsMoreThanHIndex(vector<int>& citations, int hIndex)
{
    int moreCnt = 0;
    for (auto& e : citations)
    {
        if (e >= hIndex)
            moreCnt++;
    };
    return moreCnt >= hIndex;
}

int solution(vector<int> citations) {
    int answer = 0, left = 0, right = 10'000, mid = 0;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (IsMoreThanHIndex(citations, mid))
        {
            answer = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }

    return answer;
}

int main()
{
    vector<int> input
    {
        0,
        0,
        0,
        0,
        0
    };

    cout << solution(input) << endl;
}