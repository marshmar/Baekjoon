#include<iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;


int solution(vector<int> priorities, int location) {
    int answer = 0;

    deque<pair<int, int>> dq;
    for (int i = 0; i < priorities.size(); i++)
    {
        dq.push_back({ priorities[i], i });
    }

    while (dq.size())
    {
        pair<int, int> p = dq.front();
        dq.pop_front();

        bool priorityHigh = false;
        for (auto& e : dq)
        {
            if (e.first > p.first)
            {
                priorityHigh = true;
            }
        }

        if (priorityHigh)
        {
            dq.push_back(p);
        }
        else
        {
            answer++;
            if (p.second == location)
            {
                break;
            }
        }
    }
    return answer;
}

int main()
{
    cout << solution({ 2, 1, 3, 2 }, 2);
    cout << endl;
    cout << solution({ 1, 1, 9, 1, 1, 1 }, 0);
    cout << endl;
}