#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// 수도코드
// 2개의 우선순위 큐, 1개의 map
// 
// 큐에 주어진 숫자를 삽입-> 최대힙과 최소힙에 삽입
// map에 deleteCount 감소
// D 1: 
// 이미 삭제된 원소인지 확인
// 최대힙에서 원소 제거, deleteCount 1 증가
// 
// D -1: 
// 이미 삭제된 원소인지 확인
// 최소힙에서 원소 제거, deleteCount 1 증가
// 
// 최대힙과 최소힙을 돌면서 이미 삭제된 원소인지 확인하고
// 아니면 answer에 push

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    map<int, int> deleteCnts;
    
    for (auto& operation : operations)
    {
        string op = operation.substr(0, 1);
        int data = stoi(operation.substr(2));

        if (op == "I")
        {
            maxHeap.push(data);
            minHeap.push(data);
            if (deleteCnts[data] > 0) 
                deleteCnts[data]--;
        }
        else
        {
            if (data == 1)
            {
                while (maxHeap.size() && deleteCnts[maxHeap.top()] > 0)
                {
                    maxHeap.pop();
                }

                if (maxHeap.size())
                {
                    deleteCnts[maxHeap.top()]++;
                    maxHeap.pop();
                }
            }
            else
            {
                if (minHeap.size())
                {
                    while (minHeap.size() && deleteCnts[minHeap.top()] > 0)
                    {
                        minHeap.pop();
                    }

                    if (minHeap.size())
                    {
                        deleteCnts[minHeap.top()]++;
                        minHeap.pop();
                    }
                }
            }
        }
    }

    while (maxHeap.size() && deleteCnts[maxHeap.top()] > 0)
    {
        maxHeap.pop();
    }


    while (minHeap.size() && deleteCnts[minHeap.top()] > 0)
    {
        minHeap.pop();
    }

    if (maxHeap.empty() || minHeap.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(maxHeap.top());
        answer.push_back(minHeap.top());
    }

    return answer;
}

int main()
{
    vector<string> input
    {
        //"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1",
        "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333",
    };

    vector<int> ret = solution(input);
    for (auto& e : ret)
        cout << e << " ";
    return 0;
}