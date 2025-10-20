#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    // min-heap: (cost, node)
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
    pq.push({0, 1});

    vector<vector<long long>> dist(n + 1); // store up to k distances for each node

    while (!pq.empty()) {
        auto [cost, u] = pq.top(); pq.pop();

        if (dist[u].size() >= k) continue; // already have k shortest distances

        dist[u].push_back(cost);

        for (auto [v, w] : adj[u]) {
            pq.push({cost + w, v});
        }
    }

    sort(dist[n].begin(), dist[n].end());
    for (long long price : dist[n]) cout << price << " ";
    cout << "\n";

    return 0;
}
