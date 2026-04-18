#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0, idx = 0, curTime = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    sort(jobs.begin(), jobs.end());

    int requestTime, workTime;
    while (idx < jobs.size() || pq.size())
    {
        while (idx < jobs.size() && curTime >= jobs[idx][0])
        {
            pq.push({ jobs[idx][1], jobs[idx][0] });
            idx++;
        }

        if (pq.empty())
        {
            curTime = jobs[idx][0];
        }
        else
        {
            tie(workTime, requestTime) = pq.top();
            pq.pop();
            curTime += workTime;
            answer += (curTime - requestTime);
        }
    }

    return answer / jobs.size();
}

int main()
{
    vector<vector<int>> input
    {
        {0, 3},
        {1, 9},
        {3, 5},
    };

    cout << solution(input) << endl;
}