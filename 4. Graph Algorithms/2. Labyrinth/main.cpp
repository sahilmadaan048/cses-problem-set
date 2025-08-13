// https://cses.fi/problemset/task/1193

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

vector<pair<int, int>> movements = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

char caldir(int dx, int dy)
{
    if (dx == 1 and dy == 0)
        return 'D';
    else if (dx == -1 and dy == 0)
        return 'U';
    else if (dx == 0 and dy == 1)
        return 'R';
    else if (dx == 0 and dy == -1)
        return 'L';
    // return '?';  // Default case to avoid issues
}

void solve()
{
    int n, m;
    cin >> n >> m;

    // Initialize the grid with n rows and m columns
    vector<vector<char>> temp(n, vector<char>(m));
    int row = -1, col = -1;

    // Read the grid and find the starting position 'A'
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> temp[i][j];
            if (temp[i][j] == 'A')
            {
                row = i;
                col = j;
            }
        }
    }

    // BFS
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1})); // To track the path
    queue<pair<int, int>> q;
    q.push({row, col});
    vis[row][col] = 1;

    bool flag = false;
    int end_row = -1, end_col = -1;

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop(); // Pop after accessing front

        for (auto movement : movements)
        {
            int nrow = r + movement.first;
            int ncol = c + movement.second;
            char dir = caldir(movement.first, movement.second);

            if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and !vis[nrow][ncol])
            {
                if (temp[nrow][ncol] == '.' || temp[nrow][ncol] == 'B')
                {
                    vis[nrow][ncol] = 1;
                    parent[nrow][ncol] = {r, c};
                    q.push({nrow, ncol});

                    if (temp[nrow][ncol] == 'B')
                    {
                        flag = true;
                        end_row = nrow;
                        end_col = ncol;
                        break;
                    }
                }
            }
        }
        if (flag)
            break; // Break outer loop if 'B' is found
    }

    if (!flag)
    {
        cout << "NO" << endl;
    }
    else
    {
        // Reconstruct the path
        string ans = "";
        pair<int, int> current = {end_row, end_col};
        while (current != make_pair(row, col))
        {
            pair<int, int> prev = parent[current.first][current.second];
            int dx = current.first - prev.first;
            int dy = current.second - prev.second;
            ans += caldir(dx, dy);
            current = prev;
        }
        reverse(ans.begin(), ans.end()); // Reverse the path since we built it backwards

        cout << "YES" << endl;
        cout << ans.size() << endl;
        cout << ans << endl;
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
