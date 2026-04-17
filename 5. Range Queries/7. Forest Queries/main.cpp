// Author - sahilmadaan048


// https://cses.fi/problemset/task/1652


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


void modadd(int &a  , int b) {a=((a%MOD)+(b%MOD))%MOD;}
void modsub(int &a , int b) {a=((a%MOD)-(b%MOD)+MOD)%MOD;}
void modmul(int &a , int b) {a=((a%MOD)*(b%MOD))%MOD;}
// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================

struct Fenwick {
   int n;
   vector<int> bit;

   Fenwick(int n) {
      this->n = n;
      bit.assign(n+1, 0);
   }

   void update(int idx, int val) {
      for(; idx <= n; idx += idx & -idx) {
         bit[idx] += val;
      }
   }

   int query(int idx) {
      int sum = 0;

      for(; idx > 0; idx -= idx&-idx) {
         sum += bit[idx];
      }

      return sum;
   }
};


void solve() {
   int n,q ; cin >>  n >> q;
   vector<string> grid(n);

   for(int i=0; i<n; i++) {
      cin >> grid[i];
   }

   vector<vector<int>> pref(n+1, vector<int> (n+1, 0));

   // build a 2D prefix sum array

   for(int i=1; i<=n; i++) {
      for(int j=1; j<=n; j++) {
         int star = (grid[i-1][j-1] == '*');

         pref[i][j] = star + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
      }
   }

   while(q--) {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;

      int ans = pref[x2][y2] - pref[x1-1][y2] - pref[x2][y1-1] + pref[x1-1][y1-1];

      cout << ans << "\n";
   }

   return;
}


/*

void solve(){
   int n, q; cin >> n >> q;
   vector<string> temp(n);

   for(int i=0; i<n; i++) {
      cin >> temp[i];   
   }

   Fenwick ft(n);

   while(q--) {
      int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
      x1--;
      y1--;
      x2--;
      y2--;
   
      // start points -> (x1, y1)    (x1, y2)      
      // end points ->   (x2, y1)    (x2, y2)      

      int cnt = 0;

      for(int i=x1; i<=x2; i++) {
         for(int j=0; j<n; j++) {
            if(temp[i][j] == '*') {
               ft.update(j, 1);
            }
         }
         cnt += (ft.query(i));
      }

      cout << cnt << "\n";
   }  
}

*/

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



// .**
// *..


/*



| Problem Type             | Data Structure |
| ------------------------ | -------------- |
| Static range sum (1D)    | Prefix sum     |
| Static range sum (2D)    | 2D prefix      |
| Point update + range sum | Fenwick        |
| Range update + range sum | Lazy segtree   |
| Rectangle sum + updates  | 2D Fenwick     |





Final Complexity Summary

Time Complexity:
=> O(n²) + O(n²) + O(q)
=> O(n² + q)

Space Complexity:
=> O(n²)

*/