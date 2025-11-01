#include <iostream>
#include <vector>
using namespace std;

// Mock implementation for testing
// In actual LeetCode problem, this is provided by the API
int badVersion = 0;
bool isBadVersion(int version) {
    return version >= badVersion;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (isBadVersion(mid)) {
                high = mid; // look to the left
            } else {
                low = mid + 1; // look to the right
            }
        }
        return low;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1: Basic example
    cout << "Test Case 1:" << endl;
    badVersion = 4;
    int n1 = 5;
    int result1 = solution.firstBadVersion(n1);
    cout << "Input: n = " << n1 << ", badVersion = " << badVersion << endl;
    cout << "Output: " << result1 << endl;
    cout << "Explanation: First bad version is " << result1 << endl << endl;
    
    // Test Case 2: First version is bad
    cout << "Test Case 2:" << endl;
    badVersion = 1;
    int n2 = 1;
    int result2 = solution.firstBadVersion(n2);
    cout << "Input: n = " << n2 << ", badVersion = " << badVersion << endl;
    cout << "Output: " << result2 << endl;
    cout << "Explanation: First version is bad" << endl << endl;
    
    // Test Case 3: Last version is bad
    cout << "Test Case 3:" << endl;
    badVersion = 10;
    int n3 = 10;
    int result3 = solution.firstBadVersion(n3);
    cout << "Input: n = " << n3 << ", badVersion = " << badVersion << endl;
    cout << "Output: " << result3 << endl;
    cout << "Explanation: Last version is the first bad version" << endl << endl;
    
    // Test Case 4: Middle version is bad
    cout << "Test Case 4:" << endl;
    badVersion = 7;
    int n4 = 10;
    int result4 = solution.firstBadVersion(n4);
    cout << "Input: n = " << n4 << ", badVersion = " << badVersion << endl;
    cout << "Output: " << result4 << endl;
    cout << "Explanation: Middle version is first bad" << endl << endl;
    
    // Test Case 5: Large number
    cout << "Test Case 5:" << endl;
    badVersion = 1702766719;
    int n5 = 2126753390;
    int result5 = solution.firstBadVersion(n5);
    cout << "Input: n = " << n5 << ", badVersion = " << badVersion << endl;
    cout << "Output: " << result5 << endl;
    cout << "Explanation: Handles large numbers correctly" << endl << endl;
    
    // Test Case 6: Early bad version
    cout << "Test Case 6:" << endl;
    badVersion = 2;
    int n6 = 100;
    int result6 = solution.firstBadVersion(n6);
    cout << "Input: n = " << n6 << ", badVersion = " << badVersion << endl;
    cout << "Output: " << result6 << endl;
    cout << "Explanation: Bad version near the beginning" << endl << endl;
    
    // Additional test cases
    cout << "Additional Test Cases:" << endl;
    vector<int> testN = {3, 5, 2};
    vector<int> testBad = {2, 4, 2};
    vector<int> expected = {2, 4, 2};
    
    for (int i = 0; i < testN.size(); i++) {
        badVersion = testBad[i];
        int result = solution.firstBadVersion(testN[i]);
        cout << "Test " << (i + 7) << ": n = " << testN[i] << ", badVersion = " << testBad[i] 
             << " -> " << result << " (expected: " << expected[i] << ")" << endl;
    }
    
    return 0;
}

