#include <bits/stdc++.h>
using namespace std;

vector<int> sortBugReportFrequencies(vector<int> bugs) {
    unordered_map<int, int> freq;

    // Count frequency
    for (int x : bugs) {
        freq[x]++;
    }

    // Custom sort
    sort(bugs.begin(), bugs.end(), [&](int a, int b) {
        if (freq[a] != freq[b])
            return freq[a] < freq[b];   // lower freq first
        return a < b;                   // smaller value first
    });

    return bugs;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> bugs(n);
    for (int i = 0; i < n; i++) {
        cin >> bugs[i];
    }

    vector<int> result = sortBugReportFrequencies(bugs);

    for (int x : result) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}