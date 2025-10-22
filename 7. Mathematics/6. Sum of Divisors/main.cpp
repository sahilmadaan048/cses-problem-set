#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
int MOD = 1e9 + 7;  // Hardcoded, directly change from here for functions!

// Modulo helper functions
void modadd(int &a, int b) { a = ((a % MOD) + (b % MOD)) % MOD; }
void modsub(int &a, int b) { a = ((a % MOD) - (b % MOD) + MOD) % MOD; }
void modmul(int &a, int b) { a = ((a % MOD) * (b % MOD)) % MOD; }

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // your code here
    ll n; cin >> n;
    ll sum = 0;
    for(int i=1; i*i<=n; i++) {
        // for each i check for its contributions for all the numebrs 
        int len = (n - i) / i + 1;
        modmul(len, i);
        modadd(sum , len);
        cout << sum << " ";
    }
    cout << sum << "\n";
    return 0;
}
