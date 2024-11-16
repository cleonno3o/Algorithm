#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int T;
int n;

vector<vector<int>> rotate(const vector<vector<int>>& board)
{
	vector<vector<int>> rotated(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			rotated[j][n - i - 1] = board[i][j];
		}
	}
	return rotated;
}
void runTest()
{
	cin >> n;
	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	}
	vector<vector<int>> res(n, vector<int>(n * 3));
	for (int i = 0; i < 3; i++)
	{
		board = rotate(board);
		for (int a = 0; a < n; a++)
		{
			for (int b = 0; b < n; b++)
			{
				res[a][i * n + b] = board[a][b];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3 * n; j++)
		{
			cout << res[i][j];
			if (j % n == n - 1) cout << " ";
		}
		cout << "\n";
	}
}

int main(int argc, char** argv)
{
	cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		cout << "#" << test_case << "\n";
		runTest();
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}