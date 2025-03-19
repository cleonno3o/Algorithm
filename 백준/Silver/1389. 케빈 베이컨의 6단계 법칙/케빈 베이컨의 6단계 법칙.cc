#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int minPerson, minDist = 2147000000;
vector<int> graph[120];
vector<int> dist;

void getInput()
{
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        int s, e;
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
}

void calDist()
{
    for (int i = 1; i <= N; i++)
    {
        queue<pair<int, int>> q;
        dist = vector<int>(N + 1, -1);
        for (int j = 0; j < graph[i].size(); j++)
        {
            q.push(make_pair(graph[i][j], 1));
            dist[graph[i][j]] = 1;
        }
        while (!q.empty())
        {
            pair<int, int> info = q.front();
            int node = info.first;
            int step = info.second;
            q.pop();
            for (int j = 0; j < graph[node].size(); j++)
            {
                if (i != graph[node][j] && (dist[graph[node][j]] == -1 || dist[graph[node][j]] > step + 1)
                ) 
                {
                    dist[graph[node][j]] = step + 1;
                    q.push(make_pair(graph[node][j], step + 1));
                }
            }
        }
        int tempSum = 0;
        for (int j = 1; j <= N; j++)
        {
            tempSum += dist[j];
        }
        if (tempSum < minDist)
        {
            minDist = tempSum;
            minPerson = i;
        }
    }
}

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    getInput();
    calDist();
    cout << minPerson;
}