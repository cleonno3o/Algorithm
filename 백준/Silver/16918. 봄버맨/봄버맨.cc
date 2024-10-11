#include <iostream>
using namespace std;
int board[200][200];
int R, C, N;
int d_row[] = { 0, 1, 0, -1 };
int d_col[] = { 1, 0, -1, 0 };
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	cin >> R >> C >> N;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			char c;
			cin >> c;
			if (c == 'O') board[i][j] = -1;
		}
	}
	for (int turn = 1; turn <= N; turn++)
	{
		if (turn == 1) continue;
		else if (turn % 2 == 0)
		{
			for (int i = 0; i < R; i++)
			{
				for (int j = 0; j < C; j++)
				{
					if (board[i][j] == 0) board[i][j] = turn;
				}
			}
		}
		else if (turn % 2 == 1)
		{
			for (int i = 0; i < R; i++)
			{
				for (int j = 0; j < C; j++)
				{
					if ((board[i][j] != 0 and board[i][j] == turn - 3) or board[i][j] == -1)
					{
						board[i][j] = 0;
						for (int k = 0; k < 4; k++)
						{
							int n_row = i + d_row[k];
							int n_col = j + d_col[k];
							if (n_row >= R or n_row < 0 or n_col >= C or n_col < 0) continue;
							if ((board[n_row][n_col] != 0 and board[n_row][n_col] == turn - 3) || board[n_row][n_col] == -1) continue;
							board[n_row][n_col] = 0;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (board[i][j] == 0) cout << ".";
			else cout << "O";
		}
		cout << "\n";
	}
}