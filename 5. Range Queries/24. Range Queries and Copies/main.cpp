// https://cses.fi/problemset/task/1737
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
   int sum;

   Node* left, *right;

   Node(int s=0, Node*l = nullptr, Node*r = nullptr) {
      sum = s;
      left = l;
      right = r;
   }
}; 

Node* build(int l, int r,
            vector<int>& a) {

    if (l == r)
        return new Node(a[l]);

    int mid = (l + r) / 2;

    Node* left =
        build(l, mid, a);

    Node* right =
        build(mid + 1, r, a);

    return new Node(
        left->sum + right->sum,
        left,
        right
    );
}
   
Node* update(Node* node,
             int l, int r,
             int idx, int val) {

    if (l == r)
        return new Node(val);

    int mid = (l + r) / 2;

    if (idx <= mid) {

        Node* newLeft =
            update(node->left,
                   l, mid,
                   idx, val);

        return new Node(
            newLeft->sum
            + node->right->sum,
            newLeft,
            node->right
        );
    }

    else {

        Node* newRight =
            update(node->right,
                   mid + 1, r,
                   idx, val);

        return new Node(
            node->left->sum
            + newRight->sum,
            node->left,
            newRight
        );
    }
}

int query(Node* node,
          int l, int r,
          int ql, int qr) {

    if (qr < l || r < ql)
        return 0;

    if (ql <= l && r <= qr)
        return node->sum;

    int mid = (l + r) / 2;

    return
        query(node->left,
              l, mid,
              ql, qr)
      + query(node->right,
              mid + 1, r,
              ql, qr);
}


void solve(){
   int n, q; cin >> n >> q;
   vector<int> a(n+1);

   for(int i=1; i<=n; i++) {
      cin >> a[i];
   }

   vector<Node*> roots;

   roots.push_back(build(1, n, a));

   while(q--) {
      int type; cin  >> type;

      if(type == 1) {
         int k, idx, x;
         cin >> k >> idx >> x;

         k--;

         roots[k] = update(roots[k], 1, n, idx, x);
      }
      else if(type == 2) {
         int k, l, r; 
         cin >> k >> l >> r;

         k--;

         cout << query(roots[k], 1, n, l, r) << endl;
      }
      else {
         int k; cin >> k;
         k--;
         roots.push_back(roots[k]);
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
   
   this is a Oersistent Segment Tree problem

   each array version has its own segment tree root

   when we update;   
      only O(logn) nodes change

   all other nodes are reused

   so copying an array is just

      roots.push_back(roots[k])
   
   which is just o(1)


   Persistent Segment Tree
   each node stores: 
      sum
      left child
      right child

   update creates newnodes only on the update path

   Complexity: 
      build o(n)
      update o(logn)
      query o(logn)
      copy o(1)


      perfect for 2e5

*/