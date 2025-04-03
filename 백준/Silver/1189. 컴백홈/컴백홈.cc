#include <iostream>
#include <string>

using namespace std;
int R, C, K;
int board[5][5];
int cnt;
int drow[] = { 0, -1, 0, 1 };
int dcol[] = { -1, 0, 1, 0 };

void dfs(int row, int col, int dist)
{
    if (row == 0 && col == C - 1)
    {
        if (dist == K) cnt++;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            int nRow = row + drow[i];
            int nCol = col + dcol[i];
            if (nRow >= R || nRow < 0 || nCol >= C || nCol < 0) continue;
            if (board[nRow][nCol] != -1 && board[nRow][nCol] != 1 && dist + 1 <= K)
            {
                board[nRow][nCol] = -1;
                dfs(nRow, nCol, dist + 1);
                board[nRow][nCol] = 0;
            }
        }
    }
}

int main()
{
    cin >> R >> C >> K;
    string temp;
    for (int i = 0; i < R; i++)
    {
        cin >> temp;
        for (int j = 0; j < C; j++)
        {
            if (temp[j] == '.') board[i][j] = 0;
            else board[i][j] = 1;
        }
    }
    board[R - 1][0] = -1;
    dfs(R - 1, 0, 1);
    cout << cnt;
}