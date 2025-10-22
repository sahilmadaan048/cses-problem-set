// https://cses.fi/problemset/task/1731

#include "bits/stdc++.h"
#define int long long
using namespace std;
int MOD = 1e9 + 7;  // Hardcoded, directly change from here for functions!

// Modulo helper functions
void modadd(int &a, int b) { a = ((a % MOD) + (b % MOD)) % MOD; }
void modsub(int &a, int b) { a = ((a % MOD) - (b % MOD) + MOD) % MOD; }
void modmul(int &a, int b) { a = ((a % MOD) * (b % MOD)) % MOD; }

// Recursive brute-force function to count ways
void checkAll(string t, string &s, vector<string> &temp, int &cnt) {
    // If current string t matches s completely -> one valid way
    if (t == s) {
        modadd(cnt, 1);
        return;
    }

    if (t.size() > s.size()) return;

    // Try to add each word (unbounded recursion)
    for (int i = 0; i < temp.size(); i++) {
        // We only try adding a word if it fits the current prefix of s
        int len = temp[i].size();
        if (s.substr(0, t.size() + len).rfind(t + temp[i], 0) == 0) {
            // Means t + temp[i] still matches the prefix of s
            checkAll(t + temp[i], s, temp, cnt);
        }
    }
}

void solve() {
    string s;
    cin >> s;  
    int n = s.size();

    int k;
    cin >> k; 
    vector<string> temp(k);
    for (int i = 0; i < k; i++) {
        cin >> temp[i];
    }

    int cnt = 0;
    string t = "";
    checkAll(t, s, temp, cnt);

    cout << cnt << "\n";
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
