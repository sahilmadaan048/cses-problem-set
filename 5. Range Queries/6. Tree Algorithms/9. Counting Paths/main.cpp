
// https://cses.fi/problemset/task/1136

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

const int MAXN = 2e5+5;
const int LOG = 28;

vector<int> g[MAXN];
int parent[LOG][MAXN];
int depth[MAXN];
int cnt[MAXN];
int n, m;

void dfs(int node, int par, int d) {
   parent[0][node] = par;
   depth[node] = d;
   for(auto child: g[node]) {
      if(child == par) continue;
      dfs(child, node, d+1);
   }
}

int lca(int a, int b) {
   if(depth[a] < depth[b]) {
      swap(a, b);
   }

   int diff = depth[a] - depth[b];
   for(int i=0; i<LOG; i++) {
      if(diff & (1 << i)) {
         a = parent[i][a];
      }
   }

   if(a == b) return a;

   for(int i=LOG-1; i>=0; i--) {
      if(parent[i][a] != parent[i][b]) {
         a = parent[i][a];
         b = parent[i][b];
      }
   }

   return parent[0][a];
}

void dfs2(int node, int par) {
   for(auto child: g[node]) {
      if(child == par) continue;
      dfs2(child, node);
      cnt[node] += cnt[child];
   }
}

void solve(){
   cin >> n >> m;

   for(int i=1; i<=n; i++) {
      g[i].clear();
   }

   for(int i=1; i<=n-1; i++) {
      int a, b; cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
   }

   dfs(1, 0, 0);

   for(int i=1; i<LOG; i++) {
      for(int j=1; j<=n; j++) {
         parent[i][j] = parent[i-1][parent[i-1][j]];
      }
   }


   while(m--) {
      int a, b; cin >> a >> b;

      int l = lca(a, b);

      cnt[a]++;
      cnt[b]++;

      cnt[l]--;

      if(parent[0][l] != 0) {
         cnt[parent[0][l]]--;
      }
   }

   dfs2(1, 0);

   for(int i=1; i<=n; i++) {
      cout << cnt[i] << " ";
   }

   cout << "\n";
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
