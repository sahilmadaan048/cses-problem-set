

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n;
    cin >> m;

    vector<vector<int>> a(n, vector<int>(m));
    unordered_map<int, pair<int,int>> pos;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            pos[a[i][j]] = {i, j};
        }
    }

    int k;
    cin >> k;

    vector<int> ord(k);
    for(int i = 0; i < k; i++) {
        cin >> ord[i];
    }

    vector<int> row(n, 0), col(m, 0);

    for(int i = 0; i < k; i++) {
        int v = ord[i];
        int r = pos[v].first;
        int c = pos[v].second;

        row[r]++;
        col[c]++;

        if(row[r] == m || col[c] == n) {
            cout << v;
            return 0;
        }
    }

    return 0;
}