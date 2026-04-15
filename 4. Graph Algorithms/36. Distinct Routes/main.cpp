// Author - sahilmadaan048

// https://cses.fi/problemset/task/1711

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, rev, cap;
    bool original;   // true if this is real input edge
};

const int MAXN = 505;
vector<Edge> graph[MAXN];
int level[MAXN], ptr[MAXN];
int n, m;

void add_edge(int u, int v) {
    Edge a = {v, (int)graph[v].size(), 1, true};
    Edge b = {u, (int)graph[u].size(), 0, false};
    graph[u].push_back(a);
    graph[v].push_back(b);
}

bool bfs(int s, int t) {
    memset(level, -1, sizeof(level));
    queue<int> q;
    q.push(s);
    level[s] = 0;

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto &e : graph[u]) {
            if(level[e.to] == -1 && e.cap > 0) {
                level[e.to] = level[u] + 1;
                q.push(e.to);
            }
        }
    }
    return level[t] != -1;
}

int dfs(int u, int t, int flow) {
    if(u == t) return flow;

    for(int &cid = ptr[u]; cid < graph[u].size(); cid++) {
        Edge &e = graph[u][cid];
        if(level[e.to] == level[u] + 1 && e.cap > 0) {
            int pushed = dfs(e.to, t, min(flow, e.cap));
            if(pushed) {
                e.cap -= pushed;
                graph[e.to][e.rev].cap += pushed;
                return pushed;
            }
        }
    }
    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    while(bfs(s, t)) {
        memset(ptr, 0, sizeof(ptr));
        while(int pushed = dfs(s, t, 1e9))
            flow += pushed;
    }
    return flow;
}

vector<int> path;

bool extract_path(int u, int t) {
    path.push_back(u);
    if(u == t) return true;

    for(auto &e : graph[u]) {
        // follow only original edges where flow was used
        if(e.original && e.cap == 0) {
            e.cap = -1; // mark as used so we don't reuse
            if(extract_path(e.to, t))
                return true;
        }
    }

    path.pop_back();
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add_edge(a, b);
    }

    int flow = maxflow(1, n);
    cout << flow << "\n";

    while(flow--) {
        path.clear();
        extract_path(1, n);
        cout << path.size() << "\n";
        for(int x : path) cout << x << " ";
        cout << "\n";
    }

    return 0;
}