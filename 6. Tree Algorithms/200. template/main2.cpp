// CSES - Distinct Colors
// Euler Tour + Offline Queries + Fenwick

#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
vector<int> adj[N];
int color[N];

int tin[N], tout[N], timer;
int flat[N];

int bit[N];
int ans[N];

void update(int i, int v) {
    for (; i <= n; i += i & -i)
        bit[i] += v;
}

int query(int i) {
    int s = 0;
    for (; i > 0; i -= i & -i)
        s += bit[i];
    return s;
}

void dfs(int u, int p) {
    tin[u] = ++timer;
    flat[timer] = u;

    for (int v : adj[u])
        if (v != p)
            dfs(v, u);

    tout[u] = timer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> color[i];

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    // queries: (R, L, node)
    vector<tuple<int,int,int>> queries;
    for (int i = 1; i <= n; i++)
        queries.push_back({tout[i], tin[i], i});

    sort(queries.begin(), queries.end());

    unordered_map<int,int> last;
    int ptr = 1;

    for (auto [R, L, node] : queries) {

        while (ptr <= R) {
            int u = flat[ptr];
            int c = color[u];

            if (last.count(c))
                update(last[c], -1);

            update(ptr, 1);
            last[c] = ptr;
            ptr++;
        }

        ans[node] = query(R) - query(L - 1);
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";

    return 0;
}