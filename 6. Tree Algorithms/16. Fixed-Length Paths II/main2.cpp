#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 200005;

int n,k1,k2;
vector<int> adj[MAXN];

bool dead[MAXN];
int sub[MAXN];

ll ans=0;

int cnt[MAXN];

//------------------------
void dfs_size(int u,int p){
    sub[u]=1;
    for(int v:adj[u]){
        if(v==p || dead[v]) continue;
        dfs_size(v,u);
        sub[u]+=sub[v];
    }
}

int centroid(int u,int p,int sz){
    for(int v:adj[u]){
        if(v==p || dead[v]) continue;
        if(sub[v] > sz/2)
            return centroid(v,u,sz);
    }
    return u;
}

// collect depths
void get_depths(int u,int p,int d,vector<int>& depths){
    if(d>k2) return;

    depths.push_back(d);

    for(int v:adj[u]){
        if(v==p || dead[v]) continue;
        get_depths(v,u,d+1,depths);
    }
}

//------------------------

void decompose(int entry){

    dfs_size(entry,-1);
    int c=centroid(entry,-1,sub[entry]);

    dead[c]=true;

    vector<int> touched;

    cnt[0]=1;
    touched.push_back(0);

    int maxDepth=0;

    for(int v:adj[c]){
        if(dead[v]) continue;

        vector<int> depths;
        get_depths(v,c,1,depths);

        // build prefix sums once
        static int pref[MAXN];
        pref[0]=cnt[0];
        for(int i=1;i<=maxDepth;i++)
            pref[i]=pref[i-1]+cnt[i];

        // query this subtree
        for(int d:depths){

            int L=max(0,k1-d);
            int R=min(maxDepth,k2-d);

            if(L<=R){
                ans += pref[R]-(L?pref[L-1]:0);
            }
        }

        // add this subtree afterward
        for(int d:depths){
            if(cnt[d]==0) touched.push_back(d);
            cnt[d]++;
            maxDepth=max(maxDepth,d);
        }
    }

    // clear only used entries
    for(int d:touched)
        cnt[d]=0;

    for(int v:adj[c]){
        if(!dead[v])
            decompose(v);
    }
}

//------------------------

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>k1>>k2;

    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    decompose(1);

    cout<<ans<<"\n";
}