// https://cses.fi/problemset/task/2134
// Author - sahilmadaan048

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e5 + 5;

int n, q;
vector<int> adj[MAXN];
int val[MAXN];

// HLD arrays
int parent[MAXN], depth[MAXN], heavy[MAXN], head[MAXN], pos[MAXN];
int subtree[MAXN];
int cur_pos = 0;

// Segment Tree
int seg[4 * MAXN];

int dfs(int v, int p) {
    parent[v] = p;
    subtree[v] = 1;
    int max_size = 0;

    for (int u : adj[v]) {
        if (u == p) continue;
        depth[u] = depth[v] + 1;
        int size = dfs(u, v);
        subtree[v] += size;

        if (size > max_size) {
            max_size = size;
            heavy[v] = u;
        }
    }
    return subtree[v];
}

void decompose(int v, int h) {
    head[v] = h;
    pos[v] = ++cur_pos;

    if (heavy[v]) {
        decompose(heavy[v], h);
    }

    for (int u : adj[v]) {
        if (u == parent[v] || u == heavy[v]) continue;
        decompose(u, u);
    }
}

// Segment Tree functions
void build(int idx, int l, int r) {
    if (l == r) {
        seg[idx] = val[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);
    seg[idx] = max(seg[2 * idx], seg[2 * idx + 1]);
}

void update(int idx, int l, int r, int p, int value) {
    if (l == r) {
        seg[idx] = value;
        return;
    }
    int mid = (l + r) / 2;
    if (p <= mid) {
        update(2 * idx, l, mid, p, value);
    }
    else {
        update(2 * idx + 1, mid + 1, r, p, value);
    }

    seg[idx] = max(seg[2 * idx], seg[2 * idx + 1]);
}

int query(int idx, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return -1e18;
    if (ql <= l && r <= qr) return seg[idx];
    int mid = (l + r) / 2;
    return max(
        query(2 * idx, l, mid, ql, qr),
        query(2 * idx + 1, mid + 1, r, ql, qr)
    );
}

int query_path(int a, int b) {
    int res = -1e18;

    while (head[a] != head[b]) {
        if (depth[head[a]] < depth[head[b]]) {
            swap(a, b);
        }

        res = max(res, query(1, 1, n, pos[head[a]], pos[a]));
        a = parent[head[a]];
    }

    if (depth[a] > depth[b]) swap(a, b);

    res = max(res, query(1, 1, n, pos[a], pos[b]));
    return res;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    decompose(1, 1);

    // Rearrange values according to position
    vector<int> temp(n + 1);
    for (int i = 1; i <= n; i++) {
        temp[pos[i]] = val[i];
    }
    for (int i = 1; i <= n; i++) {
        val[i] = temp[i];
    }

    build(1, 1, n);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int s, x;
            cin >> s >> x;
            update(1, 1, n, pos[s], x);
        }
        else {
            int a, b;
            cin >> a >> b;
            cout << query_path(a, b) << " ";
        }
    }
    cout << "\n";
}