#include <iostream>
using namespace std;
int board[5][5];
int combo;
void checkRow()
{
	for (int i = 0; i < 5; i++)
	{
		bool flag = true;
		for (int j = 0; j < 5; j++)
		{
			if (board[i][j] != 0)
			{
				flag = false;
				break;
			}
		}
		if (flag) combo++;
	}
}
void checkCol()
{
	for (int i = 0; i < 5; i++)
	{
		bool flag = true;
		for (int j = 0; j < 5; j++)
		{
			if (board[j][i] != 0)
			{
				flag = false;
				break;
			}
		}
		if (flag) combo++;
	}
}
void checkDiag()
{
	if (board[0][0] == 0 &&
		board[1][1] == 0 &&
		board[2][2] == 0 &&
		board[3][3] == 0 &&
		board[4][4] == 0)
	{
		combo++;
	}
	if (board[0][4] == 0 &&
		board[1][3] == 0 &&
		board[2][2] == 0 &&
		board[3][1] == 0 &&
		board[4][0] == 0)
	{
		combo++;
	}
}
void check()
{
	combo = 0;
	checkRow();
	checkCol();
	checkDiag();
}
int main()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			cin >> board[i][j];
	}
	for (int i = 1; i <= 25; i++)
	{
		int target;
		cin >> target;
		bool isFound = false;
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				if (board[j][k] == target)
				{
					board[j][k] = 0;
					isFound = true;
					break;
				}
			}
			if (isFound) break;
		}
		check();
		if (combo >= 3)
		{
			cout << i;
			break;
		}
	}
}