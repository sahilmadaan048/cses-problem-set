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


unordered_map<int, vector<int>> mpp;

int n, m;

vector<int> cycle;
bool found = false;

unordered_map<int, int> color;
unordered_map<int, int> parent;

void dfs(int u) {
   color[u] =  1;

   for(auto v: mpp[u]) {
      if(color[v] == 0) {
         parent[v] = u;
         dfs(v);
         if(found) return;
      }
      else if(color[v] == 1) {
         found = true;
         int cur = u;
         cycle.push_back(v);
         while(cur != v) {
            cycle.push_back(cur);
            cur = parent[cur];
         }
         cycle.push_back(v);
         reverse(cycle.begin(), cycle.end());
         return;
      }
   }
   color[u] = 2;
}

void solve(){  
   cin >> n >> m;
   for(int i=0; i<m; i++) {
      int u, v; cin >> u >> v;
      mpp[u].push_back(v);
   }

   for(auto p: mpp) {
      if(color[p.first] == 0) {
         dfs(p.first);
         if(found) break;
      }
   }

   if(found) {
      cout << cycle.size() << "\n";
      for(auto ele: cycle) cout << ele << " ";
      cout << "\n";
   }
   else {
      cout << "IMPOSSIBLE\n";
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
