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
    int n = a.size();

    if (!n)
        return cout;

    cout << a[0];

    for (int i = 1; i < n; i++)
        cout << ' ' << a[i];

    return cout;
}

const int B = 21;
const int N = 1 << B;

vector<vi> dp1(N, vi(B));
vector<vi> dp2(N, vi(B));

int invert_mask(int x)
{
    fr(i, B - 1)
    {
        x ^= (1LL << i);
    }

    return x;
}

void solve()
{
    int n;
    cin >> n;

    vi a(n);
    cin >> a;

    for (auto x : a)
    {
        dp1[x][0]++;
        dp2[x][0]++;
    }

    for (int mask = 0; mask < (1LL << (B - 1)); mask++)
    {
        rep(bit, 1, B - 1)
        {
            dp1[mask][bit] += dp1[mask][bit - 1];

            if (mask & (1LL << (bit - 1)))
            {
                dp1[mask][bit] += dp1[mask ^ (1LL << (bit - 1))][bit - 1];
            }
        }
    }

    for (int mask = (1LL << (B - 1)) - 1; mask >= 0; mask--)
    {
        rep(bit, 1, B - 1)
        {
            dp2[mask][bit] += dp2[mask][bit - 1];

            if (!(mask & (1LL << (bit - 1))))
            {
                dp2[mask][bit] += dp2[mask ^ (1LL << (bit - 1))][bit - 1];
            }
        }
    }

    for (auto x : a)
    {
        cout << dp1[x][B - 1] << " ";
        cout << dp2[x][B - 1] << " ";
        cout << n - dp1[invert_mask(x)][B - 1] << "\n";
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