/*
* 시간복잡도가 2의 40승 아닌가? 행 뒤집고 안뒤집고 20개, 열 뒤집고 안뒤집고 20개 -> 2의 40승
* 어떻게 시간복잡도를 줄일 수 있는가?
* 행만 뒤집고 각 열을 뒤집을 지 말지 생각하면 되는 로직이다. -> 2의 20승?
* 
*/
#include<iostream>
#include<bitset>
#include<string>
#include<climits>
using namespace std;

int n, ret = INT_MAX;
int alphas[41];

void solve(int idx)
{
	if (idx == n + 1)	// 행을 뒤집고 안뒤집고 끝까지 왔다(어떤거는 뒤집고 안뒤집고), 행만 뒤집으면 열의 최적해는 정해져 있다.
						// n+1까지 하는 이유는 n까지 하면 n행을 뒤집는 경우가 제외되기 때문
	{
		int sum = 0;
		for (int i = 1; i <= (1 << (n - 1)); i *= 2) // 1, 2, 4 숫자를 늘려가면서 체크
		{
			int cnt = 0;
			for (int j = 1; j <= n; j++)	// 열을 계속 체크하는 로직
			{
				if (alphas[j] & i) cnt++;	
			}
			sum += min(cnt, n - cnt);	// cnt는 현재 상태의 T의 개수, n-cnt는 뒤집은 상태의 T의 개수(N은 행의 개수이자 열의 개수 이기에
										// 뒤집은 카운트은 n-cnt가 됨.
		}

		ret = min(ret, sum);
		return;
	}

	solve(idx + 1);	// 행을 안뒤집고 호출
	alphas[idx] = ~alphas[idx]; //NOTE: a = 4(HHT) -> 뒤집으면 -5가 나옴, 왜냐하면 앞에도 비트가 채워져 있기 때문, 그러나 우리는 3부분만 사용
	solve(idx + 1); //  행을뒤집고 호출
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	string s;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		int alpha = 1;
		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] == 'T')  alphas[i] |= alpha;	// 문자로 이루어진 배열을 숫자로 표현, HHT는 4로 표현 가능(1, 2, 4라고 했을 때 4만 true), HTT는 6으로 표현 가능(2 + 4)
			alpha *= 2;
		}
	}

	solve(1);
	cout << ret << "\n";
	return 0;
}