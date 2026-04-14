#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(pair<int, int>& a, pair<int, int>& b)
    {
        if (a.first == b.first)
        {
            return a.second > b.second;
        }
        return a.first < b.first;
    }
};
using pi = pair<int, int>;
using pq = priority_queue<pi, vector<pi>, cmp>;


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    map<string, pq> GenrePlayIndexMap;
    map<string, int> GenrePlayMap;
    priority_queue<pair<int, string>> PlayGenrePQ;

    for (int i = 0; i < genres.size(); i++)
    {
        GenrePlayIndexMap[genres[i]].push({ plays[i], i });
        GenrePlayMap[genres[i]] += plays[i];
    }

    for (auto& e : GenrePlayMap)
    {
        PlayGenrePQ.push({ e.second, e.first });
    }

    while (PlayGenrePQ.size())
    {
        string genre = PlayGenrePQ.top().second;
        PlayGenrePQ.pop();
        answer.push_back(GenrePlayIndexMap[genre].top().second);
        GenrePlayIndexMap[genre].pop();
        if (GenrePlayIndexMap[genre].size())
        {
            answer.push_back(GenrePlayIndexMap[genre].top().second);
            GenrePlayIndexMap[genre].pop();
        }
    }

    return answer;
}

int main()
{
    vector<string> g{ "classic", "pop", "classic", "classic", "pop" };
    vector<int> p{ 500, 600, 150, 800, 2500 };

    vector<int> ret = solution(g, p);
    for (auto& e : ret)
    {
        cout << e << " ";
    }
    return 0;
}