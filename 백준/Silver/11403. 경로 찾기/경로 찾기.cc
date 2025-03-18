#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<vector<int>> board;
vector<vector<int>> check;
queue<pair<int, int>> q;
void getInput()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1) 
            {
                q.push(make_pair(i, j));
            }
        }
    }
}
void printBoard()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    cin >> N;
    board = vector<vector<int>>(N, vector<int>(N, 0));
    check = vector<vector<int>>(N, vector<int>(N, 0));
    getInput();
    while (!q.empty())
    {
        pair<int, int> path = q.front();
        q.pop();
        int s = path.first;
        int e = path.second;
        for (int i = 0; i < N; i++)
        {
            if (board[e][i] == 1 && check[s][i] == 0)
            {
                board[s][i] = 1;
                check[s][i] = 1;
                q.push(make_pair(s, i));
            }
        }
    }
    printBoard();
}
