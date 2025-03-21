#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int N, cnt;

struct cmp {
    bool operator()(const tuple<int, int, int>& a, const tuple<int, int, int>& b) const {
        return get<2>(a) > get<2>(b);
    }
};
vector<vector<int>> board;
vector<vector<int>> check;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, cmp> q;
int drow[] = {0,-1,0,1};
int dcol[] = {-1,0,1,0};
int minSum;

void getInput()
{
    while(!q.empty())
        q.pop();
    board = vector<vector<int>>(N, vector<int>(N, 0));
    check = vector<vector<int>>(N, vector<int>(N, 0));
    for (int i  = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    }
    check[0][0] = board[0][0];
    minSum = 2147000000;
    q.push(make_tuple(0, 0, board[0][0]));
}

void dijkstra()
{
    while (!q.empty())
    {
        int row, col, val;
        tie(row, col, val) = q.top();
        q.pop();
        if (row == N - 1 && col == N - 1)
        {
            minSum = val;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int nRow = row + drow[i];
            int nCol = col + dcol[i];
            if (nRow < 0 || nRow >= N ||
                nCol < 0 || nCol >= N) continue;
                if (check[nRow][nCol] == 0 || check[nRow][nCol] > check[row][col] + board[nRow][nCol])
                {
                    check[nRow][nCol] = check[row][col] + board[nRow][nCol];
                    q.push({nRow, nCol, val + board[nRow][nCol]});
            }   
        }
    }
}

void printResult()
{
    cout << "Problem " << cnt << ": " << minSum << "\n";
    cnt++;
}

int main()
{
    cnt = 1;
    while (1)
    {
        cin >> N;
        if (N == 0) break;
        else
        {
            getInput();
            dijkstra();
            printResult();
        }
    }
}