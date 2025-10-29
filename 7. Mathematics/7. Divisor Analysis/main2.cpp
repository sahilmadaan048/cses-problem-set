// https://cses.fi/problemset/task/2182
#include "bits/stdc++.h"
using namespace std;
#define int long long
const int MOD = 1e9+7;

// fast modular exponentiation
int modpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int modinv(int a) {
    return modpow(a, MOD - 2); // Fermat's Little Theorem
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> primes(n);
    for (auto &p : primes) cin >> p.first >> p.second;

    int num_divisors = 1;
    int sum_divisors = 1;
    int product_divisors = 1;

    int total_divisors = 1; // d(n)

    // number of divisors
    for (auto [p, e] : primes)
        num_divisors = num_divisors * (e + 1) % MOD;

    // sum of divisors
    for (auto [p, e] : primes) {
        int numerator = (modpow(p, e + 1) - 1 + MOD) % MOD;
        int denominator = modinv(p - 1);
        sum_divisors = sum_divisors * (numerator * denominator % MOD) % MOD;
    }

    // product of divisors
    // formula: n^(d(n)/2)
    // but we must handle large exponents mod (MOD-1) due to Fermat
    int exp_mod = 1;
    int phi = MOD - 1; // for exponent reduction mod φ(MOD)
    for (auto [p, e] : primes)
        exp_mod = exp_mod * (e + 1) % phi;

    int exp = 1;
    for (auto [p, e] : primes) {
        int power = e * exp_mod / 2 % (MOD - 1);
        product_divisors = product_divisors * modpow(p, power) % MOD;
    }

    cout << num_divisors << " " << sum_divisors << " " << product_divisors << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
