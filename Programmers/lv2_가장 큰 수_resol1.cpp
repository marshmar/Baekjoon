#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string& left, string& right)
{
    return left + right > right + left;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> numStrings;
    for (auto& e : numbers)
    {
        numStrings.push_back(to_string(e));
    }

    sort(numStrings.begin(), numStrings.end(), compare);
    for (auto& numString : numStrings)
    {
        cout << numString << endl;;
        answer += numString;
    }


    if (answer[0] == '0')
        answer = "0";

    return answer;
}

int main()
{
    vector<int> input
    {
        3, 30, 34, 5, 9
    };

    string ret = solution(input);
    cout << ret;
}