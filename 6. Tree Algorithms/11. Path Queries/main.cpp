// https://cses.fi/problemset/task/1138
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

const int MAXN = 2e5 + 5;

int n, q;
vector<int> adj[MAXN];
int val[MAXN];

int in[MAXN], out[MAXN];
int timer = 0;

int bit[MAXN];

// fenwick tree to do range uupdate and point query

void update(int i, int v) {
   for(; i <= n; i+=i&-i) {
      bit[i] += v;
   }
}

int query(int i) {
   int s = 0;
   for(; i > 0 ; i -= i & -i) {
      s += bit[i];
   }
   return s;
}

void range_update(int l, int r, int v) {
   update(l, v);
   update(r+1, -v);
}

void dfs(int node, int parent) {
   in[node] = ++timer;

   for(auto child: adj[node]) {
      if(child == parent) continue;
      dfs(child, node);
   }

   out[node] = timer;
}


void solve(){
   cin >> n >> q;
   for(int i=1; i<=n; i++) {
      cin >> val[i];
   }

   for(int i=0; i<n-1; i++) {
      int a, b; cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
   }

   dfs(1, 0);

   for(int i=1; i<=n; i++) {
      range_update(in[i], out[i], val[i]);
   }

   while(q--) {
      int type;
      cin  >> type;

      if(type == 1) {
         int s, x; cin >> s >> x;
         int diff = x - val[s];

         val[s] = x;

         range_update(in[s], out[s], diff);
      }  
      else {
         int s; cin >> s;
         cout << query(in[s]) << "\n"; 
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
