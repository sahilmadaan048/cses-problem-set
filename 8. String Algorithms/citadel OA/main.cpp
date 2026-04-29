
#include <bits/stdc++.h>
using namespace std;

int getOptimalTeamSize(vector<int> lowerSkill, vector<int> higherSkill) {
    int n = lowerSkill.size();
    
    auto canForm = [&](int k) {

        vector<int> candidates;
        candidates.reserve(n);

        for (int i = 0; i < n; i++) {
            if (i + 1 + higherSkill[i] >= k) {
                candidates.push_back(i);
            }
        }


        if ((int)candidates.size() < k) return false;


        sort(candidates.begin(), candidates.end());

        for (int j = 0; j < k; j++) {
            int idx = candidates[j];
            if (lowerSkill[idx] < j) return false;
        }
        return true;
    };
    
    int lo = 0, hi = n, best = 0;
    while (lo <= hi) {
        int mid = lo + (hi - lo)/2;
        if (canForm(mid)) {
            best = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) {
        return 0;
    }
    vector<int> lowerSkill(n), higherSkill(n);
    for (int i = 0; i < n; i++) {
        cin >> lowerSkill[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> higherSkill[i];
    }
    
    int result = getOptimalTeamSize(lowerSkill, higherSkill);
    cout << result << "\n";
    return 0;
}




#include <bits/stdc++.h>
using namespace std;

int getOptimalTeamSize(vector<int> lowerSkill, vector<int> higherSkill) {
    int n = lowerSkill.size();

    vector<pair<int,int>> devs(n);
    for (int i = 0; i < n; i++) {
        devs[i] = {lowerSkill[i], higherSkill[i]};
    }
    
    auto canForm = [&](int k) -> bool {
        for (int l = 0; l + k - 1 < n; l++) {
            bool valid = true;
            for (int j = 0; j < k; j++) {
                int idx = l + j;
                if ((k - 1 - j)> devs[idx].second) {
                    valid = false;
                }
            }
            if (valid) return true;
        }
        return false;
    };
    
    int lo = 0, hi = n, ans = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (canForm(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}


int main() {
    struct TestCase {
        vector<int> lowerSkill;
        vector<int> higherSkill;
        int expected;
    };

    vector<TestCase> tests = {
        // Sample Case 0 (from problem images)
        {{0, 4, 2, 3, 3}, {0, 1, 3, 2, 4}, 3},
        
        // Problem statement example: n=5, lowerSkill=[1,3,2,2,2], higherSkill=[2,2,1,1,3]
        {{3, 4, 2, 1, 2, 5}, {1, 3, 4, 5, 3, 5}, 4},
        

        {{1, 3, 2, 2, 2}, {2, 2, 1, 1, 3}, 3},
        
        // Edge: single developer, always OK
        {{0}, {0}, 1},
        
        // Edge: all reject everyone (0,0 means must be alone)
        {{0, 0, 0}, {0, 0, 0}, 1},
        
        // All very permissive
        {{4, 4, 4, 4, 4}, {4, 4, 4, 4, 4}, 5},
        
        // Two developers, both OK with each other
        {{1, 1}, {1, 1}, 2},
    };

    int passed = 0;
    for (int i = 0; i < (int)tests.size(); i++) {
        int result = getOptimalTeamSize(tests[i].lowerSkill, tests[i].higherSkill);
        bool ok = (result == tests[i].expected);
        cout << "Test " << i << ": "
             << (ok ? "PASS" : "FAIL")
             << "  got=" << result
             << "  expected=" << tests[i].expected
             << "\n";
        if (ok) passed++;
    }
    cout << "\n" << passed << "/" << tests.size() << " tests passed.\n";
    return 0;
}