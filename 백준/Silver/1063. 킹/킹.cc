#include <iostream>
#include <string>
#include <utility>
#define KING 1
#define STONE 2
using namespace std;
int drow[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dcol[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
pair<int, int> king;
pair<int, int> stone;
int order[51];
int N;
void getInput()
{
	string kIn, sIn;
	cin >> kIn >> sIn >> N;
	king = make_pair('9' - kIn[1], kIn[0] - 'A' + 1);
	stone = make_pair('9' - sIn[1], sIn[0] - 'A' + 1);
	for (int i = 1; i <= N; i++)
	{
		string ord;
		cin >> ord;
		if (ord == "R") order[i] = 0;
		else if (ord == "L") order[i] = 1;
		else if (ord == "B") order[i] = 2;
		else if (ord == "T") order[i] = 3;
		else if (ord == "RT") order[i] = 4;
		else if (ord == "LT") order[i] = 5;
		else if (ord == "RB") order[i] = 6;
		else if (ord == "LB") order[i] = 7;
	}
}
int main()
{
	getInput();
	for (int i = 1; i <= N; i++)
	{
		int nRow = king.first + drow[order[i]];
		int nCol = king.second + dcol[order[i]];
		// 밖이면 안함
		if (nRow > 8 || nRow < 1 ||
			nCol > 8 || nCol < 1) continue;
		// 안인데 빈칸
		if (make_pair(nRow, nCol) != stone)
		{
			king = make_pair(nRow, nCol);
		}
		// 안인데 돌
		else
		{
			int nnRow = nRow + drow[order[i]];
			int nnCol = nCol + dcol[order[i]];
			if (nnRow > 8 || nnRow < 1 ||
				nnCol > 8 || nnCol < 1) continue;
			else
			{
				stone = make_pair(nnRow, nnCol);
				king = make_pair(nRow, nCol);
			}
		}
	}
	cout << char('A' + king.second - 1) << 9 - king.first << "\n";
	cout << char('A' + stone.second - 1) << 9 - stone.first << "\n";
}