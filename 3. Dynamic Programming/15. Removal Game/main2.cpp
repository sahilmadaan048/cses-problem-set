#include "bits/stdc++.h"
#define int long long
#define vi vector<int>
#define vvi vector<vi>
using namespace std;

int calculate(int l, int r, const vi &a, vvi &dp)
{
    if (l > r)
        return 0;
    if (dp[l][r] != -1)
        return dp[l][r];

    // First player's turn always at this level (we calculate only for first player's optimal)
    // Second player is greedy to minimize first player's gain
    int pickLeft = a[l] + min(calculate(l + 2, r, a, dp), calculate(l + 1, r - 1, a, dp));
    int pickRight = a[r] + min(calculate(l + 1, r - 1, a, dp), calculate(l, r - 2, a, dp));

    return dp[l][r] = max(pickLeft, pickRight);
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vvi dp(n, vi(n, -1));
    cout << calculate(0, n - 1, a, dp) << "\n";

    return 0;
}
