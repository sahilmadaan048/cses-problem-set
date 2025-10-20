// https://cses.fi/problemset/task/3192


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    const int MAXB = 60;
    long long basis[MAXB] = {0};

    // Build XOR basis
    for (long long x : a) {
        for (int b = MAXB - 1; b >= 0; b--) {
            if (!(x >> b & 1)) continue;
            if (!basis[b]) { basis[b] = x; break; }
            x ^= basis[b];
        }
    }

    // Collect non-zero basis vectors
    vector<long long> B;
    for (int b = 0; b < MAXB; b++)
        if (basis[b]) B.push_back(basis[b]);
    sort(B.begin(), B.end());

    // Generate k smallest subset XORs
    vector<long long> vals = {0};
    for (long long v : B) {
        vector<long long> newVals;
        newVals.reserve(vals.size());
        for (auto x : vals) newVals.push_back(x ^ v);
        sort(newVals.begin(), newVals.end());

        // Merge both sorted lists while keeping at most k smallest
        vector<long long> merged;
        merged.reserve(min((long long)vals.size() * 2, k));
        int i = 0, j = 0;
        while ((long long)merged.size() < k &&
               (i < (int)vals.size() || j < (int)newVals.size())) {
            long long aVal = (i < (int)vals.size()) ? vals[i] : LLONG_MAX;
            long long bVal = (j < (int)newVals.size()) ? newVals[j] : LLONG_MAX;
            if (aVal <= bVal) merged.push_back(aVal), i++;
            else merged.push_back(bVal), j++;
        }
        vals.swap(merged);
    }

    // Output first k values
    for (int i = 0; i < (int)min<long long>(k, vals.size()); i++)
        cout << vals[i] << (i + 1 == k ? '\n' : ' ');

    return 0;
}
