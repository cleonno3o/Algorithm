#include <iostream>
#include <queue>
using namespace std;

int N;
pair<int, int> start, goal;
int board[200][200];
int check[200][200];
int drow[] = {-2, -2, 0, 0, 2, 2 };
int dcol[] = {-1, 1, -2, 2, -1, 1 };
int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> N;
    cin >> start.first >> start.second >> goal.first >> goal.second;
    queue<pair<int, pair<int, int>>> q;
    q.push({1, start});
    while (!q.empty())
    {
        int dist = q.front().first;
        pair<int, int> pos = q.front().second;
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int nRow = pos.first + drow[i];
            int nCol = pos.second + dcol[i];
            if (nRow >= N || nRow < 0 || nCol >= N || nCol < 0) continue;
            if (check[nRow][nCol] == 0)
            {
                check[nRow][nCol] = dist + 1;
                q.push({dist + 1, {nRow, nCol}});
            }
        }
    }
    if (check[goal.first][goal.second] == 0) cout << -1;
    else cout << check[goal.first][goal.second] - 1;
}