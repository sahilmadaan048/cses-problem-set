// https://cses.fi/problemset/task/2182
#include "bits/stdc++.h"
using namespace std;
using int64 = long long;
const int64 MOD = 1000000007LL;

int64 modpow(int64 a, int64 e, int64 mod) {
    a %= mod;
    int64 r = 1;
    while (e > 0) {
        if (e & 1) r = (__int128)r * a % mod;
        a = (__int128)a * a % mod;
        e >>= 1;
    }
    return r;
}

int64 modinv(int64 a) {
    return modpow((a%MOD+MOD)%MOD, MOD - 2, MOD);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if (!(cin >> n)) return 0;
    vector<pair<int64,int64>> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i].first >> arr[i].second;

    // 1) number of divisors (mod MOD)
    int64 num_div = 1;
    for (auto &pr : arr) {
        int64 k = pr.second;
        num_div = (num_div * ((k + 1) % MOD)) % MOD;
    }

    // 2) sum of divisors (mod MOD)
    int64 sum_div = 1;
    for (auto &pr : arr) {
        int64 p = pr.first % MOD;
        int64 k = pr.second;
        int64 num = (modpow(p, k + 1, MOD) - 1 + MOD) % MOD;
        int64 den_inv = modinv((pr.first - 1) % MOD + MOD);
        sum_div = sum_div * (num * den_inv % MOD) % MOD;
    }

    // 3) product of divisors: compute exponents carefully
    // d = product (k_i + 1)
    // we need exponents modulo (MOD-1). To handle division by 2, compute d mod (2*(MOD-1)).
    const int64 M1 = MOD - 1;                 // for exponent reduction
    const int64 M2 = 2 * (MOD - 1);           // to allow safe divide-by-2
    int64 d_mod_M2 = 1;                       // d % (2*(MOD-1))
    int64 d_mod_M1 = 1;                       // d % (MOD-1)
    bool all_k_even = true;
    for (auto &pr : arr) {
        int64 k = pr.second;
        if (k % 2 != 0) all_k_even = false;
        d_mod_M2 = ( (__int128)d_mod_M2 * ((k + 1) % M2) ) % M2;
        d_mod_M1 = ( (__int128)d_mod_M1 * ((k + 1) % M1) ) % M1;
    }

    // compute product as Π p_i^{ exponent_i } (mod MOD)
    int64 prod_div = 1;
    if (d_mod_M2 % 2 == 0) {
        // d is even; compute half = d/2 (mod M1) using d_mod_M2 / 2
        int64 half = (d_mod_M2 / 2) % M1;
        for (auto &pr : arr) {
            int64 p = pr.first % MOD;
            int64 k = pr.second % M1;
            int64 expo = ( (__int128)k * half ) % M1; // exponent mod (MOD-1)
            prod_div = prod_div * modpow(p, expo, MOD) % MOD;
        }
    } else {
        // d is odd => n is a perfect square, all k are even
        // use exponent = (k/2) * d
        for (auto &pr : arr) {
            int64 p = pr.first % MOD;
            int64 k_half = (pr.second / 2) % M1;     // integer division safe because k is even
            int64 expo = ( (__int128)k_half * d_mod_M1 ) % M1;
            prod_div = prod_div * modpow(p, expo, MOD) % MOD;
        }
    }

    cout << (num_div % MOD + MOD) % MOD << " " << (sum_div % MOD + MOD) % MOD << " " << (prod_div % MOD + MOD) % MOD << "\n";
    return 0;
}
