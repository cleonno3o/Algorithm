#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> graph;
vector<vector<int>> dist;
void dijkstra(int s, int e)
{
    int res = 2147000000;
    priority_queue<pair<int, int>> pq;
    pq.push({0, s});
    dist[s][s] = 0;
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int pos = pq.top().second;
        pq.pop();
        if (-cost > dist[s][pos]) continue;
        for (int i = 1; i <= N; i++)
        {
            if (graph[pos][i] != -1)
            {
                if (dist[s][i] > -cost + graph[pos][i])
                {
                    dist[s][i] = -cost + graph[pos][i];
                    pq.push({-dist[s][i], i});
                }
            }
        }
    }
    cout << dist[s][e] << "\n";
}

int main()
{
    cin >> N >> M;
    graph = vector<vector<int>>(N + 1, vector<int>(N + 1, -1));
    dist = vector<vector<int>>(N + 1, vector<int>(N + 1, 2147000000));
    for (int i = 1; i <= N - 1; i++)
    {
        int s, e, dist;
        cin >> s >> e >> dist;
        graph[s][e] = dist;
        graph[e][s] = dist;
    }
    for (int i = 1; i <= M; i++)
    {
        int s, e;
        cin >> s >> e;
        dijkstra(s, e);
    }
    
}