// https://cses.fi/problemset/task/3211

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    const int MAXB = 60;
    int basis[MAXB] = {0};

    for(int x: a) {
        for(int b=MAXB-1; b>=0; b--) {
            if(!(x >> b & 1)) continue;
            if(!basis[b]) {
                basis[b] = x;
                break;
            }
            x ^= basis[b];
        }
    }

    int k = 0;
    for(int i=0; i<MAXB; i++) {
        if(basis[i]) {
            k++;
        }
    }

    cout << (1LL << k) << "\n";

    return 0;
}