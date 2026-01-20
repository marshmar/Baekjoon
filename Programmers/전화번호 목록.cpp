#include<iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_set>
using namespace std;

// phone_book의 길이는 최대 1'000'000
// 각 전화번호의 길이는 1이상 20 이하
// case1. 완탐
// phone_book을 돌면서 하나씩 비교 -> O(n^2) -> Time out

// case2. 집합에다가 넣어두고 사용한다면.. 
//bool solution(vector<string> phone_book)
//{
//	set<string> phoneNumbers;
//
//	// nlogn
//	for (auto& phoneNum : phone_book)
//	{
//		phoneNumbers.insert(phoneNum);
//	}
//
//	// nlogn(n이 최대 2천만 -> 100만 * 20) -> 4억번 계산 -> 사실상 time out
//	for (auto& phoneNum : phone_book)
//	{
//		for (int charIndex = 0; charIndex < phoneNum.length(); charIndex++)
//		{
//			string substr = phoneNum.substr(0, charIndex);
//			if (phoneNumbers.find(substr) != phoneNumbers.end())
//			{
//				return false;
//			}
//		}
//	}
//
//	return true;
//}

// case3. vector를 정렬하면 사전순으로 정렬되는데 그러면 다음거의 부분 집합에 현재 자신이 있는지만 확인하면 된다.
//bool solution(vector<string> phone_book)
//{
//	sort(phone_book.begin(), phone_book.end());
//
//	for (int index = 0; index < phone_book.size() - 1; index++)
//	{
//		if (phone_book[index + 1].find(phone_book[index]) == 0) {
//			return false;
//		}
//	}
//	return true;
//}

// case4. unordered set을 사용하면 삽입에 O(1)이 된다.
bool solution(vector<string> phone_book)
{
	unordered_set<string> phoneNumbers;

	for (auto& phoneNum : phone_book)
	{
		phoneNumbers.insert(phoneNum);
	}

	for (auto& phoneNum : phone_book)
	{
		for (int charIndex = 0; charIndex < phoneNum.length(); charIndex++)
		{
			string substr = phoneNum.substr(0, charIndex);
			if (phoneNumbers.find(substr) != phoneNumbers.end())
			{
				return false;
			}
		}
	}

	return true;
}
int main()
{
	cout << solution({ "119", "97674223", "1195524421" });
	return 0;
}