#include <iostream>
#include <vector>
using namespace std;
int r, c, t;
int drow[] = { 1, 0, -1, 0 };
int dcol[] = { 0, -1, 0, 1 };
vector<pair<int, int>> airMachine;
int main()
{
	cin >> r >> c >> t;
	vector<vector<int>> board(r + 1, vector<int>(c + 1));
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == -1)
				airMachine.push_back({ i,j });
		}
	}
	for (int i = 1; i <= t; i++)
	{
		// 미세먼지 턴
		vector<vector<int>> ch(r + 1, vector<int>(c + 1));
		for (int j = 1; j <= r; j++)
		{
			for (int k = 1; k <= c; k++)
			{
				if (board[j][k] != 0 && board[j][k] != -1)
				{
					int shareAmount = board[j][k] / 5;
					int shareCnt = 0;
					for (int l = 0; l < 4; l++)
					{
						int nRow = j + drow[l];
						int nCol = k + dcol[l];
						if (nRow <= r && nRow > 0 &&
							nCol <= c && nCol > 0 &&
							board[nRow][nCol] != -1)
						{
							shareCnt++;
							ch[nRow][nCol] += shareAmount;
						}
					}
					board[j][k] -= shareAmount * shareCnt;
				}
			}
		}
		for (int j = 1; j <= r; j++)
		{
			for (int k = 1; k <= c; k++)
			{
				board[j][k] += ch[j][k];
			}
		}
		// 청정기 턴
		for (int j = 0; j < 2; j++)
		{
			pair<int, int> airPos = airMachine[j];
			// 위쪽 청정기
			if (j == 0)
			{
				for (int a = airPos.first - 1; a >= 2; a--)
					board[a][1] = board[a - 1][1];
				for (int a = 1; a <= c - 1; a++)
					board[1][a] = board[1][a + 1];
				for (int a = 1; a <= airPos.first - 1; a++)
					board[a][c] = board[a + 1][c];
				for (int a = c; a >= 3; a--)
					board[airPos.first][a] = board[airPos.first][a - 1];
				board[airPos.first][2] = 0;
			}
			// 아래쪽 청정기
			else
			{
				for (int a = airPos.first + 1; a <= r - 1; a++)
					board[a][1] = board[a + 1][1];
				for (int a = 1; a <= c - 1; a++)
					board[r][a] = board[r][a + 1];
				for (int a = r; a >= airPos.first + 1; a--)
					board[a][c] = board[a - 1][c];
				for (int a = c; a >= 3; a--)
					board[airPos.first][a] = board[airPos.first][a - 1];
				board[airPos.first][2] = 0;
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (board[i][j] != -1)
				res += board[i][j];
		}
	}
	cout << res;
}