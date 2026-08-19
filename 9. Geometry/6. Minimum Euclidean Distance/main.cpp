// https://cses.fi/problemset/task/2194

// Author - sahilmadaan048

// https://cses.fi/problemset/task/2194

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

struct Point
{
    int x, y;
};

struct cmpX
{
    bool operator()(const Point &a, const Point &b) const
    {
        if (a.x == b.x)
            return a.y < b.y;

        return a.x < b.x;
    }
};

struct cmpY
{
    bool operator()(const Point &a, const Point &b) const
    {
        return a.y < b.y;
    }
};

vector<Point> pts, temp;

int ans;

void update(Point &a, Point &b)
{
    int dx = a.x - b.x;
    int dy = a.y - b.y;

    ans = min(ans, dx * dx + dy * dy);
}

void rec(int l, int r)
{
    if (r - l <= 3)
    {
        for (int i = l; i < r; i++)
        {
            for (int j = i + 1; j < r; j++)
            {
                update(pts[i], pts[j]);
            }
        }

        sort(pts.begin() + l, pts.begin() + r, cmpY());

        return;
    }

    int m = (l + r) / 2;
    int midx = pts[m].x;

    rec(l, m);
    rec(m, r);

    merge(pts.begin() + l,
          pts.begin() + m,
          pts.begin() + m,
          pts.begin() + r,
          temp.begin(),
          cmpY());

    copy(temp.begin(), temp.begin() + (r - l), pts.begin() + l);

    int szStrip = 0;

    for (int i = l; i < r; i++)
    {
        int dx = pts[i].x - midx;

        if (dx * dx < ans)
        {
            for (int j = szStrip - 1; j >= 0; j--)
            {
                int dy = pts[i].y - temp[j].y;

                if (dy * dy >= ans)
                    break;

                update(pts[i], temp[j]);
            }

            temp[szStrip++] = pts[i];
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    pts.resize(n);
    temp.resize(n);

    fr(i, n)
    {
        cin >> pts[i].x >> pts[i].y;
    }

    sort(all(pts), cmpX());

    ans = LLONG_MAX;

    rec(0, n);

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