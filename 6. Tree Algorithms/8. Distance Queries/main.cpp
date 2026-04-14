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


// distance(a, b) = depth(a)+depth(b) - 2*lca(a, b)


void solve(){
    int n, q; 
    cin >> n >> q;

    vector<vector<int>> adj(n);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int LOG = 20; // since 2^20 > 2e5
    vector<vector<int>> parent(n, vector<int>(LOG));
    vector<int> depth(n);

    // DFS to compute depth + immediate parent
    function<void(int,int)> dfs = [&](int node, int par){
        parent[node][0] = par;
        for(auto child : adj[node]){
            if(child == par) continue;
            depth[child] = depth[node] + 1;
            dfs(child, node);
        }
    };

    dfs(0, 0); // root at node 0

    // Build binary lifting table
    for(int j = 1; j < LOG; j++){
        for(int i = 0; i < n; i++){
            parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }

    // Function to compute LCA
    auto lca = [&](int a, int b){

        if(depth[a] < depth[b])
            swap(a, b);

        // Lift a up to same depth
        int diff = depth[a] - depth[b];
        for(int j = 0; j < LOG; j++){
            if(diff & (1 << j))
                a = parent[a][j];
        }

        if(a == b) return a;

        // Lift both up
        for(int j = LOG-1; j >= 0; j--){
            if(parent[a][j] != parent[b][j]){
                a = parent[a][j];
                b = parent[b][j];
            }
        }

        return parent[a][0];
    };

    while(q--){
        int a, b;
        cin >> a >> b;
        a--; b--;

        int L = lca(a, b);
        int dist = depth[a] + depth[b] - 2 * depth[L];

        cout << dist << "\n";
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
