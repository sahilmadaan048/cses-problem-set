// https://cses.fi/problemset/task/1683

// Author - sahilmadaan048

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj, adj_rev;
vector<bool> visited;
vector<int> order, component;

void dfs1(int u) {
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v]) dfs1(v);
    order.push_back(u);
}

void dfs2(int u, int label, vector<int>& kingdom) {
    kingdom[u] = label;
    for (int v : adj_rev[u])
        if (!kingdom[v]) dfs2(v, label, kingdom);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    adj.assign(n + 1, {});
    adj_rev.assign(n + 1, {});

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }

    visited.assign(n + 1, false);

    for (int i = 1; i <= n; i++)
        if (!visited[i]) dfs1(i);

    vector<int> kingdom(n + 1, 0);
    int label = 0;

    for (int i = n - 1; i >= 0; i--) {
        int u = order[i];
        if (!kingdom[u]) {
            label++;
            dfs2(u, label, kingdom);
        }
    }

    cout << label << "\n";
    for (int i = 1; i <= n; i++) cout << kingdom[i] << " ";
    cout << "\n";

    return 0;
}