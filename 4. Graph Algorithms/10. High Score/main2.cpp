#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll NEG_INF = LLONG_MIN / 4;

struct Edge { int u, v; ll w; };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<Edge> edges;
    vector<vector<int>> adj(n + 1); // adjacency for BFS from "bad" nodes

    for (int i = 0; i < m; ++i) {
        int a, b; ll x;
        cin >> a >> b >> x;
        edges.push_back({a, b, x});
        adj[a].push_back(b);
    }

    vector<ll> dist(n + 1, NEG_INF);
    dist[1] = 0;

    // Relax edges n-1 times (maximize)
    for (int iter = 0; iter < n - 1; ++iter) {
        bool changed = false;
        for (auto &e : edges) {
            if (dist[e.u] != NEG_INF && dist[e.v] < dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
                changed = true;
            }
        }
        if (!changed) break;
    }

    // Find nodes affected by positive cycles reachable from 1
    vector<char> affected(n + 1, false);
    for (auto &e : edges) {
        if (dist[e.u] != NEG_INF && dist[e.v] < dist[e.u] + e.w) {
            affected[e.v] = true;
        }
    }

    // Propagate affected status (BFS/DFS) along edges
    queue<int> q;
    for (int i = 1; i <= n; ++i) if (affected[i]) q.push(i);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!affected[v]) {
                affected[v] = true;
                q.push(v);
            }
        }
    }

    // If n is affected => can obtain arbitrarily large score
    if (affected[n]) {
        cout << -1 << "\n";
    } else {
        cout << dist[n] << "\n";
    }

    return 0;
}
