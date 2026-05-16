// https://cses.fi/problemset/task/3226
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


struct Node {
   int ans, pref, suff, sum;

   Node(int v = 0) {
      sum = v;
      pref = suff = ans = max(0LL , v);
   }
};

struct SegTree {
   int n;
   vector<Node> tree;

   SegTree(int sz) {
      n = sz;
      tree.resize(4*n);
   }

   Node merge(Node L, Node R) {

        Node res;

        res.sum = L.sum + R.sum;

        res.pref = max(L.pref, L.sum + R.pref);

        res.suff = max(R.suff, R.sum + L.suff);

        res.ans = max({
            L.ans,
            R.ans,
            L.suff + R.pref
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
      build(2*node+1, mid+1, r, a);
 
      tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

   Node query(int node, int l, int r,
               int ql, int qr) {

        if (ql == l && qr == r)
            return tree[node];

        int mid = (l + r) / 2;

        if (qr <= mid)
            return query(2 * node, l, mid, ql, qr);

        if (ql > mid)
            return query(2 * node + 1, mid + 1, r, ql, qr);

        Node left =
            query(2 * node, l, mid, ql, mid);

        Node right =
            query(2 * node + 1, mid + 1, r,
                  mid + 1, qr);

        return merge(left, right);
    }
 };

void solve(){
   int n, q;
   cin >> n >> q;

   vector<int> x(n);

   for(int i=0; i<n; i++) {
      cin >> x[i];
   }

   SegTree seg(n);

   seg.build(1, 0, n-1, x);

   while(q--) {
      int l, r; cin >> l >> r;

      l--;
      r--;

      cout << seg.query(1, 0, n-1, l, r).ans << endl;
   }

   return;
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
   
   this is the static version of the previous problem 

   now: 
      no upfayes
   only queries on ranges [a,b]

   so we use the SAME segment tree node: 
      sum
      pref
      suff
      ans

   but noww we also need a range query returnng a whole node


   MERGE LOGIC:
      if left child = l, right child = r


         sum = l.sum + r.sum
         pref = max(l.pref, l.sum + r.pref)
         suff = max(r.suff, r.sum + l.suff)

         ans = max({
            l.ans,
            r.ans,
            l.siff + r.pref
         });



         LEAF NODE:
            empty subarray is allowd

            pref = suff = ans = max(0LL, val)

*/