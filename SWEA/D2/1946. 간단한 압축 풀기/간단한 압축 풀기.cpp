#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T;

void runTest()
{
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		char alpha;
		int nn;
		cin >> alpha >> nn;
		for (int j = 1; j <= nn; j++)
		{
			cout << alpha;
			cnt++;
			if (cnt == 10)
			{
				cnt = 0;
				cout << '\n';
			}
		}
	}
	cout << "\n";
}

int main(int argc, char** argv)
{
	int test_case;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cout << "#" << test_case << "\n";
		runTest();
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}