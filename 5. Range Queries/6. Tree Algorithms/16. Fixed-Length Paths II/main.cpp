// Author - sahilmadaan048
// https://cses.fi/problemset/task/2081

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 200005;

int n,k1,k2;
vector<int> adj[MAXN];

bool dead[MAXN];
int sub[MAXN];

ll ans=0;

struct Fenwick{
    int bit[MAXN];

    void add(int i,int v){
        i++;
        while(i<MAXN){
            bit[i]+=v;
            i+=i&-i;
        }
    }

    int sum(int i){
        if(i<0) return 0;
        i++;
        int s=0;
        while(i){
            s+=bit[i];
            i-=i&-i;
        }
        return s;
    }

    int query(int l,int r){
        if(l>r) return 0;
        l=max(l,0);
        r=min(r,n);
        if(l>r) return 0;
        return sum(r)-sum(l-1);
    }

} bit;


//-------------------------
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

void get_depths(int u,int p,int d, vector<int>& depths){
    if(d>k2) return;

    depths.push_back(d);

    for(int v:adj[u]){
        if(v==p || dead[v]) continue;
        get_depths(v,u,d+1,depths);
    }
}

//-------------------------
void decompose(int entry){

    dfs_size(entry,-1);
    int c=centroid(entry,-1,sub[entry]);

    dead[c]=true;

    vector<int> touched;

    bit.add(0,1);
    touched.push_back(0);

    for(int v:adj[c]){
        if(dead[v]) continue;

        vector<int> depths;
        get_depths(v,c,1,depths);

        // count paths
        for(int d:depths){
            ans += bit.query(k1-d,k2-d);
        }

        // add this subtree
        for(int d:depths){
            bit.add(d,1);
            touched.push_back(d);
        }
    }

    // clear BIT
    for(int d:touched)
        bit.add(d,-1);

    for(int v:adj[c]){
        if(!dead[v])
            decompose(v);
    }
}

//-------------------------

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