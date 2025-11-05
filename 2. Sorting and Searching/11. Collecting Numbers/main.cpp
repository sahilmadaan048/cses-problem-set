// https://cses.fi/problemset/task/2183

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<int>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

void solve()
{
    int n;
    cin >> n;
    vector<int> array(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> array[i];
    }

    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[array[i]] = i;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (mp[i] > mp[i + 1])
        {
            count++;
        }
    }
    return;
}

int main()
{
    fast;
    solve();
    return 0;
}