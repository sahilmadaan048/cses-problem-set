// https://cses.fi/problemset/task/1740/

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
    int n = a.size();

    if (!n)
        return cout;

    cout << a[0];

    for (int i = 1; i < n; i++)
        cout << ' ' << a[i];

    return cout;
}

// =================================== END ==========================================

const int N = 200005;

struct Range
{
    int x1, y1, x2, y2;
};

Range ranges[N];

vector<int> startPts[N];
vector<int> endPts[N];
vector<pair<int, int>> horizontal[N];

int segtree[4 * N];

void update(int node, int l, int r, int pos, int val)
{
    if (l > pos || r < pos || l > r)
        return;

    if (l == r)
    {
        segtree[node] += val;
        return;
    }

    int mid = (l + r) / 2;

    update(node * 2, l, mid, pos, val);
    update(node * 2 + 1, mid + 1, r, pos, val);

    segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

int query(int node, int l, int r, int ql, int qr)
{
    if (l > qr || r < ql || l > r)
        return 0;

    if (l >= ql && r <= qr)
        return segtree[node];

    int mid = (l + r) / 2;

    return query(node * 2, l, mid, ql, qr) +
           query(node * 2 + 1, mid + 1, r, ql, qr);
}

void solve()
{
    int n;
    cin >> n;

    fr(i, n)
    {
        cin >> ranges[i].x1
            >> ranges[i].y1
            >> ranges[i].x2
            >> ranges[i].y2;
    }

    vi compress;

    fr(i, n)
    {
        compress.push_back(ranges[i].x1);
        compress.push_back(ranges[i].x2);
    }

    srt(compress);
    compress.erase(unique(all(compress)), compress.end());

    fr(i, n)
    {
        ranges[i].x1 =
            lower_bound(all(compress), ranges[i].x1) -
            compress.begin() + 1;

        ranges[i].x2 =
            lower_bound(all(compress), ranges[i].x2) -
            compress.begin() + 1;
    }

    compress.clear();

    fr(i, n)
    {
        compress.push_back(ranges[i].y1);
        compress.push_back(ranges[i].y2);
    }

    srt(compress);
    compress.erase(unique(all(compress)), compress.end());

    fr(i, n)
    {
        ranges[i].y1 =
            lower_bound(all(compress), ranges[i].y1) -
            compress.begin() + 1;

        ranges[i].y2 =
            lower_bound(all(compress), ranges[i].y2) -
            compress.begin() + 1;
    }

    fr(i, n)
    {
        int x1 = ranges[i].x1;
        int x2 = ranges[i].x2;
        int y1 = ranges[i].y1;
        int y2 = ranges[i].y2;

        if (x1 == x2)
        {
            startPts[y1].push_back(x1);
            endPts[y2].push_back(x1);
        }
        else
        {
            horizontal[y1].push_back({x1, x2});
        }
    }

    int ans = 0;

    rep(y, 1, N - 1)
    {
        for (auto x : startPts[y])
        {
            update(1, 1, N - 1, x, 1);
        }

        for (auto [l, r] : horizontal[y])
        {
            ans += query(1, 1, N - 1, l, r);
        }

        for (auto x : endPts[y])
        {
            update(1, 1, N - 1, x, -1);
        }
    }

    cout << ans;
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