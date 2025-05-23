#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int i = 0; i < n; ++i) cin >> grid[i];

    // dp[i][j] stores the lexicographically smallest path from (0, 0) to (i, j)
    vector<vector<string>> dp(n, vector<string>(n));

    dp[0][0] = string(1, grid[0][0]);

    // Fill first row
    for (int j = 1; j < n; ++j)
        dp[0][j] = dp[0][j-1] + grid[0][j];

    // Fill first column
    for (int i = 1; i < n; ++i)
        dp[i][0] = dp[i-1][0] + grid[i][0];

    // Fill the rest
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            string from_top = dp[i-1][j] + grid[i][j];
            string from_left = dp[i][j-1] + grid[i][j];
            dp[i][j] = min(from_top, from_left);
        }
    }

    cout << dp[n-1][n-1] << endl;
}


int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
