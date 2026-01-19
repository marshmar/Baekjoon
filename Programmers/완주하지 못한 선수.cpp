#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// participant cnt는 1이상 100'000 이하
// completion의 길이는 paticipant의 길이보다 1 작다.
// 참가자의 이름은 1개 이상 20개 이하의 알파벳 소문자로 이루어져 있다.
// 참가자 중에는 동명이인이 있을 수 있다.

// 완탐 -> 안됨 100000^2이기 때문에.
// nlogn은 되어야 함
string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	map<string, int> people;
	for (auto& name : completion)
	{
		if (people.find(name) != people.end())
			people[name]++;
		else
			people.insert({ name, 1 });
	}
	
	for (auto& name : participant)
	{
		if (people.find(name) != people.end())
		{
			if (people[name] != 0)
				people[name]--;
			else
				answer = name;
		}
		else
			answer = name;

		if (answer != "")
			break;
	}

	return answer;
}

int main()
{
	cout << solution({ "marina", "josipa", "nikola", "vinko", "filipa" }, { "josipa", "filipa", "marina", "nikola" }) << endl;
}