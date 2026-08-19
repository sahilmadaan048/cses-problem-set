// https://cses.fi/problemset/task/1741

// Author - sahilmadaan048

// https://cses.fi/problemset/task/1741

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

const int N = 2000007;
const int OFFSET = 1000001;

vector<pair<int, int>> startPts[N];
vector<pair<int, int>> endPts[N];

int lazy[4 * N];
pair<int, int> segtree[4 * N];

pair<int, int> combine(pair<int, int> a, pair<int, int> b)
{
    if (a.first < b.first)
        return a;

    if (b.first < a.first)
        return b;

    return {a.first, a.second + b.second};
}

void build(int node, int l, int r)
{
    if (l > r)
        return;

    if (l == r)
    {
        segtree[node] = {0, 1};
        return;
    }

    int mid = (l + r) / 2;

    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);

    segtree[node] =
        combine(segtree[node * 2], segtree[node * 2 + 1]);
}

void push(int node, int l, int r)
{
    if (!lazy[node])
        return;

    segtree[node].first += lazy[node];

    if (l != r)
    {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }

    lazy[node] = 0;
}

void update(int node, int l, int r, int ql, int qr, int val)
{
    push(node, l, r);

    if (l > r || l > qr || r < ql)
        return;

    if (ql <= l && r <= qr)
    {
        lazy[node] += val;
        push(node, l, r);
        return;
    }

    int mid = (l + r) / 2;

    update(node * 2, l, mid, ql, qr, val);
    update(node * 2 + 1, mid + 1, r, ql, qr, val);

    segtree[node] =
        combine(segtree[node * 2], segtree[node * 2 + 1]);
}

pair<int, int> query(int node, int l, int r, int ql, int qr)
{
    push(node, l, r);

    if (l > r || l > qr || r < ql)
        return {10, 0};

    if (ql <= l && r <= qr)
        return segtree[node];

    int mid = (l + r) / 2;

    return combine(
        query(node * 2, l, mid, ql, qr),
        query(node * 2 + 1, mid + 1, r, ql, qr));
}

void solve()
{
    int n;
    cin >> n;

    fr(i, n)
    {
        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        x1 += OFFSET;
        x2 += OFFSET;
        y1 += OFFSET;
        y2 += OFFSET;

        startPts[y1].push_back({x1, x2});
        endPts[y2].push_back({x1, x2});
    }

    build(1, 1, N - 1);

    int emptyCells = 0;

    rep(y, 1, N - 1)
    {
        for (auto [l, r] : endPts[y])
        {
            update(1, 1, N - 1, l + 1, r, -1);
        }

        for (auto [l, r] : startPts[y])
        {
            update(1, 1, N - 1, l + 1, r, 1);
        }

        auto cur = query(1, 1, N - 1, 1, N - 1);

        if (cur.first == 0)
        {
            emptyCells += cur.second;
        }
    }

    cout << 2000006LL * 2000006LL - emptyCells;
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