#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int plus = 1;
        for (int i = digits.size()-1; i >= 0; i--)
        {
            digits[i] = digits[i] + plus;
            plus = digits[i] == 10 ? 1 : 0;
            digits[i] %= 10;
        }
        if (plus) digits.insert(digits.begin(), 1);

        return digits;
    }
};

int main()
{
    Solution sol;
    vector<int> digits{1,0,0,0,0 };
    vector<int> ret;    
    ret = sol.plusOne(digits);

    for (auto& e : ret)
    {
        cout << e << " ";
    }
}