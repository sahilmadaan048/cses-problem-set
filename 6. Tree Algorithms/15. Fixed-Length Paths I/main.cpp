// https://cses.fi/problemset/task/2080
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

const int MAXN = 200005;

int n, k;
vector<int> adj[MAXN];
bool removed[MAXN];
int sub[MAXN];

int ans = 0;


void dfs_size(int u, int p){
    sub[u]=1;
    for(int v: adj[u]){
        if(v==p || removed[v]) continue;
        dfs_size(v,u);
        sub[u]+=sub[v];
    }
}

int dfs_centroid(int u,int p,int sz){
    for(int v: adj[u]){
        if(v==p || removed[v]) continue;
        if(sub[v] > sz/2)
            return dfs_centroid(v,u,sz);
    }
    return u;
}

void get_depths(int u,int p,int depth, vector<int>& depths){
    if(depth>k) return;
    depths.push_back(depth);

    for(int v: adj[u]){
        if(v==p || removed[v]) continue;
        get_depths(v,u,depth+1,depths);
    }
}

void decompose(int entry){

    dfs_size(entry,-1);
    int c = dfs_centroid(entry,-1,sub[entry]);

    removed[c]=true;

    vector<int> cnt(k+1,0);
    cnt[0]=1;

    for(int v: adj[c]){

        if(removed[v]) continue;

        vector<int> depths;
        get_depths(v,c,1,depths);

        // count paths using previously processed subtrees
        for(int d: depths){
            if(d<=k)
                ans += cnt[k-d];
        }

        // add this subtree into frequency
        for(int d: depths){
            if(d<=k)
                cnt[d]++;
        }
    }

    for(int v: adj[c]){
        if(!removed[v])
            decompose(v);
    }
}
void solve(){
    cin>>n>>k;

    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    decompose(1);

    cout<<ans<<"\n";
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
