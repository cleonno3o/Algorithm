#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int t, l;
pair<int, int> start;
pair<int, int> goal;
vector<vector<int>> board;
int drow[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dcol[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
void getInput()
{
	cin >> l;
	cin >> start.first >> start.second;
	cin >> goal.first >> goal.second;
	board = vector<vector<int>>(l, vector<int>(l, -1));
	board[start.first][start.second] = 0;
	queue<pair<int, int>> q;
	q.push({ start });
	while (!q.empty())
	{
		pair<int, int>currPos = q.front();
		q.pop();
		if (currPos == goal)
			break;
		int row = currPos.first;
		int col = currPos.second;
		for (int i = 0; i < 8; i++)
		{
			int nRow = row + drow[i];
			int nCol = col + dcol[i];
			if (nRow < l && nRow >= 0 &&
				nCol < l && nCol >= 0)
			{
				if (board[nRow][nCol] == -1)
				{
					board[nRow][nCol] = board[row][col] + 1;
					q.push(make_pair(nRow, nCol));
				}
			}
		}
	}
	cout << board[goal.first][goal.second] << "\n";
}
int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		getInput();
	}
	return 0;
}