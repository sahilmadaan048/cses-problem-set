// https://cses.fi/problemset/task/2134
// Path Queries II

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 200005;

int n, q;
vector<int> adj[MAXN];
int val[MAXN];

int parent[MAXN], depth[MAXN], heavy[MAXN], head[MAXN], pos[MAXN];
int subtree[MAXN];

int cur_pos = 0;

// ---------- ITERATIVE DFS ----------
void dfs(int root = 1) {

    stack<int> st;
    vector<int> order;

    parent[root] = 0;
    depth[root] = 0;
    st.push(root);

    // First pass: build order
    while (!st.empty()) {
        int v = st.top(); st.pop();
        order.push_back(v);

        for (int u : adj[v]) {
            if (u == parent[v]) continue;
            parent[u] = v;
            depth[u] = depth[v] + 1;
            st.push(u);
        }
    }

    // Second pass: compute subtree sizes bottom-up
    for (int i = order.size() - 1; i >= 0; i--) {
        int v = order[i];
        subtree[v] = 1;
        heavy[v] = 0;

        int max_size = 0;

        for (int u : adj[v]) {
            if (u == parent[v]) continue;

            subtree[v] += subtree[u];

            if (subtree[u] > max_size) {
                max_size = subtree[u];
                heavy[v] = u;
            }
        }
    }
}

// ---------- HLD ----------
void decompose(int root = 1) {

    stack<pair<int,int>> st;
    st.push({root, root});

    while (!st.empty()) {
        auto [v, h] = st.top();
        st.pop();

        // Go down heavy path
        while (v) {
            head[v] = h;
            pos[v] = ++cur_pos;

            // Push light children
            for (int u : adj[v]) {
                if (u != parent[v] && u != heavy[v]) {
                    st.push({u, u});
                }
            }

            v = heavy[v];
        }
    }
}


// ---------- ITERATIVE SEGMENT TREE ----------
vector<int> seg;

void seg_build(vector<int> &base) {
    seg.assign(2*n, 0);
    for (int i = 0; i < n; i++)
        seg[n+i] = base[i+1];

    for (int i = n-1; i > 0; i--)
        seg[i] = max(seg[i<<1], seg[i<<1|1]);
}

void seg_update(int p, int value) {
    p = p + n - 1;
    seg[p] = value;
    for (p >>= 1; p > 0; p >>= 1)
        seg[p] = max(seg[p<<1], seg[p<<1|1]);
}

int seg_query(int l, int r) {
    l = l + n - 1;
    r = r + n - 1;

    int res = LLONG_MIN;

    while (l <= r) {
        if (l & 1) res = max(res, seg[l++]);
        if (!(r & 1)) res = max(res, seg[r--]);
        l >>= 1;
        r >>= 1;
    }

    return res;
}

// ---------- PATH QUERY ----------
int query_path(int a, int b) {

    int res = LLONG_MIN;

    while (head[a] != head[b]) {
        if (depth[head[a]] < depth[head[b]])
            swap(a, b);

        res = max(res,
                  seg_query(pos[head[a]], pos[a]));

        a = parent[head[a]];
    }

    if (depth[a] > depth[b])
        swap(a, b);

    res = max(res,
              seg_query(pos[a], pos[b]));

    return res;
}


int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> val[i];

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    decompose(1);

    vector<int> base(n+1);
    for (int i = 1; i <= n; i++)
        base[pos[i]] = val[i];

    seg_build(base);

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int s, x;
            cin >> s >> x;
            seg_update(pos[s], x);
        }
        else {
            int a, b;
            cin >> a >> b;
            cout << query_path(a, b) << "\n";
        }
    }

    return 0;
}