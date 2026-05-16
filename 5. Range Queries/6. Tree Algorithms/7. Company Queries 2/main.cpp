// https://cses.fi/problemset/task/1688

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
int MOD = 1e9 + 7; // Hardcoded, directly change from here for functions!

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

const int MAXN = 2e5 + 5;
const int LOG = 20; // 2^20 > 2e5
int up[MAXN][LOG];  // up[v][j] = 2^j-th ancestor of v
int depth[MAXN];

void dfs(int v, int p, vector<vector<int>> &adj)
{
    up[v][0] = p;
    for (int j = 1; j < LOG; j++)
    {
        if (up[v][j - 1] != -1)
            up[v][j] = up[up[v][j - 1]][j - 1];
        else
            up[v][j] = -1;
    }
    for (int u : adj[v])
    {
        if (u != p)
        {
            depth[u] = depth[v] + 1;
            dfs(u, v, adj);
        }
    }
}

int lca(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);

    // Lift a to the depth of b
    for (int j = LOG - 1; j >= 0; j--)
    {
        if (up[a][j] != -1 && depth[up[a][j]] >= depth[b])
            a = up[a][j];
    }

    if (a == b)
        return a;

    // Lift both a and b together
    for (int j = LOG - 1; j >= 0; j--)
    {
        if (up[a][j] != -1 && up[a][j] != up[b][j])
        {
            a = up[a][j];
            b = up[b][j];
        }
    }

    return up[a][0]; // parent of both is LCA
}

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int boss;
        cin >> boss;
        adj[boss].push_back(i);
    }

    depth[1] = 0;
    dfs(1, -1, adj);

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << "\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
