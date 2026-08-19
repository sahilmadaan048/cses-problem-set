// https://cses.fi/problemset/task/1654

// Author - sahilmadaan048

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
#define srt(v) sort(v.begin(), v.end())
#define mxe(v) *max_element(v.begin(), v.end())
#define mne(v) *min_element(v.begin(), v.end())
#define unq(v) v.resize(distance(v.begin(), unique(v.begin(), v.end())));
#define bin(x, y) bitset<y>(x)

using namespace std;

int MOD = 1e9 + 7;

void modadd(int &a, int b) { a = ((a % MOD) + (b % MOD)) % MOD; }
void modsub(int &a, int b) { a = ((a % MOD) - (b % MOD) + MOD) % MOD; }
void modmul(int &a, int b) { a = ((a % MOD) * (b % MOD)) % MOD; }

// ================================== Input / Output ==================================

template <typename typC, typename typD>
istream &operator>>(istream &cin, pair<typC, typD> &a)
{
    return cin >> a.first >> a.second;
}

template <typename typC>
istream &operator>>(istream &cin, vector<typC> &a)
{
    for (auto &x : a)
        cin >> x;

    return cin;
}

template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const pair<typC, typD> &a)
{
    return cout << a.first << ' ' << a.second;
}

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
    if (a.empty())
        return cout;

    cout << a[0];

    for (int i = 1; i < sz(a); i++)
        cout << ' ' << a[i];

    return cout;
}

// ================================== End ==================================

const int B = 21;
const int N = 1 << B;

int submask[N];
int supermask[N];

void solve()
{
    int n;
    cin >> n;

    vi a(n);
    cin >> a;

    for (auto x : a)
    {
        submask[x]++;
        supermask[x]++;
    }

    for (int bit = 0; bit < B; bit++)
    {
        for (int mask = 0; mask < N; mask++)
        {
            if (mask & (1LL << bit))
            {
                submask[mask] += submask[mask ^ (1LL << bit)];
            }
            else
            {
                supermask[mask] += supermask[mask ^ (1LL << bit)];
            }
        }
    }

    int full = N - 1;

    for (auto x : a)
    {
        int a1 = submask[x];
        int a2 = supermask[x];
        int a3 = n - submask[full ^ x];

        cout << a1 << " " << a2 << " " << a3 << "\n";
    }
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