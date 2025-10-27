// https://cses.fi/problemset/task/1716

#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
#define fr(i, n) for (int i = 0; i < (n); i++)
#define rep(i, a, n) for (int i = (a); i <= (n); i++)
#define nl cout << "\n"
#define dbg(var) cout << #var << "=" << var << " "
#define all(v) v.begin(), v.end()
#define sz(v) (int)(v.size())
#define srt(v) sort(v.begin(), v.end())         // sort
#define mxe(v) *max_element(v.begin(), v.end()) // find max element in vector
#define mne(v) *min_element(v.begin(), v.end()) // find min element in vector
#define unq(v) v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed
#define bin(x, y) bitset<y>(x)
using namespace std;
using int64 = long long;
const int64 MOD = 1000000007LL;

void modadd(int &a, int b) { a = ((a % MOD) + (b % MOD)) % MOD; }
void modsub(int &a, int b) { a = ((a % MOD) - (b % MOD) + MOD) % MOD; }
void modmul(int &a, int b) { a = ((a % MOD) * (b % MOD)) % MOD; }
// ================================== take ip/op like vector,pairs directly!==================================
template <typename typC, typename typD>
istream &operator>>(istream &cin, pair<typC, typD> &a) { return cin >> a.first >> a.second; }
template <typename typC>
istream &operator>>(istream &cin, vector<typC> &a)
{
    for (auto &x : a)
        cin >> x;
    return cin;
}
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const pair<typC, typD> &a) { return cout << a.first << ' ' << a.second; }
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const vector<pair<typC, typD>> &a)
{
    for (auto &x : a)
        cout << x << '\n';
    return cout;
}
template <typename typC>
ostream &operator<<(ostream &cout, const vector<typC> &a)
{
    int n = a.size();
    if (!n)
        return cout;
    cout << a[0];
    for (int i = 1; i < n; i++)
        cout << ' ' << a[i];
    return cout;
}
// ===================================END Of the input module ==========================================

int64 modpow(int64 a, int64 b)
{
    int64 res = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

struct Comb
{
    vector<int64> fact, invfact;
    Comb(int N = 0) { init(N); }

    void init(int N)
    {
        fact.assign(N + 1, 1);
        for (int i = 1; i <= N; ++i)
            fact[i] = (fact[i - 1] * i) % MOD;
        invfact.assign(N + 1, 1);
        if (N >= 0)
            invfact[N] = modpow(fact[N], MOD - 2);
        for (int i = N; i > 0; --i)
            invfact[i - 1] = (invfact[i] * i) % MOD;
    }

    int64 nCr(int n, int r)
    {
        if (r < 0 || r > n)
            return 0;
        return ((fact[n] * invfact[r]) % MOD * invfact[n - r]) % MOD;
    }
};

void solve()
{
    int n, m;
    if (!(cin >> n >> m))
        return;

    // edge case
    if (n <= 0)
    {
        cout << (m == 0 ? 1 : 0) << "\n";
        return;
    }

    if (m < 0)
    {
        cout << 0 << "\n";
        return;
    }

    int limit = n + m;
    Comb C((int)limit + 5);

    /*

        formular used is (n + m -1) C (m)

    */

    int64 ways = C.nCr((int)(n + m - 1), (int)(m));
    cout << ways << "\n";

    return;
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}
