#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
int T;

void runTest()
{
	int repeat;
	cin >> repeat;
	vector<int> land(100);
	for (int i = 0; i < 100; i++)
		cin >> land[i];
	for (int i = 1; i <= repeat; i++)
	{
		pair<vector<int>::iterator, vector<int>::iterator> it = minmax_element(land.begin(), land.end());
		if (abs(*it.first - *it.second) <= 1) break;
		else
		{
			(*it.first)++;
			(*it.second)--;
		}
	}
	pair<vector<int>::iterator, vector<int>::iterator> it = minmax_element(land.begin(), land.end());
	cout << *it.second - *it.first << "\n";
}

int main()
{
	for (int i = 1; i <= 10; i++)
	{
		cout << "#" << i << " ";
		runTest();
	}
	return 0;
}