#include<iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

    while (pq.size() && pq.top() < K)
    {
        if (pq.size() < 2)
        {
            return -1;
        }

        int lowestScoville = pq.top();
        pq.pop();
        int secondScoville = pq.top();
        pq.pop();
  
        int newScoville = lowestScoville + secondScoville * 2;
        pq.push(newScoville);

        answer++;
    }
    return answer;
}

int main()
{
    vector<int> input{ 1, 2, 3, 9, 10, 12 };
    cout << solution(input, 7);
    return 0;
}