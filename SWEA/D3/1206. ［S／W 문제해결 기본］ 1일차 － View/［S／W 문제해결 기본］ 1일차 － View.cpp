#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <vector>
#include <algorithm>
using namespace std;
int T;

void runTest()
{
	int n;
	cin >> n;
	vector<int> info(n);
	for (int i = 0; i < n; i++)
	{
		cin >> info[i];
	}
	int res = 0;
	for (int i = 2; i < n - 2; i++)
	{
		int ldiff = min(info[i] - info[i - 1], info[i] - info[i - 2]);
		int rdiff = min(info[i] - info[i + 1], info[i] - info[i + 2]);
		int mindiff = min(ldiff, rdiff);
		if (mindiff > 0)
		{
			res += mindiff;
		}
	}
	cout << res << "\n";
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