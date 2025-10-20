#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<pair<int, int>>> adj; // adj[u] = {{v, w}, ...}
vector<bool> visited;
long long maxPathSum = LLONG_MIN;

void dfs(int u, long long currSum) {
    if (u == n) { // reached destination
        maxPathSum = max(maxPathSum, currSum);
        return;
    }

    visited[u] = true;

    for (auto [v, w] : adj[u]) {
        if (!visited[v]) {
            dfs(v, currSum + w);
        }
    }

    visited[u] = false; // backtrack
}

int main() {
  cin >> n >> m;
    adj.assign(n + 1, {});
    visited.assign(n + 1, false);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
        // if undirected graph, also add adj[b].push_back({a, w});
    }

    dfs(1, 0);

    cout << maxPathSum << "\n";


    return 0;
}
