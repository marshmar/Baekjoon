#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
using ti = tuple<int, int, int>;

// first: 작업 시간, second: 작업 요청 시간, third: 작업 번호
struct compare{
    bool operator()(ti& left, ti& right)
    {
        // 작업 시간이 같을 경우
        if (get<0>(left) == get<0>(right))
        {
            // 작업 요청 시간이 같을 경우
            if (get<1>(left) == get<1>(right))
            {
                // 작업 번호가 작은 것을 top으로 설정
                return get<2>(left) > get<2>(right);
            }
            // 작업 요청 시간이 빠른 것을 top 설정
            return get<1>(left) > get<1>(right);
        }
        // 작업 시간이 작은 것을 top으로 설정
        return get<0>(left) > get<0>(right);

    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0, curTime = 0;
    priority_queue<ti, vector<ti>, compare> pq, temp;

    for (int i = 0; i < jobs.size(); i++)
    {
        // 0: 작업이 요청되는 시간, 1: 작업 시간
        pq.push({ jobs[i][1], jobs[i][0], i });
    }

    while (pq.size())
    {
        int requestTime, workTime, index;
        tie(workTime, requestTime, index) = pq.top();
        pq.pop();

        // 현재 시간이 작업 요청시간보다 작은 겨우
        // == 작업이 아직 들어오지 않은 경우
        if (curTime < requestTime)
        {
            temp.push({ workTime, requestTime, index });
            continue;
        }
        else
        {
            curTime += workTime;
            answer += (curTime - requestTime);
            while (temp.size())
            {
                tie(workTime, requestTime, index) = temp.top();
                temp.pop();
                pq.push({ workTime, requestTime, index });
            }
        }

        cout << "현재 시간: " << curTime 
            << " 작업 요청시간: " << requestTime
            << " answer: " << answer
            << " 요청부터 소요 시간: " << curTime - requestTime
            << " 작업 시간: " << workTime
            << " 작업 번호: " << index << endl;
    }

    return answer / jobs.size();
}

int solution(vector<vector<int>> jobs)
{
    // 요청 시간 기준 정렬
    sort(jobs.begin(), jobs.end())
}


int main()
{
    vector<vector<int>> input
    {
        {0, 10},
        {2, 2},
        {100, 5}
    };

    cout << solution(input);
    return 0;
}