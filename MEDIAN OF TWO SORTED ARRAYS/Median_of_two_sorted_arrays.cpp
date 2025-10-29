#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n1 = (int)nums1.size(), n2 = (int)nums2.size();
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int n = n1 + n2;
        int left = (n + 1) / 2;
        int low = 0, high = n1;

        while (low <= high) {
            int mid1 = (low + high) >> 1;
            int mid2 = left - mid1;

            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 < n1) r1 = nums1[mid1];
            if (mid2 < n2) r2 = nums2[mid2];
            if (mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

            if (l1 <= r2 && l2 <= r1) {
                if (n % 2 == 1) return (double)max(l1, l2);
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            } else if (l1 > r2) {
                high = mid1 - 1;
            } else {
                low = mid1 + 1;
            }
        }
        return 0.0;
    }
};

int main() {
    Solution sol;

    vector<int> a1 = {1, 3}, b1 = {2};
    cout << "Test 1: " << sol.findMedianSortedArrays(a1, b1) << "\n"; // 2.0

    vector<int> a2 = {1, 2}, b2 = {3, 4};
    cout << "Test 2: " << sol.findMedianSortedArrays(a2, b2) << "\n"; // 2.5

    vector<int> a3 = {}, b3 = {1};
    cout << "Test 3: " << sol.findMedianSortedArrays(a3, b3) << "\n"; // 1.0

    vector<int> a4 = {0, 0}, b4 = {0, 0};
    cout << "Test 4: " << sol.findMedianSortedArrays(a4, b4) << "\n"; // 0.0

    vector<int> a5 = {3}, b5 = {-2, -1};
    cout << "Test 5: " << sol.findMedianSortedArrays(a5, b5) << "\n"; // -1.0

    vector<int> a6 = {1, 3, 8, 9, 15}, b6 = {7, 11, 18, 19, 21, 25};
    cout << "Test 6: " << sol.findMedianSortedArrays(a6, b6) << "\n"; // 11.0

    return 0;
}
