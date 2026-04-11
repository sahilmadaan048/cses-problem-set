// https://cses.fi/problemset/task/1684

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

vector<int> adj[MAXN], adj2[MAXN];
vector<int> order;
bool vis[MAXN];
int comp[MAXN];
int value_ans[MAXN];
int n, m;
int comp_id = 0;

void dfs1(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs1(v);
        }
    }
    order.push_back(u);
}

void dfs2(int u) {
    vis[u] = true;
    comp[u] = comp_id;
    for (int v : adj2[u]) {
        if (!vis[v]) {
            dfs2(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    // Build implication graph
    for (int i = 0; i < n; i++) {
        char c1, c2;
        int a, b;
        cin >> c1 >> a >> c2 >> b;

        // Map positive and negative literals
        if (c1 == '-') a = 2 * m - a + 1;
        if (c2 == '-') b = 2 * m - b + 1;

        int not_a = 2 * m - a + 1;
        int not_b = 2 * m - b + 1;

        // ¬a → b
        adj[not_a].push_back(b);
        adj2[b].push_back(not_a);

        // ¬b → a
        adj[not_b].push_back(a);
        adj2[a].push_back(not_b);
    }

    // First DFS (topological order)
    for (int i = 1; i <= 2 * m; i++) {
        if (!vis[i]) {
            dfs1(i);
        }
    }

    // Reset visited
    for (int i = 1; i <= 2 * m; i++) {
        vis[i] = false;
    }

    // Second DFS (SCC)
    for (int i = order.size() - 1; i >= 0; i--) {
        int node = order[i];
        if (!vis[node]) {
            comp_id++;
            dfs2(node);
        }
    }

    // Check for contradiction and assign values
    for (int i = 1; i <= m; i++) {
        int pos = i;
        int neg = 2 * m - i + 1;

        if (comp[pos] == comp[neg]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }

        value_ans[i] = (comp[pos] > comp[neg]);
    }

    // Output result
    for (int i = 1; i <= m; i++) {
        if (value_ans[i]) cout << "+ ";
        else cout << "- ";
    }

    return 0;
}