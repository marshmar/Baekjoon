#include<iostream>
#include<string>
#include<map>

//#include <bits/stdc++.h>
using namespace std;
map<char, int> alphabets;

void Solution(string s)
{
    for (char c = 'a'; c <= 'z'; c++)
    {
        alphabets.insert({ c, 0 });
    }

    for (char c : s)
    {
        alphabets[c]++;
    }

    for(auto& e : alphabets)
    {
        cout << e.second << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    Solution(s);
    return 0;
}
