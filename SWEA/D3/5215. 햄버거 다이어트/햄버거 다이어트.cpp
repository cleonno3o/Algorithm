#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int T;
int n, limit;
vector<int> ch;
vector<int> score;
vector<int> cal;
int maxScore;
void dfs(int s, int currScore, int currCal)
{
	if (currScore > maxScore) maxScore = currScore;
	for (int i = s + 1; i < n; i++)
	{
		if (ch[i] == 0)
		{
			if (currCal + cal[i] <= limit)
			{
				ch[i] = 1;
				dfs(i, currScore + score[i], currCal + cal[i]);
				ch[i] = 0;
			}
		}
	}
}
void runTest()
{
	maxScore = 0;
	cin >> n >> limit;
	ch = score = cal = vector<int>(n);
	for (int i = 0; i < n; i++)
	{
		cin >> score[i] >> cal[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (cal[i] <= limit)
		{
			ch[i] = 1;
			dfs(i, score[i], cal[i]);
		}
	}
	cout << maxScore << "\n";
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