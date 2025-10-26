#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     long long minOperations(vector<int> &nums1, vector<int> &nums2)
//     {
//         vector<int> travenior = nums1;
//         int n = travenior.size();
//         long long s = 0;
//         for (int i = 0; i < n; ++i)
//             s += abs((long long)travenior[i] - nums2[i]);
//         long long best = LLONG_MAX;
//         for (int i = 0; i < n; ++i)
//         {
//             long long a = abs((long long)travenior[i] - nums2[n]);
//             long long b = abs((long long)nums2[i] - nums2[n]);
//             long long c = abs((long long)travenior[i] - nums2[i]);
//             long long extra = a + b - c;
//             if (extra < 0)
//                 extra = 0;
//             if (extra < best)
//                 best = extra;
//         }
//         return s + best + 1;
//     }
// };
class Solution
{
public:
    long long minOperations(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        long long sumDiff = 0;
        for (int i = 0; i < n; ++i)
        {
            long long diff = (long long)nums1[i] - (long long)nums2[i];
            sumDiff += (diff < 0 ? -diff : diff);
        }
        long long last = nums2[n];
        long long minExtra = LLONG_MAX;
        for (int i = 0; i < n; ++i)
        {
            long long v = nums1[i];
            long long p = nums2[i];
            if (last >= min(v, p) && last <= std::max(v, p))
            {
                minExtra = 0;
                break;
            }
            else
            {
                long long d1 = v - last;
                long long d2 = p - last;
                long long cost1 = (d1 < 0 ? -d1 : d1);
                long long cost2 = (d2 < 0 ? -d2 : d2);
                minExtra = std::min(minExtra, std::min(cost1, cost2));
            }
        }
        return sumDiff + minExtra + 1;
    }
};

int main()
{
    Solution sol;

    vector<int> nums1_1 = {2, 8};
    vector<int> nums2_1 = {1, 7, 3};
    cout << "Example 1 Output: " << sol.minOperations(nums1_1, nums2_1) << endl;

    vector<int> nums1_2 = {1, 3, 6};
    vector<int> nums2_2 = {2, 4, 5, 3};
    cout << "Example 2 Output: " << sol.minOperations(nums1_2, nums2_2) << endl;

    vector<int> nums1_3 = {2};
    vector<int> nums2_3 = {3, 4};
    cout << "Example 3 Output: " << sol.minOperations(nums1_3, nums2_3) << endl;

    vector<int> nums1_4 = {753, 357};
    vector<int> nums2_4 = {271, 520, 413};
    cout << "Example 4 Output: " << sol.minOperations(nums1_4, nums2_4) << endl;

    return 0;
}
