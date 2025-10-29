#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (const auto& interval : intervals) {
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
    }
};

static void printIntervals(const vector<vector<int>>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << "[" << v[i][0] << "," << v[i][1] << "]";
        if (i + 1 < v.size()) cout << ",";
    }
    cout << "]\n";
}

int main() {
    Solution sol;

    // Test 1
    cout << "Test 1:" << endl;
    vector<vector<int>> a1 = {{1,3},{2,6},{8,10},{15,18}};
    auto r1 = sol.merge(a1);
    cout << "Input: [[1,3],[2,6],[8,10],[15,18]]\nOutput: "; printIntervals(r1); cout << endl;

    // Test 2
    cout << "Test 2:" << endl;
    vector<vector<int>> a2 = {{1,4},{4,5}};
    auto r2 = sol.merge(a2);
    cout << "Input: [[1,4],[4,5]]\nOutput: "; printIntervals(r2); cout << endl;

    // Test 3
    cout << "Test 3:" << endl;
    vector<vector<int>> a3 = {{1,4},{0,2},{3,5}};
    auto r3 = sol.merge(a3);
    cout << "Input: [[1,4],[0,2],[3,5]]\nOutput: "; printIntervals(r3); cout << endl;

    // Test 4: no overlap
    cout << "Test 4:" << endl;
    vector<vector<int>> a4 = {{1,2},{3,4},{5,6}};
    auto r4 = sol.merge(a4);
    cout << "Input: [[1,2],[3,4],[5,6]]\nOutput: "; printIntervals(r4); cout << endl;

    // Test 5: single interval
    cout << "Test 5:" << endl;
    vector<vector<int>> a5 = {{1,10}};
    auto r5 = sol.merge(a5);
    cout << "Input: [[1,10]]\nOutput: "; printIntervals(r5); cout << endl;

    // Additional tests
    cout << "Additional Tests:" << endl;
    vector<vector<int>> a6 = {{1,4},{2,3}}; // fully contained
    auto r6 = sol.merge(a6);
    cout << "Input: [[1,4],[2,3]]\nOutput: "; printIntervals(r6);

    return 0;
}
