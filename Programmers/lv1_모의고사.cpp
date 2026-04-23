#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

vector<int> oneSolutions{ 1, 2, 3, 4, 5 };
vector<int> twoSolutions{ 2, 1, 2, 3, 2, 4, 2, 5 };
vector<int> threeSolutions{ 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int oneCount = 0, twoCount = 0, threeCount = 0;
    for (int i = 0; i < answers.size(); i++)
    {
        if (oneSolutions[i % oneSolutions.size()] == answers[i])
            oneCount++;
        if (twoSolutions[i % twoSolutions.size()] == answers[i])
            twoCount++;
        if (threeSolutions[i % threeSolutions.size()] == answers[i])
            threeCount++;
    }

    priority_queue<pair<int, int>> pq;
    pq.push({ oneCount, 1 });
    pq.push({ twoCount, 2 });
    pq.push({ threeCount, 3 });

    int maxCnt, index;
    do
    {
        tie(maxCnt, index) = pq.top();
        pq.pop();
        answer.push_back(index);
    } while (pq.size() && pq.top().first == maxCnt);

    sort(answer.begin(), answer.end());
    return answer;
}

vector<int> solutionOther(vector<int> answers) {
    vector<int> answer;

    int oneCount = 0, twoCount = 0, threeCount = 0;
    for (int i = 0; i < answers.size(); i++)
    {
        if (oneSolutions[i % oneSolutions.size()] == answers[i])
            oneCount++;
        if (twoSolutions[i % twoSolutions.size()] == answers[i])
            twoCount++;
        if (threeSolutions[i % threeSolutions.size()] == answers[i])
            threeCount++;
    }
    
    vector<int> temp{oneCount, twoCount, threeCount};
    int maxCnt = *max_element(temp.begin(), temp.end());
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i] == maxCnt)
        {
            answer.push_back(i + 1);
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{
    vector<int> input
    {
        1, 3, 2, 4, 2
    };

    vector<int> ret = solutionOther(input);

    for (auto& e : ret)
        cout << e << " ";
}