Good — thanks for the full problem statement. That clarifies why the simple DFS approach I gave earlier can fail. I’ll explain *why it gives wrong answers* and then give a *correct, efficient C++ solution* (Bellman–Ford style) that handles negative and positive weights and detects the “arbitrarily large score” case (print `-1`).

---

## Why the DFS/backtracking solution is wrong here

1. **Revisiting nodes matters.** Your rules allow passing through tunnels multiple times. A naïve DFS that uses `visited[]` to prevent revisits will *miss* valid paths that require revisiting nodes (including beneficial cycles).
2. **Positive cycles can make the score infinite.** If there exists a cycle whose total weight is positive, and that cycle is both reachable from `1` and can reach `n`, you can loop the cycle arbitrarily many times → arbitrarily large score. A DFS that forbids revisits never detects this correctly.
3. **Exponential search & recursion depth.** Exploring *all* paths by naive recursion is exponential and will TLE for `n,m` up to thousands.
4. **You need a graph algorithm for longest path with cycle detection.** The standard approach for this problem is to adapt **Bellman–Ford** to maximize distances instead of minimizing, and then check for positive cycles that affect the path to `n`.

---

## Correct approach (Bellman–Ford variant)

* Maintain `dist[i] = best known maximum score to reach i`. Initialize `dist[1] = 0`, others `-INF`.
* Relax all edges `n-1` times: if `dist[u] != -INF` and `dist[v] < dist[u] + w` then update `dist[v]`.
* After `n-1` relaxations, do one more pass. If any edge can still be relaxed (i.e. `dist[u] != -INF && dist[v] < dist[u] + w`) then node `v` (and nodes reachable from it) are affected by a positive cycle reachable from `1`.
* From all such nodes, run BFS/DFS over the graph to mark all nodes that can be reached from them. If node `n` is marked, the answer is `-1` (arbitrarily large).
* Otherwise, answer is `dist[n]`.

This is `O(n*m)` and fits the constraints.

---

## Robust C++ implementation

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll NEG_INF = LLONG_MIN / 4;

struct Edge { int u, v; ll w; };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<Edge> edges;
    vector<vector<int>> adj(n + 1); // adjacency for BFS from "bad" nodes

    for (int i = 0; i < m; ++i) {
        int a, b; ll x;
        cin >> a >> b >> x;
        edges.push_back({a, b, x});
        adj[a].push_back(b);
    }

    vector<ll> dist(n + 1, NEG_INF);
    dist[1] = 0;

    // Relax edges n-1 times (maximize)
    for (int iter = 0; iter < n - 1; ++iter) {
        bool changed = false;
        for (auto &e : edges) {
            if (dist[e.u] != NEG_INF && dist[e.v] < dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
                changed = true;
            }
        }
        if (!changed) break;
    }

    // Find nodes affected by positive cycles reachable from 1
    vector<char> affected(n + 1, false);
    for (auto &e : edges) {
        if (dist[e.u] != NEG_INF && dist[e.v] < dist[e.u] + e.w) {
            affected[e.v] = true;
        }
    }

    // Propagate affected status (BFS/DFS) along edges
    queue<int> q;
    for (int i = 1; i <= n; ++i) if (affected[i]) q.push(i);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!affected[v]) {
                affected[v] = true;
                q.push(v);
            }
        }
    }

    // If n is affected => can obtain arbitrarily large score
    if (affected[n]) {
        cout << -1 << "\n";
    } else {
        cout << dist[n] << "\n";
    }

    return 0;
}
```

### Important implementation notes

* Use `long long` (`ll`) because edge weights can be up to `1e9` and paths can sum large.
* `NEG_INF` is `LLONG_MIN/4` to avoid overflow when adding.
* We only mark nodes as "affected" if we can still relax an edge after `n-1` relaxations — that indicates a positive cycle reachable from `1`. We then propagate that effect forward along edges; if `n` is reachable from any such affected node, answer is `-1`.
* The code assumes the input guarantee: "You can assume that it is possible to get from room 1 to room n." (so `dist[n]` won't remain `NEG_INF` unless cycles or implementation errors).

---

## For the sample

Input:

```
4 5
1 2 3
2 4 -1
1 3 -2
3 4 7
1 4 4
```

The program prints `5`, matching the example.

---

If you want, I can:

* Add comments/print debugging to trace specific relaxations.
* Modify the code to also print the actual path (if finite).
* Provide a small test harness to try multiple inputs.

Which (if any) would you like next?
 