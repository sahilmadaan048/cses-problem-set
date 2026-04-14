// Author - sahilmadaan048

// https://cses.fi/problemset/task/1686


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
vector<vector<int>> adj, radj;
vector<int> coins;
vector<bool> visited;
vector<int> order, comp;
vector<int> scc_sum;

/*

    - use kosaraju to collect all coins inside a SCC
    - condense SCC meaning now each SCC will be considered as a individual node
      thus the given directed graph now becomes , DAG since the different SCC's will never form a cycle
      otherwise they would not be called SCC's in the first place
    - now Problem reduces to maximum path sum in a DAG , use DP on Graphs to do this 

*/


void dfs1(int u)  {
    visited[u] = true;

    for(auto &v: adj[u]) {
        if(!visited[v]) {
            dfs1(v);
        }
    }

    order.push_back(u);
}

void dfs2(int u, int id) {
    comp[u] = id;
    scc_sum[id] += coins[u];
    for(int v: radj[u]) {
        if(comp[v] == -1) {
            dfs2(v, id);
        }
    }
}

void solve(){
    cin >> n >> m;

    adj.assign(n, {});
    radj.assign(n, {});
    coins.resize(n);
    visited.assign(n, false);

    for(int i=0; i<n; i++) {
        cin >> coins[i];
    }

    for(int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }
     

    // order by finisih time
    for (int i=0; i<n; i++) {
        if(!visited[i]) {
            dfs1(i);
        }
    }

    // assign SCC's now
    comp.assign(n, -1);
    scc_sum.assign(n, 0);

    int scc_count = 0;
    reverse(order.begin(), order.end()); // since elements are to be topped in LIFO fashion

    for(int u: order) {
        if(comp[u] == -1) {
            dfs2(u, scc_count);
            scc_count++;
        }
    }


    // lets make the condensed DAG
    vector<vector<int>> dag(scc_count);

    for(int u=0; u<n; u++) {
        for(int v: adj[u]) {
            if(comp[u] != comp[v]) {
                dag[comp[u]].push_back(comp[v]);
            }
        }
    }


    // now we will do DP on DAG
    vector<int> dp (scc_count, 0);

    for(int i=0; i<scc_count; i++) {
        dp[i] = scc_sum[i];
    }

    // since it is directed, we will traverse only in the topo sort oder
    // topo sort using  kahn algo involve ugina a queue and a indegree array 
    vector<int> indegree(scc_count, 0);
    for(int u=0; u<scc_count; u++) {
        for(int v: dag[u]) {
            indegree[v]++;
        }
    } 

    queue<int> q;
    for(int i=0; i<scc_count; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v: dag[u]) {
            dp[v] = max(dp[v] , dp[u] + scc_sum[v]);
            indegree[v]--;
            if(indegree[v] == 0) {
                q.push(v);
            } 
        }
    }

    int ans = 0;
    for(int i=0; i<scc_count; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";
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

