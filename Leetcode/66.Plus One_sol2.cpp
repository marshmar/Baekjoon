#include<iostream>
#include<vector>
using namespace std;

/// <summary>
/// 내 코드는 반복문 끝까지 돌아야해서 무조건 O(N)이었지만,
/// 조기 종료를 통해 평균 O(1)로 줄일 수 있다.
/// 9999 처럼 모든 자리가 9인 최악의 경우에만 O(N)이 된다.
/// </summary>
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int plus = 1;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (digits[i] < 9)
            {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }

        // 여기까지 왔다면 모든 자리가 9인것.
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main()
{
    Solution sol;
    vector<int> digits{ 1,0,0,0,0 };
    vector<int> ret;
    ret = sol.plusOne(digits);

    for (auto& e : ret)
    {
        cout << e << " ";
    }
}