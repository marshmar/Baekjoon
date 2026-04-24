#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int maxNum = 9'999'999;
bool primeNumber[maxNum + 4];
set<int> ret;

void era()
{
    for (int i = 0; i < maxNum + 4; i++)
        primeNumber[i] = true;

    primeNumber[0] = false;
    primeNumber[1] = false;

    for (int i = 2; i * i <= maxNum; i++)
    {
        if (primeNumber[i])
        {
            for (int j = i * i; j <= maxNum; j += i)
            {
                primeNumber[j] = false;
            }
        }

    }
}

void combi(int start, string& numbers, string& comb, int n, int k)
{
    if (comb.size() == k)
    {
        string temp = comb;
        sort(temp.begin(), temp.end());

        do {
            int number = stoi(temp);
            if (primeNumber[number])
                ret.insert(number);
        } while (next_permutation(temp.begin(), temp.end()));

        return;
    }
    for (int i = start + 1; i < n; i++)
    {
        comb.push_back(numbers[i]);
        combi(i, numbers, comb, n, k);
        comb.pop_back();
    }
}

int solution(string numbers) 
{
    era();
    string combString;
    for (int i = 0; i < numbers.size(); i++)
    {
        combi(-1, numbers, combString, numbers.size(), i + 1);
    }

    return ret.size();
}

int main()
{
    cout << solution("17") << endl;
    return 0;
}