#include<iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// 전체면적: brown + yellow
// yellow = (width-2) * (height-2)
// brown = S - y;
// 
// 전체면적 S에 대해 도출할 수 있는 Width와 height를 전부 탐색한 다음 
// 인자로 들어온 yellow와 brown이 맞는지 판단
// 

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    // 전체면적: 갈색 격자 개수 + 노란색 격자 개수
    int Area = brown + yellow;

    // 높이는 최소 3이상, 세로가 가로보다 작기 떄문에 전체 면적의 약수까지만 검사
    for (int height = 3; height <= sqrt(Area); height++)
    {
        if (Area % height == 0)
        {
            // 가로 길이 계산
            int width = Area / height;

            // 노란색 격자 면적 = (width-2) * (height-2)
            if ((width - 2) * (height - 2) == yellow)
            {
                answer.push_back(width);
                answer.push_back(height);
            }
        }

    }
    return answer;
}

int main()
{
    vector<int>  ret;
    ret = solution(10, 2);

    for (auto& e : ret)
        cout << e << " ";

    return 0;
}