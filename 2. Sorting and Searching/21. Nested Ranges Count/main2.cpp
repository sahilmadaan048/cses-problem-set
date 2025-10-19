// // https://cses.fi/problemset/task/2169

// #include <bits/stdc++.h>
// using namespace std;

// struct Range {
//     int x, y, idx;
// };

// struct Fenwick {
//     vector<int> bit;
//     int n;
//     Fenwick(int n): n(n), bit(n+1, 0) {}
//     void update(int i, int val) {
//         for(; i<=n; i += (i&-i)) {
//             bit[i] += val;
//         }
//     }

//     int sum(int i) {
//         int s = 0;
//         for(; i>0; i -= (i & -i)) {
//             s += bit[i];
//         }
//         return s;
//     }
// };

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n; cin >> n;
//     vector<Range> v(n);
//     vector<int> ys;

//     for(int i=0; i<n; i++) {
//         cin >> v[i].x >> v[i].y;
//         v[i].idx = i;
//         ys.push_back(v[i].y);
//     }

//     // do coordinate compression here
//     sort(ys.begin(), ys.end());
//     // This removes duplicate elements from the vector ys
//     ys.erase(unique(ys.begin(), ys.end()), ys.end());
    
//     // lower_bound(ys.begin(), ys.end(), y) returns an iterator pointing to the first element ≥ y.
//     // Subtracting ys.begin() gives the 0-based index.
//     // Adding +1 makes it 1-based.
//     // getY(y) returns the compressed coordinate of y
//     auto getY = [&](int y) {
//         return (int)(lower_bound(ys.begin(), ys.end(), y) - ys.begin() + 1); 
//     };

//     // sort by s asc, y desc
//     sort(v.begin(), v.end(), [](auto &a, auto &b) {
//         if(a.x == b.x) {
//             return a.y > b.y;
//         } 
//         return a.x < b.x;
//     });

//     vector<int> contains(n), contained(n);
//     Fenwick bit(n);

//     // count "contains"
//     // process from right to left
//     for(int i=n-1; i>=0; i--) {
//         int pos = getY(v[i].y);
//         contains[v[i].idx] = pos;
//         bit.update(pos, 1);
//     }

//     // Reset BIT
//     bit = Fenwick(n);

//     // count "contained"
//     // process from left to right
//     for(int i=0; i<n; i++) {
//         int pos = getY(v[i].y);
//         contained[v[i].idx] = i - bit.sum(pos-1);
//         bit.update(pos, 1); 
//     }

//     for(auto x: contains) cout << x << " ";
//     cout << "\n";
//     for(auto x: contained) cout << x << " ";
//     cout << "\n";
// }

#include <bits/stdc++.h>
using namespace std;

struct Range {
    int x, y, idx;
};

struct Fenwick {
    vector<int> bit;
    int n;
    Fenwick(int n) : n(n), bit(n + 1, 0) {}
    void update(int i, int val) {
        for (; i <= n; i += i & -i)
            bit[i] += val;
    }
    int sum(int i) {
        int s = 0;
        for (; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Range> v(n);
    vector<int> ys;

    for (int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y;
        v[i].idx = i;
        ys.push_back(v[i].y);
    }

    // Coordinate compress y values
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    auto getY = [&](int y) {
        return (int)(lower_bound(ys.begin(), ys.end(), y) - ys.begin()) + 1;
    };

    // Sort by x asc, y desc
    sort(v.begin(), v.end(), [](auto &a, auto &b) {
        if (a.x == b.x) return a.y > b.y;
        return a.x < b.x;
    });

    vector<int> contains(n), contained(n);
    Fenwick bit(n);

    // Count "contains"
    // Process from right to left
    for (int i = n - 1; i >= 0; i--) {
        int pos = getY(v[i].y);
        contains[v[i].idx] = bit.sum(pos);
        bit.update(pos, 1);
    }

    // Reset BIT
    bit = Fenwick(n);

    // Count "contained"
    // Process from left to right
    for (int i = 0; i < n; i++) {
        int pos = getY(v[i].y);
        contained[v[i].idx] = i - bit.sum(pos - 1);
        bit.update(pos, 1);
    }

    for (int x : contains) cout << x << " ";
    cout << "\n";
    for (int x : contained) cout << x << " ";
    cout << "\n";
}
