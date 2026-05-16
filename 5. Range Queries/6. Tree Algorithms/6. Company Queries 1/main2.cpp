#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2e5 + 5;
const int LOG = 20; // because 2^20 > 1e6
int up[MAXN][LOG]; // up[node][j] = 2^j-th ancestor of node

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> parent(n + 1);
    parent[1] = -1;
    for (int i = 2; i <= n; i++) {
        cin >> parent[i];
    }

    // Precompute binary lifting table
    for (int v = 1; v <= n; v++) {
        up[v][0] = parent[v]; // 2^0-th ancestor
    }
    for (int j = 1; j < LOG; j++) {
        for (int v = 1; v <= n; v++) {
            if (up[v][j - 1] == -1)
                up[v][j] = -1;
            else
                up[v][j] = up[up[v][j - 1]][j - 1];
        }
    }

    // Answer queries
    while (q--) {
        int node, k;
        cin >> node >> k;
        for (int j = 0; j < LOG; j++) {
            if (k & (1LL << j)) {
                node = up[node][j];
                if (node == -1) break;
            }
        }
        cout << node << "\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    while (T--) solve();
    return 0;
}
