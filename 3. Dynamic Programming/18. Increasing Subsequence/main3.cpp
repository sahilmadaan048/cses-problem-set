// https://cses.fi/problemset/task/1145


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> temp(n);
    for (int i = 0; i < n; i++) cin >> temp[i];

    vector<int> tails;  // tails[i] = min tail value for subsequence of length i+1
    for (int x : temp) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end())
            tails.push_back(x);
        else
            *it = x;
    }

    cout << (int)tails.size() << "\n";
    return 0;
}
