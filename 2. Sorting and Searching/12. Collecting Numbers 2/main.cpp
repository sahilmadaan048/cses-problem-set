#include "bits/stdc++.h"
#define int long long
#define vi vector<int>
using namespace std;

int MOD=1e9+7;

int calc_break(int x, unordered_map<int,int>& pos, int n) {
    int res = 0;
    if (x > 1 && pos[x-1] > pos[x]) res++;
    if (x < n && pos[x] > pos[x+1]) res++;
    return res;
}

void solve(){
    int n, m; cin >> n >> m;
    vi a(n);
    unordered_map<int,int> pos;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    int segments = 1;
    for(int i = 2; i <= n; i++) {
        if (pos[i-1] > pos[i]) segments++;
    }

    while(m--) {
        int u, v; cin >> u >> v;
        int iu = pos[u], iv = pos[v];

        set<int> to_check = {u, v};
        if (u > 1) to_check.insert(u-1);
        if (u < n) to_check.insert(u+1);
        if (v > 1) to_check.insert(v-1);
        if (v < n) to_check.insert(v+1);

        int before = 0, after = 0;
        for (int x : to_check) before += calc_break(x, pos, n);

        // Swap values in array
        swap(a[iu], a[iv]);

        // Update positions using new values at the positions
        pos[a[iu]] = iu;
        pos[a[iv]] = iv;

        for (int x : to_check) after += calc_break(x, pos, n);

        segments += (after - before);
        cout << segments << "\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
