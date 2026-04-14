#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

bool compare(pair<int, int>& left, pair<int, int>& right)
{
    if (left.first == right.first)
    {
        return left.second < right.second;
    }
    return left.first > right.first;
}

// 벡터랑 map만 사용해서 풀어보기
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> GenrePlaySumMap;
    map<string, vector<pair<int, int>>> GenrePlayMap;
    for (int i = 0; i < genres.size(); i++)
    {
        GenrePlaySumMap[genres[i]] += plays[i];
        GenrePlayMap[genres[i]].push_back({ plays[i], i });
    }
    
    vector<pair<int, string>> GenrePlaySumVec;
    for (auto& e : GenrePlaySumMap)
    {
        GenrePlaySumVec.push_back({e.second, e.first});
    }
    sort(GenrePlaySumVec.begin(), GenrePlaySumVec.end(), greater<pair<int, string>>());

    for (auto& e : GenrePlaySumVec)
    {
        auto& genre = e.second;
        sort(GenrePlayMap[genre].begin(), GenrePlayMap[genre].end(), compare);

        answer.push_back(GenrePlayMap[genre][0].second);
        if (GenrePlayMap[genre].size() >= 2)
        {
            answer.push_back(GenrePlayMap[genre][1].second);
        }
    }

    return answer;
}

int main()
{
    vector<string> g{ "classic", "pop", "classic", "classic", "pop"};
    vector<int> p{ 500, 600, 150, 800, 2500 };

    vector<int> ret = solution(g, p);
    for (auto& e : ret)
    {
        cout << e << " ";
    }
    return 0;
}