#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int T;

void runTest()
{
	int t;
	cin >> t;
	deque<int> pw;
	for (int i = 0; i < 8; i++)
	{
		int temp;
		cin >> temp;
		pw.push_back(temp);
	}
	bool isRun = true;
	while (isRun)
	{
		for (int i = 1; i <= 5; i++)
		{
			int n = pw.front();
			pw.pop_front();
			n -= i;
			if (n <= 0)
			{
				n = 0;
				pw.push_back(n);
				isRun = false;
				break;
			}
			else
				pw.push_back(n);
		}
	}
	while (!pw.empty())
	{
		cout << pw.front() << " ";
		pw.pop_front();
	}
}

int main(int argc, char** argv)
{
	for (int test_case = 1; test_case <= 10; ++test_case)
	{
		cout << "#" << test_case << " ";
		runTest();
		cout << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}