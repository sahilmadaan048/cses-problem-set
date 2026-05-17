// https://cses.fi/problemset/task/1736
// Author - sahilmadaan048

#include "bits/stdc++.h"
#define int long long
using namespace std;

struct SegTree {

    int n;

    vector<int> tree;

    // lazy: A*i + B
    vector<int> lazyA, lazyB;

    SegTree(int sz) {

        n = sz;

        tree.resize(4 * n);

        lazyA.assign(4 * n, 0);
        lazyB.assign(4 * n, 0);
    }

    int sumIndex(int l, int r) {

        return (l + r) * (r - l + 1) / 2;
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
            tree[2 * node]
          + tree[2 * node + 1];
    }

    void apply(int node, int l, int r,
               int A, int B) {

        tree[node] +=
            A * sumIndex(l, r)
          + B * (r - l + 1);

        lazyA[node] += A;
        lazyB[node] += B;
    }

    void push(int node, int l, int r) {

        if (l == r)
            return;

        int mid = (l + r) / 2;

        if (lazyA[node] != 0 ||
            lazyB[node] != 0) {

            apply(2 * node,
                  l, mid,
                  lazyA[node],
                  lazyB[node]);

            apply(2 * node + 1,
                  mid + 1, r,
                  lazyA[node],
                  lazyB[node]);

            lazyA[node] = 0;
            lazyB[node] = 0;
        }
    }

    void update(int node, int l, int r,
                int ql, int qr,
                int A, int B) {

        if (qr < l || r < ql)
            return;

        if (ql <= l && r <= qr) {

            apply(node, l, r, A, B);

            return;
        }

        push(node, l, r);

        int mid = (l + r) / 2;

        update(2 * node, l, mid,
               ql, qr, A, B);

        update(2 * node + 1,
               mid + 1, r,
               ql, qr, A, B);

        tree[node] =
            tree[2 * node]
          + tree[2 * node + 1];
    }

    int query(int node, int l, int r,
              int ql, int qr) {

        if (qr < l || r < ql)
            return 0;

        if (ql <= l && r <= qr)
            return tree[node];

        push(node, l, r);

        int mid = (l + r) / 2;

        return
            query(2 * node, l, mid,
                  ql, qr)
          + query(2 * node + 1,
                  mid + 1, r,
                  ql, qr);
    }
};

void solve() {

    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    SegTree seg(n);

    seg.build(1, 1, n, a);

    while (q--) {

        int type;
        cin >> type;

        int l, r;
        cin >> l >> r;

        if (type == 1) {

            // add (i-l+1)
            // = i + (1-l)

            seg.update(1, 1, n,
                       l, r,
                       1,
                       1 - l);
        }

        else {

            cout << seg.query(1, 1, n,
                              l, r)
                 << '\n';
        }
    }
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}