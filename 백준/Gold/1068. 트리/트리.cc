#include <iostream>
#include <queue>
using namespace std;
int N, kill, cnt;
bool child[50][50];
bool isDead[50];
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        if (temp != -1) child[temp][i] = true;
    }
    cin >> kill;
    queue<int> q;
    q.push(kill);
    isDead[kill] = true;
    while (!q.empty())
    {
        int target = q.front();
        q.pop();
        for (int i = 0; i < N; i++)
        {
            if (child[target][i])
            {
                isDead[i] = true;
                q.push(i);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        bool isLeaf = true;
        for (int j = 0; j < N; j++)
        {
            if (child[i][j] && !isDead[j])
            {
                isLeaf = false;
                break;
            }
        }
        if (isLeaf && !isDead[i]) cnt++;
    }
    cout << cnt;
}