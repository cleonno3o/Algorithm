#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int drow[] = { 1, 0, -1, 0 };
int dcol[] = { 0, -1, 0, 1 };
int area, maxArea;
int n, m;
void bfs(vector<vector<int>> board)
{
	area = 0;
	vector<vector<int>> ch(n, vector<int>(m));
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 2)
			{
				q.push({ i, j });
			}
		}
	}
	while (!q.empty())
	{
		pair<int, int> pos = q.front();
		ch[pos.first][pos.second] = 1;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nRow = pos.first + drow[i];
			int nCol = pos.second + dcol[i];
			if (nRow < n && nRow >= 0 &&
				nCol < m && nCol >= 0 &&
				ch[nRow][nCol] == 0 && board[nRow][nCol] == 0)
			{
				board[nRow][nCol] = 2;
				q.push({ nRow, nCol });
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0)
				area++;
		}
	}
	if (area > maxArea) maxArea = area;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int temp;
			cin >> temp;
			board[i][j] = temp;
		}
	}

	for (int a = 0; a < n; a++)
	{
		for (int b = 0; b < m; b++)
		{
			if (board[a][b] == 0)
			{
				board[a][b] = 1;
				for (int c = a; c < n; c++)
				{
					for (int d = 0; d < m; d++)
					{
						if (board[c][d] == 0)
						{
							board[c][d] = 1;
							for (int e = c; e < n; e++)
							{
								for (int f = 0; f < m; f++)
								{
									if (board[e][f] == 0)
									{
										board[e][f] = 1;
										bfs(board);
										board[e][f] = 0;
									}
								}
							}
							board[c][d] = 0;
						}
					}
				}
				board[a][b] = 0;
			}
		}
	}
	cout << maxArea;
}