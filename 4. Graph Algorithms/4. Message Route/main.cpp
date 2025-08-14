// https://cses.fi/problemset/task/1667

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

void solve()
{
    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<int>> mpp;

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;

        mpp[a].push_back(b);
        mpp[b].push_back(a);
    }

    vector<int> vis(n + 1, 0);
    vector<int> par(n + 1, -1);

    queue<int> q;
    q.push(1);
    vis[1] = 1;
    par[1] = -1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto ele : mpp[node]) {
            if(!vis[ele]) {
                vis[ele] = 1;
                par[ele] = node;
                q.push(ele);


                if(ele == n ) break;
            }
        }
            
    }

    if (!vis[n])
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<int> path;
    for (int i = n; i != -1; i = par[i])
    {
        path.push_back(i);
    }

    reverse(path.begin(), path.end());
    cout << path.size() << endl;

    for (int v : path)
    {
        cout << v << " ";
    }
    cout << endl;

    return;
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
