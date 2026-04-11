// https://cses.fi/problemset/task/1160

// Author - sahilmadaan048


#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int LOG = 20;

int n, q;
int nxt[MAXN];
int up[MAXN][LOG];
int depth[MAXN];
int comp[MAXN];
int cycle_id[MAXN];
int cycle_pos[MAXN];
int cycle_size[MAXN];
bool vis[MAXN];
bool in_stack[MAXN];

void dfs(int u) {
   vis[u] = true;
   in_stack[u] = true;
   int v = nxt[u];

   if(!vis[v]) {
      dfs(v);
   } else if(in_stack[v]) {
      // found cycle

      int cur = v;
      int cid = v;
      int pos = 0;
      do {
         cycle_id[cur] = cid;
         cycle_pos[cur] = pos++;
         cur = nxt[cur];
      } while(cur != v);
      cycle_size[cid] = pos;
   }

   in_stack[u] = false;

   if(!cycle_id[u]) {
      cycle_id[u] = cycle_id[nxt[u]];
      depth[u] = depth[nxt[u]] + 1;
   }
}

int jump(int u, int k) {
   for(int i=0; i<LOG; i++) {
      if((k & (1 << i))) {
         u = up[u][i];
      }
   }
   return u;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   cin >> n >> q;

   for(int i=1; i<=n; i++) {
      cin >> nxt[i];
   }

   for(int i=1; i<=n; i++) {
      up[i][0] = nxt[i];
   }

   for(int j=1; j<LOG; j++) {
      for(int i=1; i<=n; i++) {
         up[i][j] = up[up[i][j-1]][j-1];
      }
   }

   for(int i=1; i<=n; i++) {
      if(!vis[i]) {
         dfs(i);
      }
   }

   while(q--) {
      int a, b; cin >> a >> b;

      if(cycle_id[a] != cycle_id[b]) {
         cout << -1 << "\n";
         continue;
      }

      if(depth[a] >= depth[b]) {
         int diff = depth[a] - depth[b];
         if(jump(a, diff) == b) {
            cout << diff << "\n";
            continue;
         }
      }

      if (depth[b] == 0) {
         int dist = depth[a];
         int entry = jump(a, depth[a]);
         int cid = cycle_id[a];
         int cyc_dist = (cycle_pos[b] - cycle_pos[entry] + cycle_size[cid]) % cycle_size[cid];
         cout << dist + cyc_dist << "\n";
      } else {
         cout << -1 << "\n";
      }
   }
}