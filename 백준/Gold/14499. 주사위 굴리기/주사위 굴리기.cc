#include <iostream>
using namespace std;

int n, m, x, y, k, dir;
int drow[] = {-100, 0, 0, -1, 1 };
int dcol[] = {-100, 1, -1, 0, 0 };
int board[20][20];
struct Dice {
	int up = 0;
	int down = 0;
	int left = 0;
	int right = 0;
	int front = 0;
	int back = 0;
} dice;

void updateDice()
{
	if (board[x][y] == 0)
		board[x][y] = dice.down;
	else
	{
		dice.down = board[x][y];
		board[x][y] = 0;
	}
	cout << dice.up << '\n';
}

void moveDice()
{
	int nRow = x + drow[dir];
	int nCol = y + dcol[dir];
	if (nRow < n && nRow >= 0 &&
		nCol < m && nCol >= 0)
	{
		x = nRow;
		y = nCol;
		//cout << x << " " << y << '\n';
		int temp;
		switch (dir)
		{
		case 1:
			temp = dice.right;
			dice.right = dice.up;
			dice.up = dice.left;
			dice.left = dice.down;
			dice.down = temp;
			break;
		case 2:
			temp = dice.up;
			dice.up = dice.right;
			dice.right = dice.down;
			dice.down = dice.left;
			dice.left = temp;
			break;
		case 3:
			temp = dice.up;
			dice.up = dice.front;
			dice.front = dice.down;
			dice.down = dice.back;
			dice.back = temp;
			break;
		case 4:
			temp = dice.up;
			dice.up = dice.back;
			dice.back = dice.down;
			dice.down = dice.front;
			dice.front = temp;
			break;
		}
		updateDice();
	}
	else return;
}

int main()
{
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < k; i++)
	{
		cin >> dir;
		moveDice();
	}
}