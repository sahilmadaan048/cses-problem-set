// https://cses.fi/problemset/task/2413

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int md = 1e9+7;
const int mxN = 1e6+6;

// Precompute results up to mxN using only two pairs of variables
vector<int> total(mxN);

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    // Base case
    int prev1 = 1, prev2 = 1; // dp[1][1], dp[1][2]
    total[1] = (prev1 + prev2) % md;

    for (int i = 2; i < mxN; i++) {
        int curr1 = (prev1 * 4 % md + prev2) % md;
        int curr2 = (prev1 + prev2 * 2 % md) % md;
        total[i] = (curr1 + curr2) % md;

        prev1 = curr1;
        prev2 = curr2;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << total[n] << endl;
    }
}