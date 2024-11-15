#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T;

void runTest()
{
	vector<int> nums(10);
	for (int i = 0; i < 10; i++)
	{
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());
	int sum = 0;
	for (int i = 1; i < 9; i++)
	{
		sum += nums[i];
	}
	double avg = double(sum) / 8.0;
	cout << int(avg + 0.5f) << "\n";
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