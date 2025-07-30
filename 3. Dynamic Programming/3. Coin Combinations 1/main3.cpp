#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;


int main() {
    ll N, X; cin >> N >> X;
    vector<ll> coins(N);
    for(int i=0; i<N; i++) cin >> coins[i];
    vector<ll> dp(X + 1, 0);  // Initialize dp with 0 while doing tabulation and while doung memoisation do it with -1
    
    dp[0] = 1;
    
    
    //to make it space oprimises, we need the previois  cells only which can be mantained using an array
    vector<ll> temp(N);
     
    temp[0] = 1;
    
    for(int i=1; i<=X; i++) {
        for(int j=0; j<N; j++) {
            int coin = coins[j];            
            if(i - coin >= 0) {
               temp[i] = (temp[i] + temp[i - coin]) %  mod; 
            }
        }
    }
    
    cout << dp[X] << endl;
}
