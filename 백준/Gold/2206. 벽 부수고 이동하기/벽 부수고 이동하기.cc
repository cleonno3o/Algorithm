#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int drow[] = { 1, 0 ,-1, 0 };
int dcol[] = { 0, -1, 0, 1 };
struct Pos {
	int first;
	int second;
	bool isBroke;
};
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n + 1, vector<int>(m + 1));
	vector<vector<vector<int>>> ch(n + 1, vector<vector<int>>(m + 1, vector<int>(2)));
	vector<vector<int>> dist(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; i++)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < temp.length(); j++)
		{
			board[i][j + 1] = temp[j] - '0';
		}
	}
	queue<Pos> q;
	q.push({ 1,1, false });
	ch[1][1][0] = 1;
	int res = -1;
	while (!q.empty())
	{
		Pos pos = q.front();
		q.pop();
		if (pos.first == n && pos.second == m)
		{
			res = ch[pos.first][pos.second][pos.isBroke];
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int nRow = pos.first + drow[i];
			int nCol = pos.second + dcol[i];
			if (nRow <= n && nRow >= 1 &&
				nCol <= m && nCol >= 1)
			{
				// 부순적있으면
				if (pos.isBroke)
				{
					if (board[nRow][nCol] == 0 && ch[nRow][nCol][1] == 0)
					{
						q.push({ nRow, nCol, pos.isBroke });
						ch[nRow][nCol][1] = ch[pos.first][pos.second][1] + 1;
					}
				}
				else
				{
					if (board[nRow][nCol] == 1 && ch[nRow][nCol][1] == 0)
					{
						q.push({ nRow, nCol, true });
						ch[nRow][nCol][1] = ch[pos.first][pos.second][0] + 1;
					}
					else if (board[nRow][nCol] == 0 && ch[nRow][nCol][0] == 0)
					{
						q.push({ nRow, nCol, false });
						ch[nRow][nCol][0] = ch[pos.first][pos.second][0] + 1;
					}
				}
			}
		}
	}
	cout << res;
}