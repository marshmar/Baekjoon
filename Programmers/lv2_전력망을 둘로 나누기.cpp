#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
const int nCnt = 104;   // 송전탑 최대 개수
bool visited[nCnt]{ 0 };

vector<vector<int>> powerGrids(nCnt);


int dfs(vector<int> wire)
{
    int cnt = 1;
    for (auto& e : wire)
    {
        if (visited[e])
        {
            continue;
        }
        visited[e] = true;
        cnt += dfs(powerGrids[e]);
    }

    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;

    // 송전탑을 연결 리스트 형태로 저장(양방향 연결리스트)
    for (auto& wire : wires)
    {
        powerGrids[wire[0] - 1].push_back(wire[1] - 1);
        powerGrids[wire[1] - 1].push_back(wire[0] - 1);
    }
    

    for (int i = 0; i < wires.size(); i++)
    {
        int v1 = wires[i][0] - 1;
        int v2 = wires[i][1] - 1;

        // wires에서 하나의 전력망 끊기(다시 사용해야 하기에 끊었다가 다시 복구)
        powerGrids[v1].erase(find(powerGrids[v1].begin(), powerGrids[v1].end(), v2));
        powerGrids[v2].erase(find(powerGrids[v2].begin(), powerGrids[v2].end(), v1));

        // visited 배열 초기화
        memset(visited, 0, nCnt);

        // 전력망 개수를 계산할 vector 선언
        vector<int> result;

        // 각각의 원소에서 dfs 돌기(dfs 한 바퀴 돌 때마다 result + 1)
        for (int index = 0; index < n; index++)
        {
            if (visited[index]) continue;
            visited[index] = true;
            result.push_back(dfs(powerGrids[index]) + 1);
        }

        cout << "result: ";
        for (auto& e : result)
        {
            cout << e << " ";
        }
        cout << endl;

        // result와 answer를 비교해서 max 값 저장
        answer = min(answer, abs(result[0] - result[1]));

        // 전력망 복구
        powerGrids[v1].push_back(v2);
        powerGrids[v2].push_back(v1);
    }


    return answer;
}

int main()
{
    vector<vector<int>> wires{ {1,3},{2,3},{3,4},{4,5},{4,6},{4,7},{7,8},{7,9} };
    
    cout << solution(9, wires);
    return 0;
} 
