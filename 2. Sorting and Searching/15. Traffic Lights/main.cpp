// https://cses.fi/problemset/task/1163
// Author - sahilmadaan048


#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, n;
    cin >> x >> n;
    
    set<int> positions;          
    multiset<int> segments;     

    positions.insert(0);
    positions.insert(x);
    segments.insert(x);

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;

        auto it = positions.upper_bound(p);
        int right = *it;
        int left = *prev(it);

        segments.erase(segments.find(right - left));

        segments.insert(p - left);
        segments.insert(right - p);

        positions.insert(p);

        cout << *segments.rbegin() << " ";
    }
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
