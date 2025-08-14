// https://cses.fi/problemset/task/1671

#include "bits/stdc++.h"
#define int long long
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
using namespace std;

const long long INF = 1e18;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    
    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, INF));
    
    // distance to self is zero
    for (int i = 1; i <= n; i++) dist[i][i] = 0;
    
    // input roads
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], (long long)c);
        dist[b][a] = min(dist[b][a], (long long)c); // two-way road
    }
    
    // Floyd-Warshall all-pairs shortest paths
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    // answer queries
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == INF) cout << "-1\n";
        else cout << dist[a][b] << "\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    while (T--) solve();
    return 0;
}
