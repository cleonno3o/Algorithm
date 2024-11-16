#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int T;
int n, limit;
vector<int> score;
vector<int> cal;

void runTest()
{
	cin >> n >> limit;
	vector<int> table(limit + 1);
	score = cal = vector<int>(n);
	for (int i = 0; i < n; i++)
		cin >> score[i] >> cal[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = limit; j >= cal[i]; j--)
		{
			table[j] = max(table[j], table[j - cal[i]] + score[i]);
		}
	}
	cout << table[limit] << "\n";
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		cout << "#" << test_case << " ";
		runTest();
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}