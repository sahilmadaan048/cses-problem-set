// https://cses.fi/problemset/task/1097


#include "bits/stdc++.h"
#define int long long
#define vi vector<int>
using namespace std;

// Recursive function to get max score first player can get
int calculate(int l, int r, const vi& a, bool firstTurn) {
    if (l > r) return 0;

    if (firstTurn) {
        // First player's turn: pick max of two options
        int pickLeft = a[l] + calculate(l + 1, r, a, false);
        int pickRight = a[r] + calculate(l, r - 1, a, false);
        return max(pickLeft, pickRight);
    } else {
        // Second player's turn: he plays optimally to minimize first's score
        int pickLeft = calculate(l + 1, r, a, true);
        int pickRight = calculate(l, r - 1, a, true);
        return min(pickLeft, pickRight);
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    cout << calculate(0, n - 1, a, true) << "\n";

    return 0;
}
