#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1001;
const int LOG = 10; // log2(1000) ≈ 10

vector<pair<int, int>> tree[MAX];
int parent[MAX][LOG]; // 2^k번째 조상
int depth[MAX];
int dist[MAX];

void dfs(int curr, int par, int d) {
    depth[curr] = depth[par] + 1;
    parent[curr][0] = par;
    dist[curr] = d;

    for (auto [next, w] : tree[curr]) {
        if (next != par) dfs(next, curr, d + w);
    }
}

void buildLCA(int N) {
    for (int k = 1; k < LOG; k++) {
        for (int v = 1; v <= N; v++) {
            parent[v][k] = parent[parent[v][k - 1]][k - 1];
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int k = LOG - 1; k >= 0; k--) {
        if (depth[u] - (1 << k) >= depth[v]) {
            u = parent[u][k];
        }
    }
    if (u == v) return u;
    for (int k = LOG - 1; k >= 0; k--) {
        if (parent[u][k] != parent[v][k]) {
            u = parent[u][k];
            v = parent[v][k];
        }
    }
    return parent[u][0];
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
    }

    dfs(1, 0, 0);     // 루트는 1
    buildLCA(N);      // LCA 전처리

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        int anc = lca(u, v);
        cout << dist[u] + dist[v] - 2 * dist[anc] << '\n';
    }
}
