#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;
using ipq = priority_queue<pair<int, int>>;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    unordered_map<string, int> um;
    unordered_map<string, ipq> songs;
    priority_queue<pair<int, string>> ppq;

    int s = int(genres.size());
    for (int i = 0; i < s; i++)
    {
        if (um[genres[i]])
            um[genres[i]] += plays[i];
        else
            um[genres[i]] = plays[i];

        if (songs.find(genres[i]) != songs.end())
        {
            songs[genres[i]].push({ plays[i], i });
        }
        else
        {
            songs.insert({ genres[i], {} });
            songs[genres[i]].push({ plays[i], i });
        }

    }

    for (auto& e : um)
    {
        ppq.push({ e.second, e.first });
    }

    while (ppq.size())
    {

        string cur = ppq.top().second;

        int cnt = 2;
        while (cnt > 0)
        {
            answer.push_back(songs[cur].top().second);
            songs[cur].pop();
            cnt--;
        }

        ppq.pop();
    }

    return answer;
}

int main()
{
    auto bestAlbum = solution({ "classic", "pop", "classic", "classic", "pop" }, { 500, 600, 150, 800, 2500 });
    for (auto& e : bestAlbum)
    {
        cout << e << " ";
    }
    cout << endl;
}