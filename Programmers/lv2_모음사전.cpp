#include<iostream>
#include<vector>

using namespace std;

string Dictionary = "AEIOU";
int cnt = 0;
int answer = 0;

void dfs(string word, string target)
{
    cnt++;
    if (word == target)
    {
        answer = cnt;
        return;
    }

    if (word.length() >= 5)
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
    return answer-1;
}

int main()
{
    cout << solution("A") << endl;
	return 0;
}