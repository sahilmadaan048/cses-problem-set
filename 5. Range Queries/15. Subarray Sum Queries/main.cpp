
// https://cses.fi/problemset/task/1190/
// Author - sahilmadaan048

#include "bits/stdc++.h"
#define int long long
using namespace std;


struct Node {
   int sum, pref, suff, ans;

   Node(int v = 0) {
      sum = v;
      pref = suff = ans = max(0LL, v);
   }
};

struct SegTree {
   int n;
   vector<Node> tree;

   SegTree(int sz){
      n = sz;

      tree.resize(4*n);
   }


   Node merge(Node l, Node r) {
      Node res;

      res.sum =  l.sum + r.sum;

      res.pref = max(l.pref, l.sum + r.pref);
      res.suff = max(r.suff, r.sum + l.suff);


      res.ans = max({
         l.ans, 
         r.ans,
         l.suff + r.pref
      });

      return res;
   }

   void build(int node, int l, int r, vector<int> &a) {
      if(l == r) {
         tree[node] = Node(a[l]);
         return;
      }

      int mid = (l + r) / 2;

      build(2*node, l, mid, a);
      build(2*node + 1, mid+1, r, a);
   
      tree[node] = merge(tree[2*node], tree[2*node+1]);
   }

       void update(int node, int l, int r,
                int idx, int val) {

        if (l == r) {
            tree[node] = Node(val);
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(2 * node, l, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, r, idx, val);

        tree[node] = merge(tree[2 * node],
                           tree[2 * node + 1]);
    }
};

void solve(){

     int n, m;
    cin >> n >> m;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    SegTree seg(n);

    seg.build(1, 0, n - 1, a);

    while (m--) {

        int k, x;
        cin >> k >> x;

        k--;

        seg.update(1, 0, n - 1, k, x);

        cout << seg.tree[1].ans << '\n';
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
