#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int dp[501][125251]; // dp[i][currSum]

int recur(int i, int currSum, int target, int n) {
    if (currSum > target) return 0;
    if (i > n) return (currSum == target ? 1 : 0);
    if (dp[i][currSum] != -1) return dp[i][currSum];

    int pick = recur(i + 1, currSum + i, target, n);
    int skip = recur(i + 1, currSum, target, n);
    return dp[i][currSum] = (pick + skip) % MOD;
}

int main() {
    int n;
    cin >> n;
    int sum = n * (n + 1) / 2;
    if (sum & 1) {
        cout << 0 << "\n";
        return 0;
    }
    int target = sum / 2;
    memset(dp, -1, sizeof(dp));
    int ways = recur(1, 0, target, n);
    cout << (ways * 1LL * ((MOD + 1) / 2)) % MOD << "\n"; // divide by 2 using modular inverse
    return 0;
}
