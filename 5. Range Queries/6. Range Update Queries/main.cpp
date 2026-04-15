// Author - sahilmadaan048
// https://cses.fi/problemset/task/1651
// CSES - Range Update Queries (1651)

#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> seg, lazy;

void build(int index, int low, int high, vector<int>& arr) {
    if (low == high) {
        seg[index] = arr[low];
        return;
    }

    int mid = (low + high) / 2;

    build(2*index+1, low, mid, arr);
    build(2*index+2, mid+1, high, arr);

    seg[index] = 0;  // we don't actually need range sums
}

void push(int index, int low, int high) {
    if (lazy[index] != 0) {
        seg[index] += lazy[index];

        if (low != high) { // not a leaf
            lazy[2*index+1] += lazy[index];
            lazy[2*index+2] += lazy[index];
        }

        lazy[index] = 0;
    }
}

void update(int index, int low, int high, int l, int r, int val) {
    push(index, low, high);

    if (high < l || low > r)
        return;

    if (low >= l && high <= r) {
        lazy[index] += val;
        push(index, low, high);
        return;
    }

    int mid = (low + high) / 2;

    update(2*index+1, low, mid, l, r, val);
    update(2*index+2, mid+1, high, l, r, val);
}

int query(int index, int low, int high, int pos) {
    push(index, low, high);

    if (low == high)
        return seg[index];

    int mid = (low + high) / 2;

    if (pos <= mid)
        return query(2*index+1, low, mid, pos);
    else
        return query(2*index+2, mid+1, high, pos);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    seg.resize(4*n);
    lazy.resize(4*n, 0);

    build(0, 0, n-1, arr);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            a--; b--;

            update(0, 0, n-1, a, b, u);
        }
        else {
            int k;
            cin >> k;
            k--;

            cout << query(0, 0, n-1, k) << "\n";
        }
    }

    return 0;
}