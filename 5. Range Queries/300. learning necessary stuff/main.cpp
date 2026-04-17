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

// range update + point query


/*

Type 1:
Add u to all elements in range [a, b]

Type 2:
Print value at index k



*/

struct Fenwick {
   int n; 
   vector<int> bit;

   Fenwick(int n) {
      this->n = n;

      bit.assign(n+1, 0);
   } 

   // add "val" at index "idx"

   void update(int idx, int val) {
      for(; idx<=n; idx += idx&-idx) {
         bit[idx] += val;
      }
   }

   // get prefix sum from 1 to idx


   int query(int idx) {
      int sum = 0;
      for(; idx>0; idx -= idx & -idx) {
         sum += bit[idx];
      }

      return sum;
   }
}

void solve(){
   int n, q; 
   cin >> n >> q;

   vector<int> arr(n+1);

   for(int i=1; i<=n; i++) {  
      cin >> arr[i];
   }

   Fenwick ft(n);

   while(q--) {
      int type; cin >> type;
      if(type == 1) {
         int a, b, u; cin >> a >> b >> u;

         ft.update(a, u);
         if(b+1 <= n) {
            ft.update(b+1, -u);
         }
      }

      else {
         int k; cin >> k;

         // point query
         cout << arr[k] + ft.query(k) << "\n";
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

Fenwick Tree (Binary Indexed Tree)
   - it stores prefix sums efficiently

   query(k) = a[1] + a[2] +... +a[k]

   - it supports 
      - point update in O(logn)
      - prefix sum query in O(logn)

   idx += idx & -idx

   - this is the heart of fenwick
      
      (idx & -idx)

   - it gives  the last set bit of idx

   idx = 12
   binary = 1100
   -idx   = 0100
   AND    = 0100 => (4) in decimal

      (idx & -idx) 

   - tells us how much range this index is responsible for
   
   - what does bit[i] store ?
      - each index stores sum of a specific block

   n = 8

   index = 1 2 3 4 5 6 7 8 

   bit[i] stores

   1 -> [1]
   2 -> [1,2]
   3 -> [3]
   4 -> [1,2,3,4]
   5 -> [5]
   6 -> [5,6]
   7 -> [7]
   8 -> [1..8]


   each index covers => 
     i - (i & -i) + 1  →  i


   for i = 1 ((i & -i) => 0001 & 1111 -> 0001 => 1) => 1 - 1 + 1 to 1 => 1 to 1  => [1]   ✅
   for i = 2 ((i & -i) => 0010 & 1110 -> 0010 => 2) => 2 - 2 + 1 to 2 => 1 to 2  => [1, 2] ✅
   for i = 3 ((i & -i) => 0011 & 1101 -> 0001 => 1) => 3 - 1 + 1 to 3 => 3 to 3  => [3]
   for i = 4 ((i & -i) => 0100 & 1100 -> 0100 => 4) => 4 - 4 + 1 to 4 => 1 to 4  => [1, 2, 3, 4] ✅
   for i = 5 ((i & -i) => 0101 & 1011 -> 0001 => 1) => 5 - 1 + 1 to 5 => 5 to 5  => [5]
   for i = 6 ((i & -i) => 0110 & 1010 -> 0010 => 2) => 6 - 2 + 1 to 6 => 5 to 6  => [5, 6]
   for i = 7 ((i & -i) => 0111 & 1001 -> 0001 => 1) => 7 - 1 + 1 to 7 => 7 to 7  => [7]
   for i = 8 ((i & -i) => 1000 & 1000 -> 1000 => 8) => 8 - 8 + 1 to 8 => 1 to 8  => [1, 2, 3, 4, 5, 6, 7, 8]  ✅


   observation => for a number which is a direct powers of 2 (1, 2, 4, 8) => range starts from 1 to that number
   since i => i & -i thus window sum till that is directly stores in that index
         

   each power of 2 index stores => prefix sum from 1 to i 

   
   well that handles the windows which have size of powers of 2

   now what about the windows sizes which are not ?
      for example -> 3, 5, 6, 7  (now these can alwasys be written in terms of the perfect power numbers)
      
      each number k can be broken down into sum of chunks of powers of 2 

      thats why we do this

      while(k > 0) {
         sum += bit[k]
         k -= (k & -k)
      } 


      k = 13 (1101)
      
      add bit[13]  (covers last 1 element)
      k = 13 - 1 = 12
   
      add bit[12] (covers 4 elements)
      k = 12 - 4 = 8
      
      add bit[8] (covers 8 elements)
      k = 8 - 8 = 0

   
      1 + 4 + 8 = 13 elements 

      So query is just decomposing number into powers of 2 using its binary form.



      Index:  1 2 3 4 5 6 7 8
      Blocks:
      1       [1]
      2       [1 2]
      3             [3]
      4       [1 2 3 4]
      5                   [5]
      6                   [5 6]
      7                         [7]
      8       [1 2 3 4 5 6 7 8]  
*/