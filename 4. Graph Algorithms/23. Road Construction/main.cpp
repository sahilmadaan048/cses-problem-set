
// https://cses.fi/problemset/task/1676
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

struct DSU {
   vector<int> parent, size;

   DSU(int n) {
      parent.resize(n+1);
      size.assign(n+1, 1);

      for(int i=1; i<=n; i++) {
         parent[i] = i;
      }
   }

   int find(int v) {
      if(v == parent[v]) {
         return v;
      }
      return parent[v] = find(parent[v]);
   }

   bool union_set(int a, int b) {
      a = find(a);
      b = find(b);
      
      if(a != b) {
         if(size[a] < size[b]) swap(a, b);
         parent[b] = a;
         size[a] += size[b];
         return true;
      }
      return false;
   }

   bool same_set(int a, int b)  {
      return find(a) == find(b);
   }

   int size_set(int v) {
      return size[find(v)];
   }
};

void solve(){
   cin >> n >> m;
   
   DSU dsu(n);

   int components = n;
   int largest = 1;

   for(int i=0; i<m; i++) {
      int a, b; cin >> a >> b;

      if(dsu.union_set(a, b)) {
         components--; // wre merged these 2
         largest = max(largest, dsu.size_set(a));
      }
      cout << components << " " << largest << "\n";
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
