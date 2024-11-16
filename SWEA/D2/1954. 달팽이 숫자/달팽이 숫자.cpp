#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T;
int drow[] = { 0, 1, 0, -1 };
int dcol[] = { 1, 0, -1, 0 };
void runTest()
{
	int n;
	cin >> n;
	int r = 0;
	int c = 0;
	int dir = 0;
	vector<vector<int> > board(n, vector<int>(n));
	for (int i = 1; i <= n * n; i++)
	{
		board[r][c] = i;
		int nrow = r + drow[dir];
		int ncol = c + dcol[dir];
		if (nrow >= n || ncol >= n || nrow < 0 || ncol < 0 || board[nrow][ncol] != 0)
		{
			dir++;
			if (dir == 4) dir = 0;
		}
		r += drow[dir];
		c += dcol[dir];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << board[i][j] << " ";
		cout << "\n";
	}
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