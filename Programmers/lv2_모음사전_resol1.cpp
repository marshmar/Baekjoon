#include<iostream>
#include<vector>
#include<string>
using namespace std;

string Dictionary = "AEIOU";
int cnt = -1, ret = 0;
const int maxWordLength = 5;

void dfs(string word, string target)
{
    cnt++;
    if (word == target)
    {
        ret = cnt;
        return;
    }
    if (word.length() >= maxWordLength)
    {
        return;
    }
    for (int i = 0; i < Dictionary.length(); i++)
    {
        dfs(word + Dictionary[i], target);
    }

}

int solution(string word) {
    dfs("", word);
    return ret;
}

int main()
{
    cout << solution("AAAAE") << endl;
	return 0;
}