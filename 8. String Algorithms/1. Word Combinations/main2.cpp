#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    int k;
    cin >> k;
    vector<string> words(k);
    for (int i = 0; i < k; i++) cin >> words[i];

    vector<int> dp(n + 1, 0);
    dp[0] = 1; // Empty prefix

    for (int i = 0; i < n; i++) {
        if (!dp[i]) continue;
        for (auto &w : words) {
            int len = w.size();
            if (i + len <= n && s.substr(i, len) == w) {
                dp[i + len] = (dp[i + len] + dp[i]) % MOD;
            }
        }
    }

    cout << dp[n] % MOD << "\n";
}
