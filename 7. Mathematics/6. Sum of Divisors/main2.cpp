#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

// Modulo helper functions
void modadd(int &a, int b) { a = ((a % MOD) + (b % MOD)) % MOD; }
void modsub(int &a, int b) { a = ((a % MOD) - (b % MOD) + MOD) % MOD; }
void modmul(int &a, int b) { a = ((a % MOD) * (b % MOD)) % MOD; }

// Function to compute sum of numbers from L to R modulo MOD
int rangeSum(int L, int R) {
    int cnt = (R - L + 1) % MOD;
    int total = ((L + R) % MOD * cnt) % MOD;
    // divide by 2 using modular inverse of 2
    return (total * ((MOD + 1) / 2)) % MOD;
}

int32_t main() {
    int n; cin >> n;
    int ans = 0 ;
    int i = 1;
 
    while(i <= n) {
        int q = n / i;
        int R = n / q;
        int sumLR = rangeSum(i, R);
        int contrib = (sumLR * (q % MOD)) % MOD;
        modadd(ans, contrib);
        i = R + 1;
    }
 
    cout << ans << "\n";
    return 0;
}