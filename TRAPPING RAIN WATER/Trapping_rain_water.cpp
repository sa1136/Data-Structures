#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;                      // Left pointer
        int r = (int)height.size() - 1; // Right pointer
        int leftMax = 0;                // Highest bar seen so far from the left
        int rightMax = 0;               // Highest bar seen so far from the right
        int water = 0;                  // Total trapped water

        while (l < r) {
            if (height[l] < height[r]) {
                if (height[l] >= leftMax)
                    leftMax = height[l];
                else
                    water += leftMax - height[l];
                l++;
            } else {
                if (height[r] >= rightMax)
                    rightMax = height[r];
                else
                    water += rightMax - height[r];
                r--;
            }
        }
        return water;
    }
};

static void runCase(const vector<int>& heights) {
    vector<int> h = heights;
    Solution s;
    cout << "Input: [";
    for (size_t i = 0; i < h.size(); ++i) {
        cout << h[i];
        if (i + 1 < h.size()) cout << ",";
    }
    cout << "]\n";
    cout << "Output: " << s.trap(h) << "\n\n";
}

int main() {
    cout << "Test Case 1:\n";
    runCase({0,1,0,2,1,0,1,3,2,1,2,1}); // expected 6

    cout << "Test Case 2:\n";
    runCase({4,2,0,3,2,5}); // expected 9

    cout << "Test Case 3:\n";
    runCase({2,0,2}); // expected 2

    cout << "Test Case 4:\n";
    runCase({3,0,1,3,0,5}); // expected 8

    cout << "Test Case 5:\n";
    runCase({}); // expected 0

    cout << "Additional Tests:\n";
    runCase({1});
    runCase({1,2,3});
    runCase({5,4,1,2});

    return 0;
}
