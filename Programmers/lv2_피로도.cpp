#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
	sort(dungeons.begin(), dungeons.end());
    
	vector<int> lessTired(dungeons.size());  

    // 순열로 던전을 탐색하면서
    while (next_permutation(dungeons.begin(), dungeons.end()))
    {
        int tired = k, maxRoom = 0;
        for (auto& e : dungeons)
        {
            if (tired >= e[0])
            {
                tired -= e[1];
                maxRoom++;
            }
            else
            {
                break;
            }
        }
        if (answer < maxRoom)
            answer = maxRoom;

    }
    return answer;
}

int main()
{
	vector<vector<int>> dungeons = { {80, 20}, {50, 40}, {30, 10} };
	cout << solution(80, dungeons);

    return 0;
}