// https://cses.fi/problemset/task/2185/
// Author - sahilmadaan048

#include<bits/stdc++.h>
using namespace std;

using int64 = long long;
using i128 = __int128_t;

int64 gcdll(int64 a,int64 b){
    return b ? gcdll(b,a%b) : a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64 n;
    int k;
    cin>>n>>k;

    vector<int64> a(k);
    for(auto &x:a) cin>>x;

    sort(a.begin(),a.end());

    // remove duplicates
    a.erase(unique(a.begin(),a.end()),a.end());

    // remove redundant multiples
    vector<int64> b;
    for(int i=0;i<a.size();i++){
        bool redundant=false;
        for(int j=0;j<i;j++){
            if(a[i]%a[j]==0){
                redundant=true;
                break;
            }
        }
        if(!redundant) b.push_back(a[i]);
    }

    a=b;
    k=a.size();

    int64 ans=0;

    for(int mask=1; mask<(1<<k); mask++){

        i128 lcm=1;
        int bits=0;
        bool bad=false;

        for(int i=0;i<k;i++){
            if(mask&(1<<i)){

                bits++;

                int64 g=gcdll((int64)lcm,a[i]);

                // overflow-safe early prune
                if(lcm/g > n/a[i]){
                    bad=true;
                    break;
                }

                lcm=(lcm/g)*a[i];
            }
        }

        if(bad) continue;

        int64 cnt=n/(int64)lcm;

        if(bits&1) ans+=cnt;
        else ans-=cnt;
    }

    cout<<ans<<"\n";
}