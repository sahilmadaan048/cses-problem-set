#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
vector<string> result;
string colors = "ABCD";

bool isValid(int i, int j, char c) {
    if (i > 0 && result[i - 1][j] == c) return false;
    if (j > 0 && result[i][j - 1] == c) return false;
    return true;
}

bool solve() {
    result = grid;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool placed = false;
            for (char c : colors) {
                if (c != grid[i][j] && isValid(i, j, c)) {
                    result[i][j] = c;
                    placed = true;
                    break;
                }
            }
            if (!placed) return false; // no valid char could be placed
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    if (solve()) {
        for (int i = 0; i < n; i++) {
            cout << result[i] << "\n";
        }
    } else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}
