#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T;

void runTest()
{
	int n, k;
	cin >> n >> k;
	vector<float> score(n);
	int targetIdx;
	for (int i = 0; i < n; i++)
	{
		int mid, fin, quiz;
		cin >> mid >> fin >> quiz;
		score[i] = mid * 0.35f + fin * 0.45f + quiz * 0.2f;
		if (i + 1 == k)
			targetIdx = i;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (score[i] > score[targetIdx]) cnt++;
	}
	string table[] = { "A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0" };
	if ((cnt + 1) % (n / 10) != 0) 
		cout << table[(cnt + 1) / (n / 10)] << "\n";
	else 
		cout << table[(cnt + 1) / (n / 10) - 1] << "\n";
}

int main(int argc, char** argv)
{
	int test_case;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cout << "#" << test_case << " ";
		runTest();
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}