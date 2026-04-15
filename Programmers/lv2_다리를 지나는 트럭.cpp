#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> bridge;
    int answer = 0, curWeight = 0, truckIndex = 0;
    for (int i = 0; i < bridge_length; i++)
    {
        bridge.push(0);
    }

    while (truckIndex < truck_weights.size())
    {
        answer++;

        curWeight -= bridge.front();
        bridge.pop();

        if (curWeight + truck_weights[truckIndex] <= weight)
        {
            curWeight += truck_weights[truckIndex];
            bridge.push(truck_weights[truckIndex]);
            truckIndex++;
        }
        else
        {
            bridge.push(0);
        }
    }

    return answer + bridge_length;
}


int main()
{
    cout << solution(3, 10, {7, 2, 2}) << endl;
    return 0;
}