#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> diffs(n);
    for(int i = 0; i < n; i++)
        cin >> diffs[i];

    int current = 1500;
    int highest = 1500;

    for(int i = 0; i < n; i++) {
        current += diffs[i];
        highest = max(highest, current);
    }

    cout << highest << " " << current << "\n";

    return 0;
}