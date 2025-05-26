// https://cses.fi/problemset/task/1743


#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> freq(26, 0);
    for (char c : s) freq[c - 'A']++;

    int max_freq = *max_element(freq.begin(), freq.end());
    if (max_freq > (n + 1) / 2) {
        cout << "-1\n";
        return 0;
    }

    // Priority queue for lex smallest - use min heap (char comparison)
    priority_queue<pair<char, int>, vector<pair<char, int>>, greater<>> pq;
    for (int i = 0; i < 26; i++) {
        if (freq[i])
            pq.push({(char)('A' + i), freq[i]});
    }

    string ans = "";
    pair<char, int> prev = {'#', 0};

    while (!pq.empty()) {
        auto [ch, count] = pq.top(); pq.pop();

        // Place current character
        ans += ch;
        count--;

        // Reinsert previous character if it still has count left
        if (prev.second > 0)
            pq.push(prev);

        // Update previous to current if more count left
        prev = {ch, count};
    }

    cout << ans << "\n";
    return 0;
}
