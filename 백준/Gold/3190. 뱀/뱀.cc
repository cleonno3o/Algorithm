#include <iostream>
#include <vector>
#include <queue>
#define BLANK 0
#define APPLE 1
#define BODY 2
using namespace std;
int n, k, l;
int drow[] = { 0, 1, 0, -1 };
int dcol[] = { 1, 0, -1, 0 };
int d = 0;

void rotate(char orientation)
{
	if (orientation == 'L')
	{
		d--;
		if (d == -1) d = 3;
	}
	else
	{
		d++;
		if (d == 4) d = 0;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	cin >> k;
	vector<vector<int>> board(n + 1, vector<int>(n + 1));
	for (int i = 0; i < k; i++)
	{
		int row, col;
		cin >> row >> col;
		board[row][col] = APPLE;
	}
	cin >> l;
	queue<pair<int, char>> q;
	for (int i = 0; i < l; i++)
	{
		int time;
		char direction;
		cin >> time >> direction;
		q.push({ time, direction });
	}
	queue<pair<int, int>> snake;
	snake.push({ 1,1 });
	board[1][1] = BODY;

	int playTime = 0;
	// Play Game
	while (1)
	{
		playTime++;
		pair<int, int> head = snake.back();
		int nRow = head.first + drow[d];
		int nCol = head.second + dcol[d];
		if (nRow > n || nRow < 1 || nCol > n || nCol < 1 || board[nRow][nCol] == BODY)
			break;
		else
		{
			if (board[nRow][nCol] != APPLE)
			{
				board[snake.front().first][snake.front().second] = BLANK;
				snake.pop();
			}
			board[nRow][nCol] = BODY;
			snake.push({ nRow, nCol });
		}
		if (!q.empty() && playTime == q.front().first)
		{
			rotate(q.front().second);
			q.pop();
		}
	}
	cout << playTime;
}