// https://cses.fi/problemset/task/2195

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

int orientation(Point a, Point b, Point c)
{
    int val = a.x * (b.y - c.y)
            + b.x * (c.y - a.y)
            + c.x * (a.y - b.y);

    if (val < 0)
        return -1;

    if (val > 0)
        return 1;

    return 0;
}

bool cw(Point a, Point b, Point c, bool include_collinear)
{
    int o = orientation(a, b, c);

    return o < 0 || (include_collinear && o == 0);
}

bool ccw(Point a, Point b, Point c, bool include_collinear)
{
    int o = orientation(a, b, c);

    return o > 0 || (include_collinear && o == 0);
}

void convex_hull(vector<Point> &pts, bool include_collinear = false)
{
    if (sz(pts) <= 1)
        return;

    sort(all(pts), [](Point a, Point b)
         {
             return make_pair(a.x, a.y) < make_pair(b.x, b.y);
         });

    Point p1 = pts[0];
    Point p2 = pts.back();

    vector<Point> upper, lower;

    upper.push_back(p1);
    lower.push_back(p1);

    for (int i = 1; i < sz(pts); i++)
    {
        if (i == sz(pts) - 1 || cw(p1, pts[i], p2, include_collinear))
        {
            while (sz(upper) >= 2 &&
                   !cw(upper[sz(upper) - 2],
                       upper[sz(upper) - 1],
                       pts[i],
                       include_collinear))
            {
                upper.pop_back();
            }

            upper.push_back(pts[i]);
        }

        if (i == sz(pts) - 1 || ccw(p1, pts[i], p2, include_collinear))
        {
            while (sz(lower) >= 2 &&
                   !ccw(lower[sz(lower) - 2],
                        lower[sz(lower) - 1],
                        pts[i],
                        include_collinear))
            {
                lower.pop_back();
            }

            lower.push_back(pts[i]);
        }
    }

    if (include_collinear && sz(upper) == sz(pts))
    {
        reverse(all(pts));
        return;
    }

    pts.clear();

    for (auto p : upper)
        pts.push_back(p);

    for (int i = sz(lower) - 2; i > 0; i--)
        pts.push_back(lower[i]);
}

void solve()
{
    int n;
    cin >> n;

    vector<Point> pts(n);

    fr(i, n)
    {
        cin >> pts[i].x >> pts[i].y;
    }

    convex_hull(pts, true);

    cout << sz(pts) << "\n";

    for (auto [x, y] : pts)
    {
        cout << x << " " << y << "\n";
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