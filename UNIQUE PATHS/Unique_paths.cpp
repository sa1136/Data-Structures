#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    Solution solution;
    
    // Test Case 1: Basic example
    cout << "Test Case 1:" << endl;
    int result1 = solution.uniquePaths(3, 7);
    cout << "Input: m = 3, n = 7" << endl;
    cout << "Output: " << result1 << endl;
    cout << "Explanation: There are 28 unique paths" << endl << endl;
    
    // Test Case 2: Square grid
    cout << "Test Case 2:" << endl;
    int result2 = solution.uniquePaths(3, 3);
    cout << "Input: m = 3, n = 3" << endl;
    cout << "Output: " << result2 << endl;
    cout << "Explanation: There are 6 unique paths" << endl << endl;
    
    // Test Case 3: Single row
    cout << "Test Case 3:" << endl;
    int result3 = solution.uniquePaths(1, 10);
    cout << "Input: m = 1, n = 10" << endl;
    cout << "Output: " << result3 << endl;
    cout << "Explanation: Only one path (single row)" << endl << endl;
    
    // Test Case 4: Single column
    cout << "Test Case 4:" << endl;
    int result4 = solution.uniquePaths(10, 1);
    cout << "Input: m = 10, n = 1" << endl;
    cout << "Output: " << result4 << endl;
    cout << "Explanation: Only one path (single column)" << endl << endl;
    
    // Test Case 5: 2x2 grid
    cout << "Test Case 5:" << endl;
    int result5 = solution.uniquePaths(2, 2);
    cout << "Input: m = 2, n = 2" << endl;
    cout << "Output: " << result5 << endl;
    cout << "Explanation: There are 2 unique paths" << endl << endl;
    
    // Test Case 6: Larger grid
    cout << "Test Case 6:" << endl;
    int result6 = solution.uniquePaths(7, 3);
    cout << "Input: m = 7, n = 3" << endl;
    cout << "Output: " << result6 << endl;
    cout << "Explanation: There are 28 unique paths" << endl << endl;
    
    // Additional test cases
    cout << "Additional Test Cases:" << endl;
    vector<pair<int, int>> testCases = {
        {5, 5},
        {4, 4},
        {10, 10}
    };
    vector<int> expected = {70, 20, 48620};
    
    for (int i = 0; i < testCases.size(); i++) {
        int result = solution.uniquePaths(testCases[i].first, testCases[i].second);
        cout << "Test " << (i + 7) << ": m = " << testCases[i].first << ", n = " << testCases[i].second 
             << " -> " << result << " (expected: " << expected[i] << ")" << endl;
    }
    
    return 0;
}

