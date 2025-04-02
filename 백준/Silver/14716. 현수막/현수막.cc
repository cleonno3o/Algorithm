#include <iostream>
#include <queue>
using namespace std;

int N, M;
int board[250][250];
int drow[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dcol[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int cnt = 0;
int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> M >> N;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 1)
            {
                queue<pair<int, int>> q;
                cnt++;
                q.push({i, j});
                board[i][j] = 0;
                while (!q.empty())
                {
                    int row = q.front().first;
                    int col = q.front().second;
                    q.pop();
                    for (int k = 0; k < 8; k++)
                    {
                        int nRow = row + drow[k];
                        int nCol = col + dcol[k];
                        if (nRow >= M || nRow < 0 || nCol >= N || nCol < 0) continue;
                        if (board[nRow][nCol] == 1)
                        {
                            board[nRow][nCol] = 0;
                            q.push({nRow, nCol});
                        }
                    }
                }
            }
        }
    }
    cout << cnt;
}