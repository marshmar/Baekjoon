#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 정렬할 때 문자열이 수가 더 큰 수가 오른쪽으로 가게 정렬하면 해결되는 문제
bool compare(int& left, int& right)
{
    string stringLeft = to_string(left);
    string stringRight = to_string(right);

    string n1 = stringLeft + stringRight;
    string n2 = stringRight + stringLeft;

    return n1 > n2;
}

string solution(vector<int> numbers) {
    string answer = "";

    sort(numbers.begin(), numbers.end(), compare);

    for (auto& e : numbers)
        answer += to_string(e);

    if (answer[0] == '0')
        answer = "0";

    return answer;
}

int main()
{
    vector<int> input
    {
        6,
        10,
        2
    };
    cout << solution(input);
    return 0;
}