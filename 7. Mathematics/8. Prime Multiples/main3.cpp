
// https://cses.fi/problemset/task/2185/
// Author - sahilmadaan048

#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using i128 = __int128_t;

int64 n;
vector<int64> a;
int64 ans = 0;

int64 gcdll(int64 a,int64 b){
    return b ? gcdll(b,a%b) : a;
}

void dfs(int idx, i128 cur_lcm, int taken){

    for(int i=idx;i<(int)a.size();i++){

        int64 g = gcdll((int64)cur_lcm,a[i]);

        // if new lcm > n skip
        if(cur_lcm/g > n/a[i])
            continue;

        i128 new_lcm = (cur_lcm/g)*a[i];

        int64 cnt = n/(int64)new_lcm;

        if((taken+1)&1) {
            ans += cnt;
        }
        else {
            ans -= cnt;
        }

        dfs(i+1,new_lcm,taken+1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> n >> k;

    a.resize(k);
    for(auto &x:a)
        cin >> x;

    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());

    // remove redundant multiples
    vector<int64> b;

    for(int64 x : a){
        bool redundant=false;

        for(int64 y : b){
            if(x % y == 0){
                redundant=true;
                break;
            }
        }

        if(!redundant)
            b.push_back(x);
    }

    a=b;

    dfs(0,1,0);

    cout << ans << "\n";
}