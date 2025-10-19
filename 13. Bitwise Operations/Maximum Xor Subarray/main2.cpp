#include <bits/stdc++.h>
using namespace std;
#define int long long

struct TrieNode {
    TrieNode* child[2];
    TrieNode() {
        child[0] = child[1] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 63; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->child[bit])
                node->child[bit] = new TrieNode();
            node = node->child[bit];
        }
    }

    int getMaxXor(int num) {
        TrieNode* node = root;
        int ans = 0;
        for (int i = 63; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->child[1 - bit]) {
                ans |= (1LL << i);
                node = node->child[1 - bit];
            } else {
                node = node->child[bit];
            }
        }
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    Trie trie;
    trie.insert(0); // for subarrays starting at index 0

    int pref = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        pref ^= a[i];
        ans = max(ans, trie.getMaxXor(pref));
        trie.insert(pref);
    }
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
