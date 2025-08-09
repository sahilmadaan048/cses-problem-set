// https://cses.fi/problemset/task/1145


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> temp(n);
    for (int i = 0; i < n; i++) cin >> temp[i];

    // dp[ind][prev+1] = LIS length from index 'ind' with previous index 'prev'
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int prev = ind - 1; prev >= -1; prev--) {
            int notTake = dp[ind + 1][prev + 1];
            int take = 0;
            if (prev == -1 || temp[ind] > temp[prev]) {
                take = 1 + dp[ind + 1][ind + 1];
            }
            dp[ind][prev + 1] = max(take, notTake);
        }
    }

    cout << dp[0][0] << "\n";
    return 0;
}
