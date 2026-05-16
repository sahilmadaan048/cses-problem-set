// https://cses.fi/problemset/task/3163
// Author - sahilmadaan048

// ACCEPTED

#include "bits/stdc++.h"
#define int long long
using namespace std;

struct Fenwick {

    int n;
    vector<int> bit;

    Fenwick(int sz) {
        n = sz;
        bit.assign(n + 1, 0);
    }

    void add(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    int sum(int idx) {

        int res = 0;

        for (; idx > 0; idx -= idx & -idx)
            res += bit[idx];

        return res;
    }

    int rangeSum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

struct Query {
    int k, l, r, id, sign;

    bool operator<(const Query& other) const {
        return k < other.k;
    }
};

void solve() {

    int n, q;
    cin >> n >> q;

    vector<pair<int,int>> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(a.begin(), a.end());

    vector<Query> queries;

    for (int i = 0; i < q; i++) {

        int l, r, c, d;
        cin >> l >> r >> c >> d;

        queries.push_back({d, l, r, i, +1});
        queries.push_back({c - 1, l, r, i, -1});
    }

    sort(queries.begin(), queries.end());

    Fenwick bit(n);

    vector<int> ans(q, 0);

    int ptr = 0;

    for (auto &qq : queries) {

        while (ptr < n && a[ptr].first <= qq.k) {

            bit.add(a[ptr].second, 1);
            ptr++;
        }

        int cnt = bit.rangeSum(qq.l, qq.r);

        ans[qq.id] += qq.sign * cnt;
    }

    for (int x : ans)
        cout << x << '\n';
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}