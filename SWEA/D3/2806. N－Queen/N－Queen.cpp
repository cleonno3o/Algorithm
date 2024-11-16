#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int T;
int n;
vector<vector<int>> board;
vector<int> ch;
int res;
void recur(int row)
{
	if (row == n)
	{
		bool isFound = true;
		for (int i = 0; i < n; i++)
		{
			if (ch[i] == -1)
			{
				isFound = false;
				break;
			}
		}
		if (isFound) res++;
	}
	for (int i = 0; i < n; i++)
	{
		bool isPossible = true;
		for (int j = 0; j <= row - 1; j++)
		{
			if (ch[j] == i)
			{
				isPossible = false;
				break;
			}
			else
			{
				int rDiff = abs(row - j);
				int cDiff = abs(i - ch[j]);
				if (rDiff == cDiff)
				{
					isPossible = false;
					break;
				}
			}
		}
		if (isPossible)
		{
			ch[row] = i;
			recur(row + 1);
			ch[row] = -1;
		}
	}
}
void runTest()
{
	res = 0;
	cin >> n;
	board = vector<vector<int>>(n, vector<int>(n));
	ch = vector<int>(n, -1);
	for (int i = 0; i < n; i++)
	{
		ch[0] = i;
		recur(1);
		ch[0] = -1;
	}
	cout << res << "\n";
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