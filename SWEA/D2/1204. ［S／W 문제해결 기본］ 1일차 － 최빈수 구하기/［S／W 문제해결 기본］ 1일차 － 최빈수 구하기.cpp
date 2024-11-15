#include <iostream>
#include <vector>
using namespace std;
int T;

void runTest()
{
	int scoreCnt[120] = { 0 };
	for (int i = 1; i <= 1000; i++)
	{
		int score;
		cin >> score;
		scoreCnt[score]++;
	}
	int maxIdx = 0;
	for (int i = 0; i <= 100; i++)
	{
		if (scoreCnt[i] >= scoreCnt[maxIdx]) maxIdx = i;
	}
	cout << maxIdx << "\n";
}

int main(int argc, char** argv)
{
	int test_case;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int temp;
		cin >> temp;
		cout << "#" << test_case << " ";
		runTest();
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}