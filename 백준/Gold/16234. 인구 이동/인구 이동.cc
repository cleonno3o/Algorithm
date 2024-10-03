#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> board(51, vector<int>(51));
vector<vector<int>> ch(51, vector<int>(51));
vector<int> population(2501);
int n, l, r, unionIdx;
int drow[] = { 1, 0, -1, 0 };
int dcol[] = { 0, -1, 0, 1 };
bool isMoved = true;
void bfs(int row, int col)
{
    queue<pair<int, int>> q;
    int cnt = 1;
    q.push({ row, col });
    ch[row][col] = unionIdx;
    population[unionIdx] += board[row][col];
    while (!q.empty())
    {
        pair<int, int> pos = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nRow = pos.first + drow[i];
            int nCol = pos.second + dcol[i];
            if (nRow <= n && nRow > 0 &&
                nCol <= n && nCol > 0 &&
                ch[nRow][nCol] == 0)
            {
                int diff = abs(board[pos.first][pos.second] - board[nRow][nCol]);
                if (diff >= l && diff <= r)
                {
                    cnt++;
                    isMoved = true;
                    population[unionIdx] += board[nRow][nCol];
                    ch[nRow][nCol] = unionIdx;
                    q.push({ nRow, nCol });
                }
            }
        }
    }
    population[unionIdx] = population[unionIdx] / cnt;
}
void runDay()
{
    unionIdx = 0;
    isMoved = false;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            ch[i][j] = 0;
    }
    for (int i = 1; i <= 2500; i++)
        population[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (ch[i][j] == 0)
            {
                unionIdx++;
                bfs(i, j);
            }
        }
    }
    if (isMoved)
    {
        for (int i = 1; i <= n ; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                board[i][j] = population[ch[i][j]];
            }
        }
    }
}
int main()
{
    cin >> n >> l >> r;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> board[i][j];
        }
    }
    int days = 0;
    while (1)
    {
        runDay();
        if (isMoved) days++;
        else break;
    }
    cout << days;
}