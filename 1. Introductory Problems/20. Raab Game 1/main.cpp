// https://cses.fi/problemset/task/3399


#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        // If points exceed rounds or only one player has positive points, it's impossible
        if (a + b > n || (a == 0 && b > 0) || (b == 0 && a > 0)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            // If both a and b are 0, every round is a tie
            if (a == 0 && b == 0) {
                // Print identical sequences 1..n for both players
                for (int i = 1; i <= n; i++) {
                    cout << i << (i == n ? '\n' : ' ');
                }
                for (int i = 1; i <= n; i++) {
                    cout << i << (i == n ? '\n' : ' ');
                }
            } else {
                // Number of tie rounds
                int ties = n - (a + b);
                int n2 = a + b; 
                vector<int> perm(n2);
                // Construct permutation perm[0..n2-1] for second player to achieve a,b
                if (a >= b) {
                    // Build a cycle of length (a-b+2) to adjust difference
                    int L = a - b + 2;
                    perm[0] = L;                 // position 1 -> L
                    for (int i = 2; i <= L; i++) {
                        perm[i-1] = i - 1;       // position i -> i-1
                    }
                    // Fill remaining positions with 2-cycles
                    for (int i = L + 1; i < n2; i += 2) {
                        perm[i-1] = i + 1;       // i -> i+1
                        perm[i]   = i;           // i+1 -> i
                    }
                } else {
                    // b > a: Build a cycle of length (b-a+2)
                    int L = b - a + 2;
                    for (int i = 1; i < L; i++) {
                        perm[i-1] = i + 1;       // position i -> i+1
                    }
                    perm[L-1] = 1;               // position L -> 1
                    // Fill remaining with 2-cycles
                    for (int i = L + 1; i < n2; i += 2) {
                        perm[i-1] = i + 1;
                        perm[i]   = i;
                    }
                }
                // Print first player's sequence (1..n)
                for (int i = 1; i <= n; i++) {
                    cout << i << (i == n ? '\n' : ' ');
                }
                // Print second player's sequence
                // Non-tie part (length n2)
                for (int i = 1; i <= n2; i++) {
                    cout << perm[i-1] << (i == n2 && ties == 0 ? '\n' : ' ');
                }
                // Tie part (the last 'ties' rounds, identical cards)
                for (int val = n2 + 1; val <= n; val++) {
                    cout << val << (val == n ? '\n' : ' ');
                }
            }
        }
    }
    return 0;
}
