#include <iostream>
#include <vector>
#include <string>
using namespace std;
int img[64][64];
int n;
int drow[] = {0, 0, 1 ,1};
int dcol[] = {0, 1, 0, 1};
void dfs(int row, int col, int len)
{
    for (int t = 0; t < 4; t++)
    {
        int sRow = row + drow[t] * len;
        int sCol = col + dcol[t] * len;
        if (sRow >= n || sCol >= n) continue;
        int refVal = img[sRow][sCol];
        bool flag = true;
        for (int i = sRow; i < sRow + len; i++)
        {
            for (int j = sCol; j < sCol + len; j++)
            {
                if (img[i][j] != refVal || !flag)
                {
                    flag = false;
                    break;
                }
            }
        }
        if (!flag)
        {
            cout << "(";
            dfs(sRow, sCol, len / 2);
            cout <<")";
        }
        else
            cout << refVal;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            img[i][j] = s[j] - '0';
        }
    }
    dfs(0, 0, n);
}