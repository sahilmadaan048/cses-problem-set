#include <bits/stdc++.h>
using namespace std;

int longestDecreasingSubsequence(const vector<int>& h) {
    vector<int> tails; // stores smallest tail of all decreasing subsequences by length

    for (int x : h) {
        // We want strictly decreasing, so we do binary search to find
        // the position to replace in tails for x.
        // Since tails stores decreasing sequences, we invert comparison.

        auto it = upper_bound(tails.begin(), tails.end(), x, greater<int>());
        if (it == tails.end()) {
            tails.push_back(x);
        } else {
            *it = x;
        }
    }
    return (int)tails.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> h(n);
    for (int &x : h) cin >> x;

    cout << longestDecreasingSubsequence(h) << "\n";
    return 0;
}
