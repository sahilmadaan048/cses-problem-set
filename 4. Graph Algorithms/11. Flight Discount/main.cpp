// https://cses.fi/problemset/task/1195

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e18;

struct Edge {
    int to;
    ll cost;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    // dist[i][0] = min cost to reach i without using coupon
    // dist[i][1] = min cost to reach i after using coupon
    vector<vector<ll>> dist(n + 1, vector<ll>(2, INF));
    dist[1][0] = 0;

    // priority_queue of {cost, node, usedCoupon}
    using State = pair<ll, pair<int, int>>; 
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({0, {1, 0}});

    while (!pq.empty()) {
        auto [d, info] = pq.top(); pq.pop();
        int u = info.first;
        int used = info.second;

        if (d != dist[u][used]) continue;

        for (auto e : adj[u]) {
            int v = e.to;
            ll w = e.cost;

            // move normally
            if (dist[v][used] > d + w) {
                dist[v][used] = d + w;
                pq.push({dist[v][used], {v, used}});
            }

            // use coupon if not used yet
            if (!used && dist[v][1] > d + w / 2) {
                dist[v][1] = d + w / 2;
                pq.push({dist[v][1], {v, 1}});
            }
        }
    }

    cout << dist[n][1] << "\n";
    return 0;
}
