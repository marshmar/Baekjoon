#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

/*
* 스택에 가격을 넣음, 인덱스 정보도 같이 넣어야 겠네
* 다음 가격이 만약 스택에 제일 위에 있는 가격보다 작으면 ex) 1 2 3 2 3일때
* 1,2,3이 스택에 있고 2가 들어오면 3을 빼고 3에 기록해
*/
vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<pair<int, int>> s;

    s.push({ prices[0], 0 });
    for (int i = 1; i < prices.size(); i++)
    {
        while (s.size() && prices[i] < s.top().first)
        {
            int time = i - s.top().second;
            answer[s.top().second] = time;
            s.pop();
        }
        s.push({ prices[i], i });
    }

    while (s.size())
    {
        int index = s.top().second;
        answer[index] = prices.size() - index - 1;
        s.pop();
    }
    return answer;
}

vector<int> solutionTwo(vector<int> prices)
{
    vector<int> answer(prices.size());
    stack<int> s;

    for (int i = 0; i < prices.size(); i++)
    {
        while (s.size() && prices[s.top()] > prices[i])
        {
            answer[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }
    while (s.size())
    {
        answer[s.top()] = prices.size() - s.top() - 1;
        s.pop();
    }

    return answer;
}

int main()
{
    vector<int> input{1, 2, 3, 1, 1};
    vector<int> ret = solution(input);

    for (auto& e : ret)
        cout << e << " ";
    return 0;
}