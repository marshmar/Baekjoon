#include<iostream>
#include<string>

using namespace std;

// w: goal team
// O: team One
// T: team Two
// oSum : team one winning time(sec)
// tSume : team two winning time(sec)

int n, w, O, T, oSum, tSum;
string s, prevT;

string print(int time)
{
	string m = "00" + to_string(time / 60);
	string s = "00" + to_string(time % 60);
	return m.substr(m.size() - 2, 2) + ":" + s.substr(s.size() - 2, 2);
}

int changeTimeToInt(string i)
{
	return atoi(i.substr(0, 2).c_str()) * 60 + atoi(i.substr(3, 2).c_str());
}

void solve(int& sum, string s)
{
	sum += (changeTimeToInt(s) - changeTimeToInt(prevT));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> w >> s;
		if (O > T)solve(oSum, s);
		else if (T > O)solve(tSum, s);
		w == 1 ? O++ : T++;
		prevT = s;
	}

	if (O > T)solve(oSum, "48:00");
	else if (T > O)solve(tSum, "48:00");

	cout << print(oSum) << "\n";
	cout << print(tSum) << "\n";
}