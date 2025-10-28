#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        map<int, int> painted;  // stores non-overlapping intervals
        vector<int> res;

        for (auto& p : paint) {
            int l = p[0], r = p[1];
            int newPaint = r - l;

            // Find first interval that might overlap
            auto it = painted.lower_bound(l);

            // Check possible overlap with previous interval
            if (it != painted.begin()) {
                auto prev = it; --prev;
                if (prev->second >= l) {
                    // Overlap with previous
                    l = min(l, prev->first);
                    newPaint -= max(0, prev->second - p[0]);
                    r = max(r, prev->second);
                    it = painted.erase(prev);
                }
            }

            // Merge all overlapping intervals
            while (it != painted.end() && it->first <= r) {
                newPaint -= max(0, min(r, it->second) - max(p[0], it->first));
                r = max(r, it->second);
                it = painted.erase(it);
            }

            // Insert merged interval
            painted[l] = r;
            res.push_back(max(0, newPaint));
        }

        return res;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> paint1 = {{1,4},{4,7},{5,8}}; // Expected: [3,3,1]
    vector<int> res1 = sol.amountPainted(paint1);
    cout << "Test 1: ";
    for (int x : res1) cout << x << ' ';
    cout << "\n";

    vector<vector<int>> paint2 = {{1,5},{2,4}}; // Expected: [4,0]
    vector<int> res2 = sol.amountPainted(paint2);
    cout << "Test 2: ";
    for (int x : res2) cout << x << ' ';
    cout << "\n";

    vector<vector<int>> paint3 = {{1,3},{2,5},{7,10},{9,12}}; // Expected: [2,2,3,2]
    vector<int> res3 = sol.amountPainted(paint3);
    cout << "Test 3: ";
    for (int x : res3) cout << x << ' ';
    cout << "\n";

    return 0;
}
