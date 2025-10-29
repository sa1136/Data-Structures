#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for (int num : s) {
            // only start if previous number not in set
            if (s.find(num - 1) == s.end()) {
                int current = num;
                int length = 1;

                while (s.find(current + 1) != s.end()) {
                    current++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1: Basic example
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {100,4,200,1,3,2};
    int result1 = solution.longestConsecutive(nums1);
    cout << "Input: [100,4,200,1,3,2]" << endl;
    cout << "Output: " << result1 << endl;
    cout << "Explanation: The longest consecutive sequence is [1, 2, 3, 4] with length 4" << endl << endl;
    
    // Test Case 2: With duplicates
    cout << "Test Case 2:" << endl;
    vector<int> nums2 = {0,3,7,2,5,8,4,6,0,1};
    int result2 = solution.longestConsecutive(nums2);
    cout << "Input: [0,3,7,2,5,8,4,6,0,1]" << endl;
    cout << "Output: " << result2 << endl;
    cout << "Explanation: The longest consecutive sequence is [0, 1, 2, 3, 4, 5, 6, 7, 8] with length 9" << endl << endl;
    
    // Test Case 3: Empty array
    cout << "Test Case 3:" << endl;
    vector<int> nums3 = {};
    int result3 = solution.longestConsecutive(nums3);
    cout << "Input: []" << endl;
    cout << "Output: " << result3 << endl;
    cout << "Explanation: Empty array, so 0" << endl << endl;
    
    // Test Case 4: Single element
    cout << "Test Case 4:" << endl;
    vector<int> nums4 = {5};
    int result4 = solution.longestConsecutive(nums4);
    cout << "Input: [5]" << endl;
    cout << "Output: " << result4 << endl;
    cout << "Explanation: Single element, so length is 1" << endl << endl;
    
    // Test Case 5: No consecutive sequence
    cout << "Test Case 5:" << endl;
    vector<int> nums5 = {1,3,5,7,9};
    int result5 = solution.longestConsecutive(nums5);
    cout << "Input: [1,3,5,7,9]" << endl;
    cout << "Output: " << result5 << endl;
    cout << "Explanation: No consecutive numbers, so length is 1" << endl << endl;
    
    // Test Case 6: Negative numbers
    cout << "Test Case 6:" << endl;
    vector<int> nums6 = {-1,0,1,2};
    int result6 = solution.longestConsecutive(nums6);
    cout << "Input: [-1,0,1,2]" << endl;
    cout << "Output: " << result6 << endl;
    cout << "Explanation: The longest consecutive sequence is [-1, 0, 1, 2] with length 4" << endl << endl;
    
    // Test Case 7: Mixed positive and negative
    cout << "Test Case 7:" << endl;
    vector<int> nums7 = {4,0,-4,-2,1,-3,-1,2};
    int result7 = solution.longestConsecutive(nums7);
    cout << "Input: [4,0,-4,-2,1,-3,-1,2]" << endl;
    cout << "Output: " << result7 << endl;
    cout << "Explanation: The longest consecutive sequence is [-4, -3, -2, -1, 0, 1, 2] with length 7" << endl << endl;
    
    // Additional test cases
    cout << "Additional Test Cases:" << endl;
    vector<vector<int>> testCases = {
        {1,2,3,4,5},
        {10,20,30},
        {1,2,0,1}
    };
    vector<int> expected = {5, 1, 3};
    
    for (int i = 0; i < testCases.size(); i++) {
        int result = solution.longestConsecutive(testCases[i]);
        cout << "Test " << (i + 8) << ": " << result << " (expected: " << expected[i] << ")" << endl;
    }
    
    return 0;
}

