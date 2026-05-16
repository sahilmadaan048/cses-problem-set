#include <bits/stdc++.h>
using namespace std;

vector<string> topBundle(vector<string> orders) {
    unordered_map<string, int> freq;

    for (auto &order : orders) {
        stringstream ss(order);
        string sku;
        set<string> uniqueSKUs;

        while (ss >> sku) {
            uniqueSKUs.insert(sku);
        }

        vector<string> items(uniqueSKUs.begin(), uniqueSKUs.end());
        int m = items.size();

        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                string key = items[i] + "#" + items[j];
                freq[key]++;
            }
        }
    }

    int maxFreq = 0;
    string bestPair = "";

    for (auto &it : freq) {
        if (it.second > maxFreq) {
            maxFreq = it.second;
            bestPair = it.first;
        } else if (it.second == maxFreq) {
            if (bestPair == "" || it.first < bestPair) {
                bestPair = it.first;
            }
        }
    }

    vector<string> result;
    int pos = bestPair.find('#');
    result.push_back(bestPair.substr(0, pos));
    result.push_back(bestPair.substr(pos + 1));

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cin.ignore(); // to consume newline

    vector<string> orders(n);
    for (int i = 0; i < n; i++) {
        getline(cin, orders[i]);
    }

    vector<string> ans = topBundle(orders);

    for (auto &s : ans) {
        cout << s << "\n";
    }

    return 0;
}

