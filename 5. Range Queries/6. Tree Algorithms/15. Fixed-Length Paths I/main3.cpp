#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 200005;

int n,k;
vector<int> adj[MAXN];

bool dead[MAXN];
int sub[MAXN];

ll ans=0;

int cnt[MAXN];

// subtree sizes
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
void get_depths(int u,int p,int d, vector<int>& depths){
    if(d>k) return;
    depths.push_back(d);

    for(int v:adj[u]){
        if(v==p || dead[v]) continue;
        get_depths(v,u,d+1,depths);
    }
}

void decompose(int entry){

    dfs_size(entry,-1);
    int c = centroid(entry,-1,sub[entry]);

    dead[c]=true;

    vector<int> touched;
    cnt[0]=1;
    touched.push_back(0);

    for(int v:adj[c]){
        if(dead[v]) continue;

        vector<int> depths;
        get_depths(v,c,1,depths);

        // count pairs
        for(int d:depths){
            ans += cnt[k-d];
        }

        // add subtree depths
        for(int d:depths){
            if(cnt[d]==0) touched.push_back(d);
            cnt[d]++;
        }
    }

    // clear only used depths
    for(int d:touched)
        cnt[d]=0;

    for(int v:adj[c]){
        if(!dead[v])
            decompose(v);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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