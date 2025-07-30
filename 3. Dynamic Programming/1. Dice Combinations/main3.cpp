// https://cses.fi/problemset/task/1633

#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve() {
    int n;
    cin >> n;

    vector<int> window(6, 0);  // only store last 6 values
    window[0] = 1;  // base case: dp[0] = 1

    for (int i = 1; i <= n; i++) {
        int ways = 0;
        for (int j = 1; j <= 6; j++) {
            if (i - j >= 0) {
                ways = (ways + window[(6 + (i - j) % 6) % 6]) % mod;
            }
        }
        window[i % 6] = ways;  // overwrite oldest value in rolling window
    }

    cout << window[n % 6] << "\n";
}


int main() {
    fast;
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
