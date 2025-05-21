#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

// Recursive function with memoization
ll countWays(ll X, vector<ll>& coins, vector<ll>& dp) {
    // Base Case: Only one way to form sum 0 — use nothing
    if (X == 0) return 1;

    // If already computed
    if (dp[X] != -1) return dp[X];

    ll ways = 0;

    for (ll coin : coins) {
        if (X - coin >= 0) {
            ways = (ways + countWays(X - coin, coins, dp)) % mod;
        }
    }

    return dp[X] = ways;
}

int main() {
    ll N, X; cin >> N >> X;
    vector<ll> coins(N);
    for(int i=0; i<N; i++) cin >> coins[i];
    vector<ll> dp(X + 1, -1);  // Initialize dp with -1
    cout << countWays(X, coins, dp) << "\n";
    return 0;
}
