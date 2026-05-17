// https://cses.fi/problemset/task/1735
// Author - sahilmadaan048

#include "bits/stdc++.h"
#define int long long
#define uint unsigned long long
#define vi vector<int>
#define vvi vector<vi >
#define vb vector<bool>
#define vvb vector<vb >
#define fr(i,n) for(int i=0; i<(n); i++)
#define rep(i,a,n) for(int i=(a); i<=(n); i++)
#define nl cout<<"\n"
#define dbg(var) cout<<#var<<"="<<var<<" "
#define all(v) v.begin(),v.end()
#define sz(v) (int)(v.size())
#define srt(v)  sort(v.begin(),v.end())         // sort 
#define mxe(v)  *max_element(v.begin(),v.end())     // find max element in vector
#define mne(v)  *min_element(v.begin(),v.end())     // find min element in vector
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())));
// make sure to sort before applying unique // else only consecutive duplicates would be removed 
#define bin(x,y)  bitset<y>(x) 
using namespace std;
int MOD=1e9+7;      // Hardcoded, directly change from here for functions!


void modadd(int &a , int b) {a=((a%MOD)+(b%MOD))%MOD;}
void modsub(int &a , int b) {a=((a%MOD)-(b%MOD)+MOD)%MOD;}
void modmul(int &a , int b) {a=((a%MOD)*(b%MOD))%MOD;}
// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================


struct SegTree {

    int n;

    vector<int> tree;

    vector<int> lazyAdd;
    vector<int> lazySet;

    vector<bool> hasSet;

    SegTree(int sz) {

        n = sz;

        tree.resize(4 * n);

        lazyAdd.assign(4 * n, 0);
        lazySet.assign(4 * n, 0);

        hasSet.assign(4 * n, false);
    }

    void build(int node, int l, int r,
               vector<int>& a) {

        if (l == r) {

            tree[node] = a[l];

            return;
        }

        int mid = (l + r) / 2;

        build(2 * node, l, mid, a);
        build(2 * node + 1, mid + 1, r, a);

        tree[node] =
            tree[2 * node]
          + tree[2 * node + 1];
    }

    void applySet(int node, int l, int r,
                  int val) {

        tree[node] =
            (r - l + 1) * val;

        lazySet[node] = val;

        hasSet[node] = true;

        lazyAdd[node] = 0;
    }

    void applyAdd(int node, int l, int r,
                  int val) {

        tree[node] +=
            (r - l + 1) * val;

        if (hasSet[node])
            lazySet[node] += val;
        else
            lazyAdd[node] += val;
    }

    void push(int node, int l, int r) {

        if (l == r)
            return;

        int mid = (l + r) / 2;

        // push set first
        if (hasSet[node]) {

            applySet(2 * node,
                     l, mid,
                     lazySet[node]);

            applySet(2 * node + 1,
                     mid + 1, r,
                     lazySet[node]);

            hasSet[node] = false;
        }

        // then push add
        if (lazyAdd[node]) {

            applyAdd(2 * node,
                     l, mid,
                     lazyAdd[node]);

            applyAdd(2 * node + 1,
                     mid + 1, r,
                     lazyAdd[node]);

            lazyAdd[node] = 0;
        }
    }

    void rangeAdd(int node, int l, int r,
                  int ql, int qr, int val) {

        if (qr < l || r < ql)
            return;

        if (ql <= l && r <= qr) {

            applyAdd(node, l, r, val);

            return;
        }

        push(node, l, r);

        int mid = (l + r) / 2;

        rangeAdd(2 * node, l, mid,
                 ql, qr, val);

        rangeAdd(2 * node + 1,
                 mid + 1, r,
                 ql, qr, val);

        tree[node] =
            tree[2 * node]
          + tree[2 * node + 1];
    }

    void rangeSet(int node, int l, int r,
                  int ql, int qr, int val) {

        if (qr < l || r < ql)
            return;

        if (ql <= l && r <= qr) {

            applySet(node, l, r, val);

            return;
        }

        push(node, l, r);

        int mid = (l + r) / 2;

        rangeSet(2 * node, l, mid,
                 ql, qr, val);

        rangeSet(2 * node + 1,
                 mid + 1, r,
                 ql, qr, val);

        tree[node] =
            tree[2 * node]
          + tree[2 * node + 1];
    }

    int query(int node, int l, int r,
              int ql, int qr) {

        if (qr < l || r < ql)
            return 0;

        if (ql <= l && r <= qr)
            return tree[node];

        push(node, l, r);

        int mid = (l + r) / 2;

        return
            query(2 * node, l, mid,
                  ql, qr)
          + query(2 * node + 1,
                  mid + 1, r,
                  ql, qr);
    }
};



void solve() {

    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    SegTree seg(n);

    seg.build(1, 1, n, a);

    while (q--) {

        int type;
        cin >> type;

        if (type == 1) {

            int l, r, x;
            cin >> l >> r >> x;

            seg.rangeAdd(1, 1, n,
                         l, r, x);
        }

        else if (type == 2) {

            int l, r, x;
            cin >> l >> r >> x;

            seg.rangeSet(1, 1, n,
                         l, r, x);
        }

        else {

            int l, r;
            cin >> l >> r;

            cout << seg.query(1, 1, n,
                              l, r)
                 << '\n';
        }
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


/*
   
   this is a classic lazy segment tree problem

   we need 3 operations: 
      range add
      range assign
      range sum query

   the tricky part is : 
      SET OVERRIDE ADD

   so lazy propagation must carefully handle both

   what each node stores

   for every nioide: 
   tree[node] = segment sum

   ;azy values
      lazyAdd[node]
      lazySet[node]
      hasSet[node]


*/