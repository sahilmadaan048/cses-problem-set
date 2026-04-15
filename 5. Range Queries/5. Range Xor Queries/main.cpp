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


vector<int> arr;
vector<int> seg;


void build(int index, int low, int high) {

   if(low == high) {
      seg[index] = arr[low];
      return;
   }

   int mid = (low + high ) / 2;
   build(2*index+1, low, mid);
   build(2*index+2, mid+1, high);

   seg[index] = (seg[2*index+1] ^ seg[2*index+2]);
}


int query(int index, int low, int high, int l, int r) {
 if (low >= l && high <= r) {
  return seg[index];
}

if (high < l || low > r) {
   return 0;   
}

int mid = (low + high) / 2;
int left = query(2*index+1, low, mid, l, r);
int right = query(2*index+2, mid+1, high, l, r);

return (left ^ right);
}

void solve(){
   int n, q; cin >> n >> q;


   arr.resize(n);

   for(int i=0; i<n; i++) {
      cin >> arr[i];
   }

   seg.resize(4*n);

   build(0, 0, n-1);

   while(q--) {
      int a, b; cin >> a >> b;
      a--;
      b--;
      cout << query(0, 0, n-1, a, b) << "\n"; 
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
