// https://cses.fi/problemset/task/3356

#include "bits/stdc++.h"
#define int long long
using namespace std;

const int INF = 1e18;

struct SegTree {

    int n;
    vector<int> tree;

    SegTree(int sz) {
        n = sz;
        tree.assign(4 * n, INF);
    }

    void build(int node, int l, int r,
               vector<int>& a) {

        if (l == r) {
            tree[node] = a[l];
            return;
        }

        int mid = (l + r) / 2;

        build(2 * node, l, mid, a);
        build(2 * node + 1, mid + 1, r, a);

        tree[node] =
            min(tree[2 * node],
                tree[2 * node + 1]);
    }

    void update(int node, int l, int r,
                int idx, int val) {

        if (l == r) {
            tree[node] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(2 * node, l, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, r,
                   idx, val);

        tree[node] =
            min(tree[2 * node],
                tree[2 * node + 1]);
    }

    int query(int node, int l, int r,
              int ql, int qr) {

        if (qr < l || r < ql)
            return INF;

        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) / 2;

        return min(
            query(2 * node, l, mid, ql, qr),
            query(2 * node + 1, mid + 1, r,
                  ql, qr)
        );
    }
};

void solve() {

    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    map<int, set<int>> pos;

    for (int i = 1; i <= n; i++)
        pos[a[i]].insert(i);

    vector<int> nxt(n + 1, INF);

    for (auto &[val, st] : pos) {

        vector<int> v(st.begin(), st.end());

        for (int i = 0; i + 1 < v.size(); i++)
            nxt[v[i]] = v[i + 1];
    }

    SegTree seg(n);

    seg.build(1, 1, n, nxt);

    auto erasePos = [&](int value, int idx) {

        auto &st = pos[value];

        auto it = st.find(idx);

        int prv = -1;
        int nx = -1;

        if (it != st.begin()) {
            auto t = prev(it);
            prv = *t;
        }

        auto t = next(it);

        if (t != st.end())
            nx = *t;

        st.erase(it);

        if (prv != -1) {
            seg.update(1, 1, n,
                       prv,
                       nx == -1 ? INF : nx);
        }
    };

    auto insertPos = [&](int value, int idx) {

        auto &st = pos[value];

        auto it = st.lower_bound(idx);

        int nx = -1;
        int prv = -1;

        if (it != st.end())
            nx = *it;

        if (it != st.begin()) {
            auto t = prev(it);
            prv = *t;
        }

        st.insert(idx);

        seg.update(1, 1, n,
                   idx,
                   nx == -1 ? INF : nx);

        if (prv != -1) {
            seg.update(1, 1, n,
                       prv,
                       idx);
        }
    };

    while (q--) {

        int type;
        cin >> type;

        if (type == 1) {

            int k, u;
            cin >> k >> u;

            erasePos(a[k], k);

            a[k] = u;

            insertPos(u, k);
        }

        else {

            int l, r;
            cin >> l >> r;

            int mn =
                seg.query(1, 1, n, l, r);

            if (mn <= r)
                cout << "NO\n";
            else
                cout << "YES\n";
        }
    }
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}