#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void runTest()
{
    int temp;
    cin >> temp;
    vector<vector<int>> board(100, vector<int>(100));
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            cin >> board[i][j];
        }
    }
    int maxSum = 0;
    for (int i = 0; i < 100; i++)
    {
        int rSum, cSum;
        rSum = cSum = 0;
        for (int j = 0; j < 100; j++)
        {
            rSum += board[i][j];
            cSum += board[j][i];
        }
        maxSum = max({ maxSum, rSum, cSum });
    }
    int d1, d2;
    d1 = d2= 0;
    for (int i = 0; i < 100; i++)
    {
        d1 += board[i][i];
        d2 += board[i][100 - i - 1];
    }
    cout << max({ maxSum, d1, d2 }) << "\n";
}

int main()
{
    for (int i = 1; i <= 10; i++)
    {
        cout << "#" << i << " ";
        runTest();
    }
}