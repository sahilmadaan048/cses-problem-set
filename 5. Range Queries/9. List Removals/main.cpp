// Author - sahilmadaan048


// https://cses.fi/problemset/task/1749

#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
vector<int> arr;
vector<int> seg;

void build(int idx, int l, int r) {
    if (l == r) {
        seg[idx] = 1;  
        return;
    }
    int mid = (l + r) / 2;
    build(2*idx, l, mid);
    build(2*idx+1, mid+1, r);
    seg[idx] = seg[2*idx] + seg[2*idx+1];
}

void update(int idx, int l, int r, int pos) {
    if (l == r) {
        seg[idx] = 0;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) {
        update(2*idx, l, mid, pos);
    }
    else {
        update(2*idx+1, mid+1, r, pos);
    }

    seg[idx] = seg[2*idx] + seg[2*idx+1];
}

int query(int idx, int l, int r, int k) {
    if (l == r) {
        return l;
    }

    int mid = (l + r) / 2;

    if (seg[2*idx] >= k) {  
        return query(2*idx, l, mid, k);
    }
    else {
        return query(2*idx+1, mid+1, r, k - seg[2*idx]);
    }
}

signed main() {
    cin >> n;

    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    seg.resize(4*n);
    build(1, 0, n-1);

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        int pos = query(1, 0, n-1, k);
        cout << arr[pos] << " ";

        update(1, 0, n-1, pos);
    }
}