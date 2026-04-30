// https://cses.fi/problemset/task/2190
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


void solve() {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    auto orient = [&](int ax,int ay,int bx,int by,int cx,int cy){
        return (bx-ax)*(cy-ay) - (by-ay)*(cx-ax);
    };

    auto onSegment = [&](int ax,int ay,int bx,int by,int cx,int cy){
        return min(ax,bx) <= cx && cx <= max(ax,bx) &&
               min(ay,by) <= cy && cy <= max(ay,by);
    };

    int o1 = orient(x1,y1,x2,y2,x3,y3);
    int o2 = orient(x1,y1,x2,y2,x4,y4);
    int o3 = orient(x3,y3,x4,y4,x1,y1);
    int o4 = orient(x3,y3,x4,y4,x2,y2);

    // Proper intersection
    if ((o1 > 0 && o2 < 0 || o1 < 0 && o2 > 0) &&
        (o3 > 0 && o4 < 0 || o3 < 0 && o4 > 0)) {
        cout << "YES\n";
        return;
    }

    // Collinear cases
    if (o1 == 0 && onSegment(x1,y1,x2,y2,x3,y3)) { cout<<"YES\n"; return; }
    if (o2 == 0 && onSegment(x1,y1,x2,y2,x4,y4)) { cout<<"YES\n"; return; }
    if (o3 == 0 && onSegment(x3,y3,x4,y4,x1,y1)) { cout<<"YES\n"; return; }
    if (o4 == 0 && onSegment(x3,y3,x4,y4,x2,y2)) { cout<<"YES\n"; return; }

    cout << "NO\n";
}

int orientation(int x1, int y1,  int x2, int y2, int x3, int y3) {
   return (x2 - x1) * (y3 - y1)
              - (y2 - y1) * (x3 - x1);
}

void solve2(){
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    /*

   orientation(A,B,C) ≠ orientation(A,B,D)
AND
   orientation(C,D,A) ≠ orientation(C,D,B)
   
   */

    if(orientation(x1, y1, x2, y2, x3, y3) != orientation(x1, y1, x2, y2, x4, y4)

      and orientation(x3, y3, x4, y4,  x1, y1) != orientation(x3, y3, x4, y4, x2, y2)) {

         cout << "YES\n"; 
    }
    else {
      cout << "NO\n";
    }
}

int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

    int T ; cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
