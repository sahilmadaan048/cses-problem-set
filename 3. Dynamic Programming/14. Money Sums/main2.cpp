#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> x(n);
    int max_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        max_sum += x[i];
    }

    vector<bool> dp(max_sum + 1, false);
    dp[0] = true;

    for (int i = 0; i < n; i++) {
        // Update dp in reverse order to avoid using one coin multiple times in the same iteration
        for (int s = max_sum - x[i]; s >= 0; s--) {
            if (dp[s]) dp[s + x[i]] = true;
        }
    }

    vector<int> res;
    for (int s = 1; s <= max_sum; s++) {
        if (dp[s]) res.push_back(s);
    }

    cout << (int)res.size() << "\n";
    for (int val : res) cout << val << " ";
    cout << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
