#include <bits/stdc++.h>
using namespace std;
#define ll long long

int maxSubsetXOR(vector<int> & a) {
    int n = a.size();
    int BITS = 63;
    vector<int> basis(BITS+1, 0);

    for(int num: a) {
        int x = num;
        for(int i=BITS; i>=0; i--) {
            if(!(x & (1LL << i))) continue;

            if(!basis[i]) {
                basis[i] = x;
                break;
            }
            x ^= basis[i];
        }
    }

    int ans = 0;
    for(int i=BITS; i>=0; i--) {
        ans = max(ans, ans ^ basis[i]);
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n ;
    vector<int> a(n);

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    cout << maxSubsetXOR(a) << "\n";
}
