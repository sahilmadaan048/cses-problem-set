#include "bits/stdc++.h"
#define int long long
#define vi vector<int>
#define vvi vector<vi>
using namespace std;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vvi dp(n, vi(n, 0));

    // base case: when l == r, only one element left
    for (int i = 0; i < n; ++i)
        dp[i][i] = a[i];

    for (int len = 2; len <= n; ++len) {
        for (int l = 0; l + len - 1 < n; ++l) {
            int r = l + len - 1;

            // if player picks left
            int left = a[l] + min(
                (l + 2 <= r ? dp[l + 2][r] : 0),
                (l + 1 <= r - 1 ? dp[l + 1][r - 1] : 0)
            );

            // if player picks right
            int right = a[r] + min(
                (l <= r - 2 ? dp[l][r - 2] : 0),
                (l + 1 <= r - 1 ? dp[l + 1][r - 1] : 0)
            );

            dp[l][r] = max(left, right);
        }
    }

    cout << dp[0][n - 1] << '\n';

    return 0;
}
