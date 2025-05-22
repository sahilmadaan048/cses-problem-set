#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);

void solve() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    vector<int> dp(n, 0);

    // Initialize first cell
    dp[0] = (grid[0][0] == '*') ? 0 : 1;

    for (int i = 0; i < n; i++) {
        vector<int> new_dp(n, 0);  // current row

        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '*') {
                new_dp[j] = 0;
                continue;
            }

            if (i == 0 && j == 0) {
                new_dp[j] = 1;
                continue;
            }

            int from_top = (i > 0) ? dp[j] : 0;
            int from_left = (j > 0) ? new_dp[j - 1] : 0;

            new_dp[j] = (from_top + from_left) % mod;
        }

        dp = new_dp;  // move to next row
    }

    cout << dp[n - 1] << '\n';
}

int main() {
    fast;
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
