#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    int sum = n * (n + 1) / 2;
    if (sum & 1) {
        cout << 0 << "\n";
        return 0;
    }
    int target = sum / 2;
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = target; j >= i; j--) {
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }

    cout << (dp[target] * 1LL * ((MOD + 1) / 2)) % MOD << "\n"; // divide by 2
    return 0;
}
