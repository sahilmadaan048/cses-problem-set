// https://cses.fi/problemset/task/1715

#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

// fact expomemtitation (a ^ b % MOD)
long long modpow(long long a, long long b) {
    long long res = 1;
    while(b > 0) {
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
} 

// Precompute factorials and inverse factorials
vector<long long> fact(1e6 + 5), invfact(1e6 + 5);

void precompute() {
    fact[0] = 1;
    for(int i=1; i<fact.size(); i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }

    invfact.back() = modpow(fact.back(), MOD - 2); // inverse of the last factorial
    for(int i=fact.size()-2; i>=0; i--) {
        invfact[i] = (invfact[i+1] * (i + 1)) % MOD;
    }
}

int main() {
    precompute();

    string s; cin >> s;
    unordered_map<char, int> freq;
    for(auto ch: s) freq[ch]++;

    long long n = s.size();
    long long res = fact[n];
    for(auto [ch, f]: freq) {
        res = (res * invfact[f]) % MOD;
    }

    cout << res << "\n";
}