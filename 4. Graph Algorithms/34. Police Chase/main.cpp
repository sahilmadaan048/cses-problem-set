// Author - sahilmadaan048
// https://cses.fi/problemset/task/1695

#include "bits/stdc++.h"
#define int long long
#define vi vector<int>
using namespace std;

struct Edge {
    int v, flow, cap;
    int rev;
};

struct Dinic {
    int n;
    vector<vector<Edge>> adj;
    vector<int> level, start;

    Dinic(int n) {
        this->n = n;
        adj.resize(n);
        level.resize(n);
        start.resize(n);
    }

    void addEdge(int u, int v, int cap) {
        Edge a = {v, 0, cap, (int)adj[v].size()};
        Edge b = {u, 0, cap, (int)adj[u].size()}; // undirected => cap both ways
        adj[u].push_back(a);
        adj[v].push_back(b);
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;

        queue<int> q;
        q.push(s);

        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(auto &e : adj[u]) {
                if(level[e.v] < 0 && e.flow < e.cap) {
                    level[e.v] = level[u] + 1;
                    q.push(e.v);
                }
            }
        }

        return level[t] >= 0;
    }

    int sendFlow(int u, int flow, int t) {
        if(u == t) return flow;

        for(int &i = start[u]; i < adj[u].size(); i++) {
            Edge &e = adj[u][i];

            if(level[e.v] == level[u] + 1 && e.flow < e.cap) {
                int curr_flow = min(flow, e.cap - e.flow);
                int temp_flow = sendFlow(e.v, curr_flow, t);

                if(temp_flow > 0) {
                    e.flow += temp_flow;
                    adj[e.v][e.rev].flow -= temp_flow;
                    return temp_flow;
                }
            }
        }
        return 0;
    }

    int maxFlow(int s, int t) {
        int total = 0;

        while(bfs(s, t)) {
            fill(start.begin(), start.end(), 0);
            while(int flow = sendFlow(s, LLONG_MAX, t)) {
                total += flow;
            }
        }

        return total;
    }

    vector<bool> minCutReachable(int s) {
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(s);
        visited[s] = true;

        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(auto &e : adj[u]) {
                if(!visited[e.v] && e.flow < e.cap) {
                    visited[e.v] = true;
                    q.push(e.v);
                }
            }
        }

        return visited;
    }
};

void solve() {

    int n, m;
    cin >> n >> m;

    Dinic dinic(n);

    vector<pair<int,int>> edges;

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        edges.push_back({a, b});
        dinic.addEdge(a, b, 1);
    }

    int flow = dinic.maxFlow(0, n-1);

    cout << flow << "\n";

    vector<bool> reachable = dinic.minCutReachable(0);

    for(auto [u, v] : edges) {
        if(reachable[u] && !reachable[v]) {
            cout << u+1 << " " << v+1 << "\n";
        }
        else if(reachable[v] && !reachable[u]) {
            cout << v+1 << " " << u+1 << "\n";
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    while (T--) {
        solve();
    }

    return 0;
}