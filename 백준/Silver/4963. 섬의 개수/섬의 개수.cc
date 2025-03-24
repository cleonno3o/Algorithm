#include <iostream>
#include <queue>

using namespace std;

int board[51][51];
int check[51][51];
int drow[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dcol[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int w, h, cnt;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    while (1)
    {
        cnt = 0;
        queue<pair<int, int>> q;
        cin >> w >> h;
        if (w == 0 and h == 0) break;
        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                cin >> board[i][j];
                check[i][j] = 0;
            }
        }
        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                if (check[i][j] == 0)
                {
                    if (board[i][j] == 1)
                    {
                        cnt += 1;
                        q.push({i, j});
                        check[i][j] = 1;
                        while (!q.empty())
                        {
                            pair<int, int> pos = q.front();
                            int row = pos.first;
                            int col = pos.second;
                            q.pop();

                            for (int k = 0; k < 8; k++)
                            {
                                int nRow = row + drow[k];
                                int nCol = col + dcol[k];
                                if (nRow > h || nRow < 1 || nCol > w || nCol < 1) continue;
                                else if (board[nRow][nCol] == 1 && check[nRow][nCol] == 0)
                                {
                                    q.push({nRow, nCol});
                                    check[nRow][nCol] = 1;
                                }
                            }
                        }
                    }
                    else check[i][j] = 1;
                }
            }
        }
        cout << cnt << "\n";
    }
}