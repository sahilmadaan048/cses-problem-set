// https://cses.fi/problemset/task/1079

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;

long long modpow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    const int MAXN = 1e6;
    vector<long long> fact(MAXN + 1), ifact(MAXN + 1);
    fact[0] = 1;
    for (int i = 1; i <= MAXN; i++) fact[i] = fact[i - 1] * i % MOD;

    ifact[MAXN] = modpow(fact[MAXN], MOD - 2);
    for (int i = MAXN; i >= 1; i--) ifact[i - 1] = ifact[i] * i % MOD;

    while (n--) {
        int a, b;
        cin >> a >> b;
        if (b < 0 || b > a) {
            cout << 0 << '\n';
            continue;
        }
        long long res = fact[a] * ifact[b] % MOD * ifact[a - b] % MOD;
        cout << res << '\n';
    }
    return 0;
}
