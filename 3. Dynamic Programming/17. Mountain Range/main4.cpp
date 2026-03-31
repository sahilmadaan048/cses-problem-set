#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<int> tree;

    SegTree(int n) {
        this->n = n;
        tree.assign(4*n, 0);
    }

    void update(int node, int start, int end, int idx, int val) {
        if(start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if(idx <= mid)
            update(2*node, start, mid, idx, val);
        else
            update(2*node+1, mid+1, end, idx, val);

        tree[node] = max(tree[2*node], tree[2*node+1]);
    }

    int query(int node, int start, int end, int l, int r) {
        if(r < start || end < l)
            return 0;
        if(l <= start && end <= r)
            return tree[node];
        int mid = (start + end) / 2;
        return max(query(2*node, start, mid, l, r),
                   query(2*node+1, mid+1, end, l, r));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> h(n);
    for(int i = 0; i < n; i++)
        cin >> h[i];

    vector<int> L(n, -1), R(n, n);
    stack<int> st;

    // Nearest greater on left
    for(int i = 0; i < n; i++) {
        while(!st.empty() && h[st.top()] <= h[i])
            st.pop();
        if(!st.empty())
            L[i] = st.top();
        st.push(i);
    }

    while(!st.empty()) st.pop();

    // Nearest greater on right
    for(int i = n-1; i >= 0; i--) {
        while(!st.empty() && h[st.top()] <= h[i])
            st.pop();
        if(!st.empty())
            R[i] = st.top();
        st.push(i);
    }

    // Sort indices by increasing height
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);

    sort(order.begin(), order.end(), [&](int a, int b) {
        return h[a] < h[b];
    });

    SegTree seg(n);
    vector<int> dp(n);
    int ans = 0;

    for(int i = 0; i < n;) {

        int j = i;

        // process same heights together
        while(j < n && h[order[j]] == h[order[i]])
            j++;

        // first compute dp
        for(int k = i; k < j; k++) {
            int idx = order[k];
            int left = L[idx] + 1;
            int right = R[idx] - 1;

            int best = 0;
            if(left <= right)
                best = seg.query(1, 0, n-1, left, right);

            dp[idx] = 1 + best;
            ans = max(ans, dp[idx]);
        }

        // then update segment tree
        for(int k = i; k < j; k++) {
            int idx = order[k];
            seg.update(1, 0, n-1, idx, dp[idx]);
        }

        i = j;
    }

    cout << ans;
}