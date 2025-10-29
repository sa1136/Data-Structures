#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        for (auto& interval : intervals) {
            // Case 1: current interval ends before newInterval starts
            if (interval[1] < newInterval[0]) {
                res.push_back(interval);
            }
            // Case 2: current interval starts after newInterval ends
            else if (interval[0] > newInterval[1]) {
                res.push_back(newInterval);
                newInterval = interval;  // shift window
            }
            // Case 3: overlap -> merge intervals
            else {
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
            }
        }

        res.push_back(newInterval);
        return res;
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

    // Test 1: Basic insert merge in middle
    cout << "Test 1:\n";
    vector<vector<int>> a1 = {{1,3},{6,9}}; vector<int> n1 = {2,5};
    auto r1 = sol.insert(a1, n1); printIntervals(r1); cout << endl;

    // Test 2: Insert merging multiple
    cout << "Test 2:\n";
    vector<vector<int>> a2 = {{1,2},{3,5},{6,7},{8,10},{12,16}}; vector<int> n2 = {4,8};
    auto r2 = sol.insert(a2, n2); printIntervals(r2); cout << endl;

    // Test 3: Insert before all
    cout << "Test 3:\n";
    vector<vector<int>> a3 = {{3,5},{7,9}}; vector<int> n3 = {0,1};
    auto r3 = sol.insert(a3, n3); printIntervals(r3); cout << endl;

    // Test 4: Insert after all
    cout << "Test 4:\n";
    vector<vector<int>> a4 = {{1,2},{3,4}}; vector<int> n4 = {5,6};
    auto r4 = sol.insert(a4, n4); printIntervals(r4); cout << endl;

    // Test 5: Insert into empty
    cout << "Test 5:\n";
    vector<vector<int>> a5; vector<int> n5 = {2,3};
    auto r5 = sol.insert(a5, n5); printIntervals(r5); cout << endl;

    // Test 6: Exact adjacency (touching)
    cout << "Test 6:\n";
    vector<vector<int>> a6 = {{1,2},{5,7}}; vector<int> n6 = {2,5};
    auto r6 = sol.insert(a6, n6); printIntervals(r6); cout << endl;

    return 0;
}
