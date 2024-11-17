#include <string>
#include <vector>

using namespace std;
void dfs(int s,int lv, int n, vector<vector<int>>& computers)
{
    for (int i = 0; i < n; i++)
    {
        if (computers[s][i] != 0)
        {
            computers[s][i] = 0;
            computers[i][i] = 0;
            dfs(i, lv, n, computers);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        if (computers[i][i] != 0)
        {
            answer++;
            computers[i][i] = 0;
            dfs(i, 0, n, computers);
        }
    }
    return answer;
}