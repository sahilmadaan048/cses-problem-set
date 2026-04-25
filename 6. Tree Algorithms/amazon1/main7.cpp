#include <bits/stdc++.h>
using namespace std;

vector<string> topBundle(vector<string> orders) {
    map<pair<string,string>, int> pairCount;

    for (const string& order : orders) {
        istringstream iss(order);
        string sku;
        set<string> skus;

        while (iss >> sku) skus.insert(sku);

        vector<string> skuVec(skus.begin(), skus.end());
        for (int i = 0; i < (int)skuVec.size(); i++) {
            for (int j = i + 1; j < (int)skuVec.size(); j++) {
                pairCount[{skuVec[i], skuVec[j]}]++;
            }
        }
    }

    pair<string,string> best;
    int maxCount = 0;

    for (const auto& [pr, cnt] : pairCount) {
        if (cnt > maxCount ||
           (cnt == maxCount && pr < best)) {
            maxCount = cnt;
            best = pr;
        }
    }

    return {best.first, best.second};
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



