/*
* 1. 윷놀이 판을 코딩으로 나타내야 함.
* 2. 윷놀이 이동 알고리즘을 어떻게 해야하나.
* 3. 최댓값 찾는 법? 시간제한이 2초 -> 완탐으로 될지도
*/
#include<iostream>
using namespace std;

int a[10];

int l1[20], l2[20];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 10; i++)
		cin >> a[i];

	for (int i = 1; i < 21; i++)
		l1[i-1] = i * 2;


	return 0;
}