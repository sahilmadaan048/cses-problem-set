#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

struct Interval {
    int l, r, idx;
};

bool contains_cmp(const Interval &a, const Interval &b) {
    if (a.l == b.l)
        return a.r > b.r; // longer first
    return a.l < b.l;
}

bool contained_cmp(const Interval &a, const Interval &b) {
    if (a.l == b.l)
        return a.r < b.r; // shorter first
    return a.l < b.l;
}

// BIT for range sums
struct BIT {
    vector<int> bit;
    int n;
    BIT(int n) : n(n) {
        bit.assign(n + 2, 0);
    }

    void update(int x, int val) {
        while (x <= n) {
            bit[x] += val;
            x += x & -x;
        }
    }

    int query(int x) {
        int res = 0;
        while (x > 0) {
            res += bit[x];
            x -= x & -x;
        }
        return res;
    }

    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    int n;
    cin >> n;
    vector<Interval> intervals(n);
    vector<int> all_r;

    for (int i = 0; i < n; ++i) {
        cin >> intervals[i].l >> intervals[i].r;
        intervals[i].idx = i;
        all_r.push_back(intervals[i].r);
    }

    // Coordinate compression on r
    sort(all_r.begin(), all_r.end());
    all_r.erase(unique(all_r.begin(), all_r.end()), all_r.end());
    auto get_rid = [&](int r) {
        return lower_bound(all_r.begin(), all_r.end(), r) - all_r.begin() + 1;
    };

    // ----------------------
    // Part 1: Count contains
    // ----------------------
    sort(intervals.begin(), intervals.end(), contains_cmp);
    BIT bit(all_r.size());
    vector<int> contains(n);
    for (const auto &it : intervals) {
        int r_comp = get_rid(it.r);
        contains[it.idx] = bit.query(r_comp, all_r.size());
        bit.update(r_comp, 1);
    }

    // ----------------------
    // Part 2: Count contained
    // ----------------------
    sort(intervals.begin(), intervals.end(), contained_cmp);
    BIT bit2(all_r.size());
    vector<int> contained(n);
    for (int i = n - 1; i >= 0; --i) {
        int r_comp = get_rid(intervals[i].r);
        contained[intervals[i].idx] = bit2.query(r_comp);
        bit2.update(r_comp, 1);
    }

    for (int x : contained) cout << x << " ";
    cout << "\n";
    for (int x : contains) cout << x << " ";
    cout << "\n";

    return 0;
}



/*

 It used Fenwick Trees so next time touch it only when i am done with 
 topics like segment trees, fenwick trees, sparse table etc

*/