#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (auto& command : commands)
    {
        vector<int> temp;
        int start = command[0] -1;
        int end = command[1] -1;
        int dataIndex = command[2] -1;
        
        // 데이터를 필요한 부분만 복사하기
        for (int i = start; i <= end; i++)
        {
            temp.push_back(array[i]);
        }

        sort(temp.begin(), temp.end());
        int ret = temp[dataIndex];
        answer.push_back(ret);
    }
    return answer;
}

int main()
{
    vector<int> array
    {
        1, 5, 2, 6, 3, 7, 4
    };

    vector<vector<int>> commands
    {
        {2, 5, 3},
        {4, 4, 1},
        {1, 7, 3},
    };

    vector<int> ret = solution(array, commands);
    for (auto& e : ret)
    {
        cout << e << " ";
    }
}