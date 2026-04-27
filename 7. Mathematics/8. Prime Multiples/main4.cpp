#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using i128 = __int128_t;

ll n;
vector<ll> a;

ll gcdll(ll a,ll b){
    return b ? gcdll(b,a%b):a;
}

ll solve(int idx, i128 cur, int sign){

    ll res=0;

    for(int i=idx;i<(int)a.size();i++){

        ll g=gcdll((ll)cur,a[i]);

        if(cur/g > n/a[i]) continue;

        i128 nxt=(cur/g)*a[i];

        ll cnt=n/(ll)nxt;

        res += sign*cnt;

        res += solve(i+1,nxt,-sign);
    }

    return res;
}

int main(){
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   while(cin>>n){

    int k;
    cin>>k;

    a.assign(k,0);

    for(auto &x:a) cin>>x;

        sort(a.begin(),a.end());

    vector<ll> b;

    for(ll x:a){
        bool skip=false;
        for(ll y:b){
            if(x%y==0){
                skip=true;
                break;
            }
        }
        if(!skip) b.push_back(x);
    }

    a=b;

    cout<<solve(0,1,1)<<"\n";
}
}