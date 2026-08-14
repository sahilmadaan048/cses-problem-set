// https://cses.fi/problemset/task/3227

// Author - sahilmadaan048

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Line {
    ll m, c;

    ll eval(ll x) const {
        return m * x + c;
    }

    bool operator<(const Line& other) const {
        if (m != other.m) return m < other.m;
        return c < other.c;
    }
};

struct Hull {
    vector<Line> v;

    bool bad(const Line& a, const Line& b, const Line& c) {
        return (__int128)(b.c - a.c) * (b.m - c.m)
             >= (__int128)(c.c - b.c) * (a.m - b.m);
    }

    void build(vector<Line>& lines) {
        if (lines.empty()) return;

        sort(lines.begin(), lines.end());

        vector<Line> tmp;

        for (auto l : lines) {
            if (!tmp.empty() && tmp.back().m == l.m) {
                if (tmp.back().c >= l.c) continue;
                tmp.pop_back();
            }
            tmp.push_back(l);
        }

        for (auto l : tmp) {
            while (v.size() >= 2 &&
                   bad(v[v.size() - 2], v.back(), l)) {
                v.pop_back();
            }
            v.push_back(l);
        }
    }

    ll query(ll x) const {
        if (v.empty()) return LLONG_MIN;

        int l = 0, r = (int)v.size() - 1;

        while (l < r) {
            int mid = (l + r) / 2;

            if (v[mid].eval(x) <= v[mid + 1].eval(x))
                l = mid + 1;
            else
                r = mid;
        }

        return v[l].eval(x);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<ll> h(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> h[i];

    // Previous strictly smaller
    vector<int> prv(n + 1), nxt(n + 1);
    stack<int> st;

    for (int i = 1; i <= n; i++) {
        while (!st.empty() && h[st.top()] >= h[i])
            st.pop();

        prv[i] = st.empty() ? 0 : st.top();
        st.push(i);
    }

    while (!st.empty()) st.pop();

    // Next strictly smaller
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && h[st.top()] >= h[i])
            st.pop();

        nxt[i] = st.empty() ? n + 1 : st.top();
        st.push(i);
    }

    int W = n - k + 1;

    // Segment tree containing lines.
    vector<vector<Line>> seg(4 * W);

    auto add_line = [&](int ql, int qr, Line line) {
        if (ql > qr) return;

        function<void(int,int,int)> add =
            [&](int node, int l, int r) {
                if (ql <= l && r <= qr) {
                    seg[node].push_back(line);
                    return;
                }

                int mid = (l + r) / 2;

                if (ql <= mid)
                    add(node * 2, l, mid);

                if (qr > mid)
                    add(node * 2 + 1, mid + 1, r);
            };

        add(1, 1, W);
    };

    auto add_piece = [&](int l, int r, Line line) {
        l = max(l, 1);
        r = min(r, W);

        if (l <= r)
            add_line(l, r, line);
    };

    /*
        For every board i:

        a = first position after previous smaller
        b = last position before next smaller

        x must also satisfy:
            i-k+1 <= x <= i
    */

    for (int i = 1; i <= n; i++) {
        ll H = h[i];

        int a = prv[i] + 1;
        int b = nxt[i] - 1;

        int lo = i - k + 1;
        int hi = i;

        int q = b - k + 1;

        // Case 1:
        // x <= a and x <= q
        // area = H*x + H*(k-a)
        add_piece(
            lo,
            min({hi, a, q}),
            {H, H * (k - a)}
        );

        // Case 2:
        // x <= a and x > q
        // area = H*(b-a+1)
        add_piece(
            max(lo, q + 1),
            min(hi, a),
            {0, H * (b - a + 1LL)}
        );

        // Case 3:
        // x > a and x <= q
        // area = H*k
        add_piece(
            max(lo, a + 1),
            min(hi, q),
            {0, H * k}
        );

        // Case 4:
        // x > a and x > q
        // area = H*(b-x+1)
        add_piece(
            max({lo, a + 1, q + 1}),
            hi,
            {-H, H * (b + 1LL)}
        );
    }

    // Build convex hulls.
    vector<Hull> hull(4 * W);

    for (int i = 1; i < 4 * W; i++) {
        if (!seg[i].empty())
            hull[i].build(seg[i]);
    }

    // Query all window starts.
    for (int x = 1; x <= W; x++) {
        ll ans = 0;

        int node = 1, l = 1, r = W;

        while (true) {
            if (!hull[node].v.empty())
                ans = max(ans, hull[node].query(x));

            if (l == r)
                break;

            int mid = (l + r) / 2;

            if (x <= mid) {
                node *= 2;
                r = mid;
            } else {
                node = node * 2 + 1;
                l = mid + 1;
            }
        }

        cout << ans << (x == W ? '\n' : ' ');
    }

    return 0;
}