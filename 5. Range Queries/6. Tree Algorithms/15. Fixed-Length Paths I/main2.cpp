#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 200005;

int n,k;
vector<int> adj[MAXN];

bool removed[MAXN];
int sub[MAXN];

ll ans=0;

int cnt[MAXN]; // frequency of depths

void dfs_size(int u,int p){
    sub[u]=1;
    for(int v:adj[u]){
        if(v==p || removed[v]) continue;
        dfs_size(v,u);
        sub[u]+=sub[v];
    }
}

int get_centroid(int u,int p,int sz){
    for(int v:adj[u]){
        if(v==p || removed[v]) continue;
        if(sub[v] > sz/2)
            return get_centroid(v,u,sz);
    }
    return u;
}


void query_depths(int u,int p,int depth){
    if(depth>k) return;

    ans += cnt[k-depth];

    for(int v:adj[u]){
        if(v==p || removed[v]) continue;
        query_depths(v,u,depth+1);
    }
}

void add_depths(int u,int p,int depth){
    if(depth>k) return;

    cnt[depth]++;

    for(int v:adj[u]){
        if(v==p || removed[v]) continue;
        add_depths(v,u,depth+1);
    }
}


void solve(int entry){

    dfs_size(entry,-1);
    int c=get_centroid(entry,-1,sub[entry]);

    removed[c]=true;

    cnt[0]=1;

    for(int v:adj[c]){
        if(removed[v]) continue;

        // count paths with previous subtrees
        query_depths(v,c,1);

        // then add this subtree
        add_depths(v,c,1);
    }

    // clear counts used for this centroid
    cnt[0]=0;
    for(int v:adj[c]){
        if(removed[v]) continue;
        add_depths(v,c,1); // currently adds again...
    }

    // proper clearing:
    function<void(int,int,int)> clear_depths =
    [&](int u,int p,int depth){
        if(depth>k) return;
        cnt[depth]=0;
        for(int x:adj[u]){
            if(x==p || removed[x]) continue;
            clear_depths(x,u,depth+1);
        }
    };

    for(int v:adj[c]){
        if(!removed[v])
            clear_depths(v,c,1);
    }

    for(int v:adj[c]){
        if(!removed[v])
            solve(v);
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

    solve(1);

    cout<<ans<<"\n";
}