// Author - sahilmadaan048

// https://cses.fi/problemset/task/1144

#include <bits/stdc++.h>
using namespace std;

// Fenwick Tree
struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int i, int delta) {
        while (i <= n) {
            bit[i] += delta;
            i += i & -i;
        }
    }

    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= i & -i;
        }
        return sum;
    }

    int rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> salary(n);
    vector<int> values;   // for compression

    for (int i = 0; i < n; i++) {
        cin >> salary[i];
        values.push_back(salary[i]);
    }

    vector<tuple<char,int,int>> queries;

    for (int i = 0; i < q; i++) {
        char type;
        cin >> type;

        if (type == '!') {
            int k, x;
            cin >> k >> x;
            k--; // convert to 0-based index
            queries.push_back({type, k, x});
            values.push_back(x);
        } else {
            int a, b;
            cin >> a >> b;
            queries.push_back({type, a, b});
            values.push_back(a);
            values.push_back(b);
        }
    }

    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());

    auto getIndex = [&](int x) {
        return lower_bound(values.begin(), values.end(), x) - values.begin() + 1;
    };

    Fenwick fenwick(values.size());

    for (int i = 0; i < n; i++) {
        fenwick.update(getIndex(salary[i]), 1);
    }

    for (auto [type, a, b] : queries) {

        if (type == '!') {
            int index = a;
            int newSalary = b;

            fenwick.update(getIndex(salary[index]), -1);

            salary[index] = newSalary;

            fenwick.update(getIndex(newSalary), 1);
        }
        else {
            int left = lower_bound(values.begin(), values.end(), a) - values.begin() + 1;
            int right = upper_bound(values.begin(), values.end(), b) - values.begin();

            if (left > right)
                cout << 0 << "\n";
            else
                cout << fenwick.rangeQuery(left, right) << "\n";
        }
    }
}