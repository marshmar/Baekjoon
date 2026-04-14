#include<iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;

    int idx = 0;
    for (auto& e : progresses)
    {
        q.push(e);
    }

    int day = 1, cnt = 0;
    while (idx < progresses.size())
    {
        // 첫 번째 작업의 진행도가 100보다 커질 떄 까지 반복
        while ((q.front() + speeds[idx] * day) < 100)
        {
            day += 1;
        }
        
        // 작업도가 100이상인 작업을 모두 출력
        while (q.size() && (q.front() + speeds[idx] * day) >= 100)
        {
            q.pop();
            cnt++;
            idx++;
        }

        answer.push_back(cnt);
        cnt = 0;
    }
    return answer;
}

int main()
{
    vector<int> p{ 95, 90, 99, 99, 80, 99 };
    vector<int> s{ 1, 1, 1, 1, 1, 1 };

    vector<int> ret = solution(p, s);
    for (auto& e : ret)
        cout << e << " ";

    return 0;
}