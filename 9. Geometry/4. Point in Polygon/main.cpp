// https://cses.fi/problemset/task/2192
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


int orientation(int x1,int y1,
                int x2,int y2,
                int x3,int y3)
{
    return (x2-x1)*(y3-y1) - (y2-y1)*(x3-x1);
}

bool onSegment(int x1,int y1,
               int x2,int y2,
               int x,int y)
{
    return min(x1,x2)<=x && x<=max(x1,x2) &&
           min(y1,y2)<=y && y<=max(y1,y2);
}

void solve(){
  int n, m;
    cin >> n >> m;

    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++)
        cin >> v[i].first >> v[i].second;

    while(m--){
        int x, y;
        cin >> x >> y;

        bool inside = false;
        bool boundary = false;

        for(int i=0;i<n;i++){
            int j = (i+1)%n;

            int x1 = v[i].first;
            int y1 = v[i].second;
            int x2 = v[j].first;
            int y2 = v[j].second;

            // Check boundary
            if(orientation(x1,y1,x2,y2,x,y)==0 &&
               onSegment(x1,y1,x2,y2,x,y)){
                boundary = true;
                break;
            }

            // Ray casting
            bool intersect = ((y1 > y) != (y2 > y)) &&
                (x < (x2-x1)*(y-y1)/(double)(y2-y1) + x1);

            if(intersect)
                inside = !inside;
        }

        if(boundary) cout << "BOUNDARY\n";
        else if(inside) cout << "INSIDE\n";
        else cout << "OUTSIDE\n";
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
