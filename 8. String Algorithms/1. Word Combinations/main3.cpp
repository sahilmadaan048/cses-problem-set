#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;

struct TrieNode {
    bool isEnd = false;
    unordered_map<char, TrieNode*> child;
};

void insert(TrieNode* root, const string &word) {
    TrieNode* node = root;
    for (char c : word) {
        if (!node->child[c]) node->child[c] = new TrieNode();
        node = node->child[c];
    }
    node->isEnd = true;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    int k;
    cin >> k;
    vector<string> words(k);
    for (int i = 0; i < k; i++) cin >> words[i];

    // Build Trie for all words
    TrieNode* root = new TrieNode();
    for (auto &w : words) insert(root, w);

    vector<int> dp(n + 1, 0);
    dp[0] = 1; // empty prefix has one way

    // DP over the string
    for (int i = 0; i < n; i++) {
        if (!dp[i]) continue;
        TrieNode* node = root;
        for (int j = i; j < n; j++) {
            if (!node->child.count(s[j])) break;
            node = node->child[s[j]];
            if (node->isEnd) {
                dp[j + 1] = (dp[j + 1] + dp[i]) % MOD;
            }
        }
    }

    cout << dp[n] % MOD << "\n";
}
