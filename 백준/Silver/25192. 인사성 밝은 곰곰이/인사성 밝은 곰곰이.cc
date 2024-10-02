#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	int n;
	cin >> n;
	map<string, int> m;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		if (str == "ENTER")
			m.clear();
		else
		{
			if (m[str] == 0)
			{
				m[str]++;
				cnt++;
			}
		}
	}
	cout << cnt;
}