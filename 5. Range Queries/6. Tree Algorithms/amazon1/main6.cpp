#include <bits/stdc++.h>
using namespace std;

int getValidConfigurations(vector<int> a) {
    int n = a.size();
    sort(a.begin(), a.end());

    int ans = 0;

    if(a[0] > 0) ans++;

    for(int k=1;k<=n;k++){
        if(a[k-1] > k-1) continue;
        if(k==n || a[k] > k) ans++;
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i=0;i<n;i++)
        cin >> a[i];

    cout << getValidConfigurations(a);
}