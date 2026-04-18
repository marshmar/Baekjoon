#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

/*
* 1. 문제 정의
* 이중우선순위큐를 구현하여, 입력 연산을 수행했을 때, 이중우선순위큐가 비어있는지 아닌지
* 확인하고 비어있으면 [0,0]을, 비어있지 않으면 [최댓값, 최솟값]을 리턴하는 함수를 구하자
* 
* 2. 예제 시뮬레이션
* 입력1: I 16 큐: 16, max:16/min:16
* 입력2: I -5643 큐: 16, -5643 max:16/min:-5643
* 입력3: D -1 큐에서 최솟값 삭제, 큐: 16 max: 16/ min: 16
* 입력4: D 1 큐에서 최대값 삭제, 큐: 
* 입력5: I 123 큐: 123 max:123/min:123
* 입력6: D -1 큐에서 최솟값 삭제, 큐: 
* 결론: 큐가 비어있어서 [0, 0]리턴
* 
* 3. 반복되는 행동 찾기
* 
* 4. 각 행동에서 "빠르게 필요한 것"이 무엇인지 찾기
* D가 들어왔을 때 최대값은 어떻게 찾고, 최솟값은 어떻게 찾을까?
* 
* 5. 의사코드 작성
* 우선순위 큐 2개, 최대힙, 최소힙
* 개수를 기록할 map
* 오퍼레이션 배열을 순회
*   if(연산 == I:)
*   {
*       최대힙과 최소힙에 원소 삽입
*       map에 원소 추가, map에 원소가 있으면 삭제 카운트 --;
*   }
*   else
    {
        if(data == 1)
        {
            이미 삭제된 원소가 아닐때 까지 원소 삭제(삭제 카운트 감소)
            최대힙에 있는 원소 삭제 및 카운트 감소
        }
*       else
        {
            이미 삭제된 원소가 아닐때 까지 원소 삭제(삭제 카운트 감소)
            최소힙에 있는 원소 삭제 및 카운트 감소
*       }
*   }
* 
* 최대힙을 돌면서, map에 기록된 개수가 0보다 크면 그냥 꺼내기, 아니면 최대값 기록
* 최소힙을 돌면서, map에 기록된 개수가 0이면 크면 그냥 꺼내기, 아니면 최솟값 기록
* 최대값과 최솟값을 리턴
* 
* 6. 의사코드를 코드로 번역
*/
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    map<int, int> deleteCounts;
    int maxData = 0, minData = 0;

    for (auto& e : operations)
    {
        string operation = e.substr(0, 1);
        int data = stoi(e.substr(2).c_str());

        if (operation == "I")
        {
            maxHeap.push(data);
            minHeap.push(data);
            if (deleteCounts[data] > 0)
                deleteCounts[data]--;
            
        }
        else
        {
            if (data == 1)
            {
                while (maxHeap.size() && deleteCounts[maxHeap.top()] > 0)
                {
                    deleteCounts[maxHeap.top()]--;
                    maxHeap.pop();
                }
                if (maxHeap.size())
                {
                    deleteCounts[maxHeap.top()]++;
                    maxHeap.pop();
                }
            }
            else
            {
                while (minHeap.size() && deleteCounts[minHeap.top()] > 0)
                {
                    deleteCounts[minHeap.top()]--;
                    minHeap.pop();
                }
                if (minHeap.size())
                {
                    deleteCounts[minHeap.top()]++;
                    minHeap.pop();;
                }

            }

        }
    }

    while (maxHeap.size())
    {
        if (deleteCounts[maxHeap.top()] > 0)
        {
            maxHeap.pop();
        }

        else
        {
            maxData = maxHeap.top();
            break;
        }
    }

    while (minHeap.size())
    {
        if (deleteCounts[minHeap.top()] > 0)
        {
            minHeap.pop();
        }
        else
        {
            minData = minHeap.top();
            break;
        }
    }

    answer.push_back(maxData);
    answer.push_back(minData);
    return answer;
}

int main()
{
    vector<string> operations
    {
        "I 16",
        "I -5643",
        "D -1",
        "D 1",
        "D 1",
        "I 123",
        "D -1",
    };
    //vector<string> operations
    //{
    //    "I -45",
    //    "I 653",
    //    "D 1",
    //    "I -642",
    //    "I 45",
    //    "I 97",
    //    "D 1",
    //    "D -1",
    //    "I 333",
    //};

    vector<int> ret = solution(operations);
    for (auto& e : ret)
    {
        cout << e << endl;
    }
}