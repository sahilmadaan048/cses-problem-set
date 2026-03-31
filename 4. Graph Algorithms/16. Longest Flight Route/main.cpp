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

int n, m; 

unordered_map<int, vector<int>> mpp;

void dfs(int node, vector<int>& vis, stack<int> &st) {
   vis[node] = 1;

   for(auto it: mpp[node]) {
      if(!vis[it]) {
         dfs(it, vis,  st);
      }
   }
   st.push(node);
}


void solve(){

   cin >> n >> m;


   for(int i=0; i<m; i++) {
      int a, b; cin >> a >> b;
      mpp[a].push_back(b);
   }

   vector<int> vis(n+1, 0);

   stack<int> st;

   for(int i=1; i<=n; i++) {
      if(!vis[i]) {
         dfs(i, vis, st);
      }
   }

   vector<int> dist(n+1, INT_MIN);  // dist[i] = maximum number of edges from source (1) to node i
   vector<int> parent(n+1, -1);

   dist[1] = 0;  // 1 -> source

   while(!st.empty()) {
      int node = st.top();
      st.pop();

      if(dist[node] != INT_MIN) {
         for(auto it: mpp[node]) {
            if(dist[node] + 1 > dist[it]) {
               dist[it] = dist[node] + 1;
               parent[it] = node;
            }
         }
      }
   }

   if(dist[n] == INT_MIN) {
      cout << "IMPOSSIBLE\n";
      return;
   }

   vector<int> path;

   for(int cur=n; cur != -1; cur = parent[cur]) {
      path.push_back(cur);
   }

   reverse(path.begin(), path.end());

   cout << path.size() << "\n";

   for(int node: path) {
      cout << node << " ";
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
