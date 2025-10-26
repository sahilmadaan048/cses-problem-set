#include <bits/stdc++.h>
using namespace std;

int main()
{
    string t = "ababcababcac", p = "ababc";
    int n = t.size(), m = p.size();
    vector<int> lps(m);
    for (int i = 1, j = 0; i < m; i++)
    {
        while (j > 0 && p[i] != p[j])
            j = lps[j - 1];
        if (p[i] == p[j])
            lps[i] = ++j;
    }

    for (int i = 0, j = 0; i < n; i++)
    {
        while (j > 0 && t[i] != p[j])
            j = lps[j - 1];
        if (t[i] == p[j])
            j++;
        if (j == m)
            cout << i - m + 1 << " ", j = lps[j - 1];
    }
}
