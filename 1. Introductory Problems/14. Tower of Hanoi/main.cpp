#include "bits/stdc++.h"
#define int long long
#define vi vector<int>
#define vb vector<bool>
#define fr(i,n) for(int i=0; i<(n); i++)
#define rep(i,a,n) for(int i=(a); i<=(n); i++)
#define nl cout<<"\n"
#define all(v) v.begin(),v.end()
#define sz(v) (int)(v.size())
#define srt(v)  sort(v.begin(),v.end())         
#define mxe(v)  *max_element(v.begin(),v.end())     
#define mne(v)  *min_element(v.begin(),v.end())     
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end())))
#define bin(x,y)  bitset<y>(x) 
using namespace std;
int MOD = 1e9+7;

// Modular arithmetic helpers (not needed here but fine to keep)
void modadd(int &a , int b) {a=((a%MOD)+(b%MOD))%MOD;}
void modsub(int &a , int b) {a=((a%MOD)-(b%MOD)+MOD)%MOD;}
void modmul(int &a , int b) {a=((a%MOD)*(b%MOD))%MOD;}

// Input/Output helpers
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }

// Use different variable than 'count'
int moveCount = 0;
vector<pair<char, char>> moves;

void towerOfHanoi(int n, char start, char helper, char end) {
    if(n == 1) {
        moves.emplace_back(start, end);
        moveCount++;
        return;
    }    
    towerOfHanoi(n-1, start, end, helper);
    moves.emplace_back(start, end);
    moveCount++;
    towerOfHanoi(n-1, helper, start, end);
}

void solve(){
    int n; cin >> n;
    towerOfHanoi(n, '1', '2', '3');
    cout << moveCount << "\n";
    for (auto &[from, to] : moves) {
        cout << from << " " << to << "\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
