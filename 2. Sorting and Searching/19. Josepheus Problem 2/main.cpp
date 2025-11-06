// https://cses.fi/problemset/task/2163

// CSES
// Sahik —  
// Shared code
// Link to this code: https://cses.fi/paste/b4cddac4c54840ecbd527e/
#include <bits/stdc++.h>
using namespace std;
 
// Fenwick Tree (Binary Indexed Tree)
struct Fenwick {
    vector<int> tree;
    int size;
 
    Fenwick(int n) {
        size = n;
        tree.assign(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            update(i, 1);
        }
    }
 
    void update(int idx, int delta) {
        while (idx <= size) {
            tree[idx] += delta;
            idx += idx & -idx;
        }
    }
 
    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
 
    int findKth(int k) {
        int low = 1, high = size;
        while (low < high) {
            int mid = (low + high) / 2;
            if (query(mid) >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, k;
    cin >> n >> k;
 
    Fenwick fw(n);
    int pos = 0;
 
    for (int i = 1; i <= n; i++) {
        pos = (pos + k) % (n - i + 1); // Calculate the next position to remove
        int child = fw.findKth(pos + 1); // Find the (pos + 1)-th remaining child
        cout << child << " "; // Print the removed child
        fw.update(child, -1); // Remove the child from the tree
    }
 
    cout << endl;
    return 0;
}