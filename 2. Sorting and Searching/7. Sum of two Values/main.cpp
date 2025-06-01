// https://cses.fi/problemset/task/1640

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, target;
    cin >> n >> target;
    vector<pair<int, int>> temp(n); // Store value and original index

    // Read input and store value-index pairs
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        temp[i] = {x, i + 1}; // Store value and 1-based index
    }

    // Sort the array by value
    sort(temp.begin(), temp.end());

    int i = 0, j = n - 1;

    // Use two-pointer technique to find the pair
    while (i < j)
    {
        int sum = temp[i].first + temp[j].first;
        if (sum == target)
        {
            cout << temp[i].second << " " << temp[j].second << endl;
            return 0; // Exit after finding the pair
        }
        else if (sum < target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
