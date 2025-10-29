#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;          // stores indices of useful elements
        vector<int> result;     // stores the maximums for each window

        for (int i = 0; i < (int)nums.size(); ++i) {
            // Step 1: Remove elements smaller than the current from the back
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            // Step 2: Add current element's index
            dq.push_back(i);

            // Step 3: Remove elements outside the current window (out of range)
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // Step 4: Record the max once we have a complete window
            if (i >= k - 1)
                result.push_back(nums[dq.front()]);
        }

        return result;
    }
};

static void printVec(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i + 1 < v.size()) cout << ",";
    }
    cout << "]\n";
}

int main() {
    Solution sol;

    // Test 1
    cout << "Test 1:\n";
    vector<int> a1 = {1,3,-1,-3,5,3,6,7}; int k1 = 3;
    auto r1 = sol.maxSlidingWindow(a1, k1); printVec(r1); cout << endl; // [3,3,5,5,6,7]

    // Test 2
    cout << "Test 2:\n";
    vector<int> a2 = {1}; int k2 = 1;
    auto r2 = sol.maxSlidingWindow(a2, k2); printVec(r2); cout << endl; // [1]

    // Test 3
    cout << "Test 3:\n";
    vector<int> a3 = {9,11}; int k3 = 2;
    auto r3 = sol.maxSlidingWindow(a3, k3); printVec(r3); cout << endl; // [11]

    // Test 4
    cout << "Test 4:\n";
    vector<int> a4 = {4,-2}; int k4 = 2;
    auto r4 = sol.maxSlidingWindow(a4, k4); printVec(r4); cout << endl; // [4]

    // Test 5
    cout << "Test 5:\n";
    vector<int> a5 = {7,2,4}; int k5 = 2;
    auto r5 = sol.maxSlidingWindow(a5, k5); printVec(r5); cout << endl; // [7,4]

    return 0;
}
