#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i)
        cin >> grid[i];

    // Initialize two rows for DP to save space
    vector<string> prev_row(n), curr_row(n);

    // Fill the first cell
    prev_row[0] = string(1, grid[0][0]);

    // Fill the first row
    for (int j = 1; j < n; ++j)
        prev_row[j] = prev_row[j - 1] + grid[0][j];

    // Process the rest of the grid
    for (int i = 1; i < n; ++i) {
        // Fill the first column of the current row
        curr_row[0] = prev_row[0] + grid[i][0];

        for (int j = 1; j < n; ++j) {
            // Choose the lexicographically smaller path from the top or left cell
            if (prev_row[j] < curr_row[j - 1])
                curr_row[j] = prev_row[j] + grid[i][j];
            else
                curr_row[j] = curr_row[j - 1] + grid[i][j];
        }

        // Move current row to previous row for next iteration
        swap(prev_row, curr_row);
    }

    // Output the lexicographically minimal path
    cout << prev_row[n - 1] << '\n';

    return 0;
}
