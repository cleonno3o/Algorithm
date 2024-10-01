#include <iostream>
#include <vector>
using namespace std;

int drow[] = { -1, 0, 1, 0 };
int dcol[] = { 0, 1, 0, -1 };
int n, m, r, c, d;
void rotate()
{
	d--;
	if (d == -1) d = 3;
}
int main()
{
	cin >> n >> m;
	cin >> r >> c >> d;

	vector<vector<int>> board(n, vector<int>(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	int cnt = 0;
	while (1)
	{
		// 현재 위치가 더러우면 청소
		if (board[r][c] == 0)
		{
			board[r][c] = 2;
			cnt++;
		}
		// 깨끗하면
		// 주변을 확인
		bool flg = false;
		for (int i = 0; i < 4; i++) {
			rotate();  // 왼쪽으로 회전
			int nRow = r + drow[d];
			int nCol = c + dcol[d];

			if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && board[nRow][nCol] == 0) {
				r = nRow;
				c = nCol;
				flg = true;  // 청소할 수 있는 곳을 찾음
				break;
			}
		}

		// 주변이 깨끗함
		if (!flg)
		{
			int nRow = r - drow[d];
			int nCol = c - dcol[d];
			if (nRow < 0 || nRow >= n || nCol < 0 || nCol >= m || board[nRow][nCol] == 1)
				break;
			else
			{
				r = nRow;
				c = nCol;
			}
		}
	}
	cout << cnt;
}