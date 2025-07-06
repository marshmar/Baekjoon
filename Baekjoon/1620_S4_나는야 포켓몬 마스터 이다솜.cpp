#include<iostream>
#include<map>
#include<string>

using namespace std;

map<string, int> enc;
int N, M;

bool comp(string& ori, string& comp)
{
	return ori == comp;
}

int main()
{
	cin >> N >> M;

	string name;
	for (int i = 0; i < N; i++)
	{
		cin >> name;
		enc[name] = i;
	}

	string temp;
	for (int i = 0; i < M; i++)
	{
		cin >> temp;
		if (atoi(temp.c_str()))
		{
			cout << enc.find()
		}
		else 
		{
			cout << enc[temp] << endl;
		}
	}
	return 0;
}