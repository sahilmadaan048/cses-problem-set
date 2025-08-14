// https://cses.fi/problemset/task/1194

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

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    pair<int, int> start = {-1, -1};
    vector<pair<int, int>> monsters;

    // Input
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
                start = {i, j};
            if (grid[i][j] == 'M')
                monsters.push_back({i, j});
        }
    }

    vector<vector<int>> monster_time(n, vector<int>(m, INT_MAX));
    queue<pair<int, int>> q;
    for (auto &mon : monsters)
    {
        q.push(mon);
        monster_time[mon.first][mon.second] = 0;
    }

    while (!q.empty())
    {
        auto it = q.front();
        
        int r = it.first;
        int c = it.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#' && monster_time[nr][nc] == INT_MAX)
            {
                monster_time[nr][nc] = monster_time[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    // BFS for player
    vector<vector<int>> player_time(n, vector<int>(m, INT_MAX));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    q.push(start);
    player_time[start.first][start.second] = 0;

    pair<int, int> escape = {-1, -1};

    while (!q.empty())
    {
        auto it = q.front();
        int r = it.first;
        int c = it.second;
        q.pop();
        // Check if on boundary
        if (r == 0 || r == n - 1 || c == 0 || c == m - 1)
        {
            escape = {r, c};
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#' && player_time[nr][nc] == INT_MAX && player_time[r][c] + 1 < monster_time[nr][nc])
            {
                player_time[nr][nc] = player_time[r][c] + 1;
                parent[nr][nc] = {r, c};
                q.push({nr, nc});
            }
        }
    }

    if (escape.first == -1)
    {
        cout << "NO\n";
        return;
    }

    // Reconstruct path
    string path = "";
    pair<int, int> cur = escape;
    while (cur != start)
    {
        auto it = parent[cur.first][cur.second];
        
        auto pr = it.first;
        auto pc = it.second;

        if (cur.first == pr + 1)
            path += 'D';
        else if (cur.first == pr - 1)
            path += 'U';
        else if (cur.second == pc + 1)
            path += 'R';
        else if (cur.second == pc - 1)
            path += 'L';
        cur = {pr, pc};
    }
    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << "\n";
    cout << path << "\n";
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
