#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int drow[] = { 1, 0 ,-1, 0 };
int dcol[] = { 0, -1, 0, 1 };

int main()
{
	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	}
	int playTime = 0;
	int prevChzz = 0;
	while (1)
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (board[i][j] == 1)
					cnt++;
			}
		}
		if (cnt == 0) break;
		else
		{
			prevChzz = cnt;
			playTime++;
			vector<vector<int>> ch(n, vector<int>(m));
			queue<pair<int, int>> q;
			q.push({ 0,0 });
			ch[0][0] = 1;
			while (!q.empty())
			{
				pair<int, int> pos = q.front();
				q.pop();
				if (board[pos.first][pos.second] == 0)
				{
					for (int i = 0; i < 4; i++)
					{
						int nRow = pos.first + drow[i];
						int nCol = pos.second + dcol[i];
						if (nRow < n && nRow >=0 &&
							nCol < m && nCol >=0 &&
							ch[nRow][nCol] == 0)
						{
							ch[nRow][nCol] = 1;
							q.push({ nRow, nCol });
						}
					}
				}
				else
				{
					board[pos.first][pos.second] = 0;
				}
			}
		}
	}
	cout << playTime << '\n' << prevChzz;
}