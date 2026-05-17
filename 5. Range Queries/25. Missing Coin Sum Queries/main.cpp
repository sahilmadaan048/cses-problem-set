// https://cses.fi/problemset/task/2184
// Author - sahilmadaan048

#include "bits/stdc++.h"
#define int long long
using namespace std;

struct Node {

    int sum;

    Node *left, *right;

    Node(int s = 0,
         Node* l = nullptr,
         Node* r = nullptr) {

        sum = s;

        left = l;
        right = r;
    }
};

Node* update(Node* node,
             int l, int r,
             int idx, int val) {

    if (l == r)
        return new Node(node->sum + val);

    int mid = (l + r) / 2;

    if (idx <= mid) {

        Node* newLeft =
            update(node->left,
                   l, mid,
                   idx, val);

        return new Node(
            newLeft->sum + node->right->sum,
            newLeft,
            node->right
        );
    }

    else {

        Node* newRight =
            update(node->right,
                   mid + 1, r,
                   idx, val);

        return new Node(
            node->left->sum + newRight->sum,
            node->left,
            newRight
        );
    }
}

int query(Node* R, Node* L,
          int l, int r,
          int ql, int qr) {

    if (qr < l || r < ql)
        return 0;

    if (ql <= l && r <= qr)
        return R->sum - L->sum;

    int mid = (l + r) / 2;

    return
        query(R->left, L->left,
              l, mid,
              ql, qr)
      + query(R->right, L->right,
              mid + 1, r,
              ql, qr);
}

Node* build(int l, int r) {

    if (l == r)
        return new Node();

    int mid = (l + r) / 2;

    return new Node(
        0,
        build(l, mid),
        build(mid + 1, r)
    );
}

void solve() {

    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);

    vector<int> vals;

    for (int i = 1; i <= n; i++) {

        cin >> a[i];

        vals.push_back(a[i]);
    }

    sort(vals.begin(), vals.end());

    vals.erase(unique(vals.begin(),
                      vals.end()),
               vals.end());

    int m = vals.size();

    vector<Node*> roots(n + 1);

    roots[0] = build(0, m - 1);

    for (int i = 1; i <= n; i++) {

        int idx =
            lower_bound(vals.begin(),
                        vals.end(),
                        a[i])
            - vals.begin();

        roots[i] =
            update(roots[i - 1],
                   0, m - 1,
                   idx,
                   a[i]);
    }

    while (q--) {

        int l, r;
        cin >> l >> r;

        int need = 1;

        while (true) {

            int pos =
                upper_bound(vals.begin(),
                            vals.end(),
                            need)
                - vals.begin() - 1;

            if (pos < 0) {
                cout << need << '\n';
                break;
            }

            int s =
                query(roots[r],
                      roots[l - 1],
                      0, m - 1,
                      0, pos);

            if (s < need) {

                cout << need << '\n';

                break;
            }

            need = s + 1;
        }
    }
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}


/*

   this problem used the classic: 
      SMALLEST MISSING SYM GREEDY

   if we have coins sorted and can already make all sums: 
      [1, x-1]

   then: 
      if next coin c belongs to x;
         we can extend reachable range to: 
            [1, x+c-1]

      otherise x is the answer

      KEY OBSERVATION FOR QUERIES

   for a query [l,  r]:

      suppose current missing sum is need

      then we only care abour:   
         sum of all coins <= need

      inside the range

      if that sum is S:
         if S  < ened
            cannot  rceate need
         else  
            now we can create ypto S+1
         
*/