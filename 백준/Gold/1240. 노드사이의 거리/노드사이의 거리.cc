#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> graph;
void dijkstra(int s, int e)
{
    int res = 2147000000;
    vector<int> dist(N + 1, 2147000000);
    priority_queue<pair<int, int>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int pos = pq.top().second;
        pq.pop();
        if (-cost > dist[pos]) continue;
        for (int i = 1; i <= N; i++)
        {
            if (graph[pos][i] != -1)
            {
                if (dist[i] > -cost + graph[pos][i])
                {
                    dist[i] = -cost + graph[pos][i];
                    pq.push({-dist[i], i});
                }
            }
        }
    }
    cout << dist[e] << "\n";
}

int main()
{
    cin >> N >> M;
    graph = vector<vector<int>>(N + 1, vector<int>(N + 1, -1));
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