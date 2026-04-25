// https://cses.fi/problemset/task/1139

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



const int N = 200005;

int n;
vector<int> adj[N];
int color[N];
int ans[N];

set<int>* dfs(int node, int parent) {
 set<int>* cur = new set<int>();
 cur->insert(color[node]);

 for (int child : adj[node]) {
  if (child == parent) continue;

  set<int>* childSet = dfs(child, node);

        // small to large merging
  if (cur->size() < childSet->size())
   swap(cur, childSet);

for (int c : *childSet)
   cur->insert(c);
}

ans[node] = cur->size();
return cur;
}


void solve() {
   cin >> n;

   for (int i = 1; i <= n; i++)
     cin >> color[i];

  for (int i = 0; i < n - 1; i++) {
     int a, b;
     cin >> a >> b;
     adj[a].push_back(b);
     adj[b].push_back(a);
  }

  dfs(1, 0);

  for (int i = 1; i <= n; i++)
     cout << ans[i] << " ";

}

int32_t main() {
 ios::sync_with_stdio(false);
 cin.tie(NULL);

 int t=1;

 while(t--) {
   solve();
}
}